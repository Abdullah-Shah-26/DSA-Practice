#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n, m;
  static const int MOD = 1e9 + 7;
  vector<int> depth;
  vector<vector<int>> up;
  vector<vector<int>> adj;

  void dfs(int u, int p){
    up[u][0] = p; // Immediate parent 
    for(int v : adj[u]){
      if(v == p) continue;
      depth[v] = depth[u] + 1;
      dfs(v, u);
    }
  }

  void build(){
    for(int k = 1; k < m; k++){
      for(int node = 0; node < n; node++){
        if(up[node][k - 1] != -1)
          up[node][k] = up[up[node][k - 1]][k - 1];
      }
    }
  }

  int kthAncestor(int node, int k){
    for(int bit = 0; bit < m; bit++){
      if(k & (1 << bit)){
        node = up[node][bit];
        if(node == -1) break; 
      }
    }
    return node;
  }

  int findLCA(int u, int v){
    if(depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    
    u = kthAncestor(u, diff);
  
    if(u == v) 
      return u;

    for(int k = m - 1; k >= 0; k--){
      if(up[u][k] != up[v][k]){
        u = up[u][k];
        v = up[v][k];
      }
    }

    return up[u][0];
  }

  vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
  n = edges.size() + 1; // Tree has N - nodes, (N - 1) edges 
  m = log2(n) + 1;

  depth.assign(n, 0);
  up.assign(n, vector<int> (m, -1));
  adj.assign(n, {});

  for(auto &e : edges){
    int u = e[0];
    int v = e[1];
    u--, v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, -1);
  build();

  // Precompute pow of 2
  vector<int> pow2(n + 1);
  pow2[0] = 1;
  
  for(int i = 1; i <= n; i++){
    pow2[i] = (pow2[i - 1] * 2LL) % MOD;
  }

  vector<int> ans;
  for(auto &q : queries){
    int u = q[0] - 1;
    int v = q[1] - 1;

    int LCA = findLCA(u, v);
    int d = depth[u] + depth[v] - 2 * depth[LCA];
    
    if(d == 0) ans.push_back(0);
    else ans.push_back(pow2[d - 1]);
  }

  return ans;
  }
};