#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* Undirected Graph Cycle Detection
//* TC = O(E Alpha(V))  ||  SC = O(V)

struct DSU{
    vector<int> parent, size;
    
    DSU(int n){
        parent.resize(n,0);
        size.resize(n,1);
        
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x){
        if(x == parent[x]) return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void merge(int u,int v){
        u = find(u);
        v = find(v);
        
        if(u == v) return;
        
        if(size[u] < size[v]) swap(u,v);
        
        parent[v] = u;
        size[u] += size[v]; 
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();

    DSU dsu(n + 1);  // 1 based nodes
    vector<int> ans;

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      if(dsu.find(u) == dsu.find(v)){
        ans.push_back(u);
        ans.push_back(v);
      }

      dsu.merge(u,v);
    }

    return ans;   
    }
};

//* DFS - src to target checking if path exist
//! TC = O(V * (V + E))  ||  SC = O(V + E)

class Solution {
  public:
    bool dfs(int src, int target, vector<vector<int>> &adj, vector<int> &vis){
      if(src == target) return true;

      vis[src] = 1;

      for(auto &nei : adj[src]){
        if(!vis[nei]){
          if(dfs(nei, target, adj, vis)){
            return true;
          }
        }
      }

      return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<vector<int>> adj(n + 1);
    
    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      vector<int> vis(n + 1, 0);

      // Check before adding edge
      if(!adj[u].empty() && !adj[v].empty()){ // Run dfs if both nodes have atleast one edge
        if(dfs(u, v, adj, vis)){
          return {u,v};
        }
      }

      // add edge
      adj[u].push_back(v);
      adj[v].push_back(u);
    }    

    return {};
    }
};