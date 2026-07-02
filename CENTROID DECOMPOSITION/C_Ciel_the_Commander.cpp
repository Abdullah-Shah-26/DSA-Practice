#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio=[](){
 ios::sync_with_stdio(false);
 cin.tie(nullptr);
 return 0;
}();

#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{for(const auto &x:(a)) cout<<x<<' '; cout<<'\n';}while(0)
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define pm(mat) do{for(const auto &r:(mat)){for(const auto &x:(r)) cout<<x<<' '; cout<<'\n';}}while(0)
#define pf(x) cout<<x<<'\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define endl '\n'

/*
==========================
Observation / Thinking
--------------------------

Need a center that keep recursion shallow 

The node whose removal splits the tree into balanced pieces.

Centroid - Largest component <= N/2

==========================
*/

const int N = 100005;

vi adj[N];
int sz[N]; // Subtree size of node
bool removed[N]; // Instead of physically removing centroid we mark it 
char ans[N];

int n;

// To compute subtree sizes
void dfs(int u, int p){
  sz[u] = 1;
  
  for(int v : adj[u]){
    if(v == p) continue;
    if(removed[v]) continue;
    
    dfs(v, u);
    sz[u] += sz[v];
  }
}

// Find centroid of current component
int findCentroid(int u, int p, int total){
  for(int v : adj[u]){
    if(v == p) continue;
    if(removed[v]) continue;

    if(sz[v] > total/2) // Our centroid lies in that subtree
      return findCentroid(v, u, total);
  }
  return u;
}

// Centroid decomposition + rank assignment
void decompose(int u, char ch){
  if(ch > 'Z'){
    pf("Impossible");
    return;
  }

  dfs(u, -1); // Finds subtree sz of this comp
  int c = findCentroid(u, -1, sz[u]);

  ans[c] = ch;
  removed[c] = true;

  for(int v : adj[c]){
    if(removed[v]) continue;
    decompose(v, ch + 1);
  }
}

void solve(){
  cin >> n; 

  for(int i = 1; i < n; i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  decompose(1,'A');

  for(int i = 1; i <= n; i++) 
    cout << ans[i] << " ";
  
    cout << endl; 
}

int main(){

  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
