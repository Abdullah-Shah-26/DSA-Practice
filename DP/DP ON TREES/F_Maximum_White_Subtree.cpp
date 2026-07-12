#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
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

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

// ---------- Macros ----------
#define rv(a) for(auto &x:(a)) cin>>x
#define pv(a) do{ for(const auto &x:(a)) cout<<x<<' '; cout<<'\n'; }while(0)
#define rm(mat) for(auto &r:(mat)) for(auto &x:(r)) cin>>x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define endl '\n'

int n;
vi color;
vi wt;
vi up;
vi ans;
vi down;
vvi adj;

void dfs1(int u, int p){
  down[u] = wt[u];

  for(int v : adj[u]){
    if(v == p) 
      continue;
    
    dfs1(v, u);
    down[u] += max(0, down[v]);
  }
}

void dfs2(int u, int p){
  ans[u] = down[u] + up[u];

  for(int v : adj[u]){
    if(v == p)
      continue;

    // Pass parent contribution to child after removing child's own effect
    up[v] = max(0, up[u] + (down[u] - max(0, down[v])));

    dfs2(v, u);
  }
}

// ---------- Solve ---------
void solve(){
  cin >> n;

  color.resize(n);
  rv(color);

  adj.resize(n);
  up.resize(n);
  down.resize(n);
  wt.resize(n);
  ans.resize(n);

  for(int i = 0; i < n-1; i++){
    int u,v;
    cin >> u >> v;
    u--,v--;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  for(int i = 0; i < n; i++){
    if(color[i]==0)
      wt[i] = -1;
    else 
      wt[i] = 1;
  }

  dfs1(0,-1);
  dfs2(0,-1);

  pv(ans);
}

// ---------- Main ----------
int main(){
    solve();
  return 0;
}