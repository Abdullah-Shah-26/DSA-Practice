#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Binary Lifting - LCA

int up[200005][21];
vi adj[200005];
vi depth(200005, 0);


void dfs(int node, int parent){
  for(auto &child : adj[node]){
      if(child == parent) continue;

      depth[child] = depth[node] + 1;
      dfs(child, node);
    
  }
}

int KthAncestor(int node, int k){
  // Start Jumping from LSB -> MSB
  for(int bit = 0; bit < 21; bit++){
    if(k & (1 << bit)){
      node = up[node][bit];
      if(node == -1){
        break;
      }
    }
  }
  return node;
}

int f(int u, int v){
  // Assuming u is deeper than v else swap
  if(depth[u] < depth[v]){
    swap(u, v);
  }

  int diff = depth[u] - depth[v];
  // Lift the deeper node by this diff to make level same
  u = KthAncestor(u, diff); 

  // If they become same after lifting
  if(u == v){ // Any of u or v is the LCA
    return u;
  }

  for(int k = 20; k >= 0; k--){
    int _2powerKthAncestorU = up[u][k];
    int _2powerKthAncestorV = up[v][k];

    if(_2powerKthAncestorU == _2powerKthAncestorV){
      continue; // LCA must be present below
    }

    // If they are diff
    // LCA must definetily present above
    u = _2powerKthAncestorU;
    v = _2powerKthAncestorV;
  }

  return up[u][0]; // or up[v][0]
  // Cause now U & V are at same levels & Now their immediate paernt is LCA
}

void solve(){
  ll n,q;
  cin >> n >> q;

  memset(up, -1, sizeof(up));
  
  // Fill immediate parents
  for(int i = 2; i <= n; i++){
    cin >> up[i][0];

    // Build Adj List
    adj[i].push_back(up[i][0]);
    adj[up[i][0]].push_back(i);
  }

  // PreCompute Depth of each node in advance
  dfs(1, -1);


  // Fill the up table
  for(int k = 1; k < 21; k++){
    for(int node = 1; node  <= n; node++){
      if(up[node][k-1] != -1){
        up[node][k] = up[ up[node][k-1] ][k - 1];
      }
    }
  }

  // Process queries
  while(q--){
    int u, v;
    cin >> u >> v;

    cout << f(u, v) << "\n";
  }
  return;
}

int main(){
  solve();

  return 0;
}