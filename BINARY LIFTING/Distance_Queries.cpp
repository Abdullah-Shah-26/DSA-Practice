#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

int up[200005][20];
vector<vector<int>> adj;
vector<int>depth;

//! We will use Iterative Version
// void dfs(int node,int p){
    
//     for(auto &child : adj[node]){
//       if(child == p) continue;

//       depth[child] = depth[node] + 1;

        // Fill immediate parent values
//       up[child][0] = node;

//       dfs(child, node);
//     }
// }

void build(int root){
  queue<int>q;
  q.push(root);

  up[root][0] = -1;
  depth[root] = 0;
  
  while(!q.empty()){
    int node = q.front();
    q.pop();

    for(int child : adj[node]){
      if(child == up[node][0]) continue;

      depth[child] = depth[node] + 1;
      up[child][0] = node;

      q.push(child);
    }
  }
}

int KthAncestor(int node, int k){
  for(int bit = 0; bit < 20; bit++){
    if(k & (1 << bit)){
      node = up[node][bit];
      
      if(node == -1) break;
    }
  }

  return node;
}

int lca(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);

  int diff = depth[u] - depth[v];

  u = KthAncestor(u, diff);

  if(u == v){
    return u;
  }

  for(int k = 19; k >= 0; k--){
    if(up[u][k] != up[v][k]){
      u = up[u][k];
      v = up[v][k];
    }
  }

  return up[u][0];
}

void solve(){
  ll n, q;
  cin >> n >> q;

  adj.assign(n + 1, {});
  depth.assign(n + 1, 0);

  memset(up, -1, sizeof(up));

  for(int i = 1; i <= n-1; i++){
    int u, v;
    cin >> u  >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // calculate depth 
  // dfs(1, -1);
  build(1); // O(N) without recursion stack

  for(int k = 1; k < 20; k++){ // n Log N = n Log(2e18) = n * 18
    for(int node = 1; node <= n; node++){
      if(up[node][ k - 1] !=  -1 ){
        up[node][k] = up[ up[node][ k - 1]][k - 1];
      }
    }
  }
  while(q--){ // O(q Log N)
    int u, v; 
    cin >> u >> v;

    int L = lca(u, v);
    int pathLen = depth[u] + depth[v] - 2 * (depth[L]);

    cout << pathLen << "\n";
  }
  return;
} 

int main(){
  fastio();
  solve();
}