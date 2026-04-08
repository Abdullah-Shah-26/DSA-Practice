#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Using BFS / DFS
//* TC = O(V + E)  ||  SC = O(V + E)

class Solution {
public:
    int n;
    bool bfs(int src, int dst, vector<vector<int>> &adj, vector<bool> &vis){
      queue<int> q;
      q.push(src);
      vis[src] = 1;

      while(!q.empty()){
        int node = q.front();
        q.pop();

        if(node == dst){
          return true;
        }

        for(auto &nei : adj[node]){
          if(!vis[nei]){
            vis[nei] = 1;
            q.push(nei);
          }
        }
      }
      return false;
    }

    bool dfs(int src, int dst, vector<vector<int>> &adj, vector<bool> &vis){
      vis[src] = 1;

      if(src == dst) return true;

      for(auto &nei : adj[src]){
        if(!vis[nei]){
          if(dfs(nei, dst, adj, vis)){
            return true;
          }
        }
      }

      return false;
    }

    bool validPath(int _n, vector<vector<int>>& edges, int src, int dst) {
    n = _n;
    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> vis(n, 0);

    // return bfs(src, dst, adj, vis); 
    return dfs(src, dst, adj, vis);
    }
};


//!  DSU
//* TC = E(alpha(V)) || SC = O(V)

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return;

        if(size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
    if(src == dst){
      return true;
    }

    DSU dsu(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      dsu.unite(u,v);
      
      if(dsu.find(src) == dsu.find(dst)){
        return true;
      }
    }   

    return false;
    }
};