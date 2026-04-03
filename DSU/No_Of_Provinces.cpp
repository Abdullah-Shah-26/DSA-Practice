#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N^2 * Alpha(N)) - Inverse Ackerman const
//! SC = O(N)

class DSU{
  public:
    int components;
    vector<int> parent, size;
    
    DSU(int n){
      parent.resize(n, 0);
      size.resize(n, 1);
      components = n;
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

      components--;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
    int n = adj.size();
    DSU dsu(n);

    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        if(adj[i][j] == 1){
          dsu.merge(i, j);
        }
      }
    } 
    
    return dsu.components;
    }
};

//! DFS 
//* TC = O(N^2) || SC = O(N)
class Solution {
public:
  int n;
    void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj){
      vis[u] = 1;

      for(int v = 0; v < n; v++){
        if(adj[u][v] == 1 && !vis[v]){
          dfs(v, vis, adj);
        }
      }
    }

    int findCircleNum(vector<vector<int>>& adj) {
    n = adj.size(); // adj matrix
    vector<bool> vis(n, 0);
    int comp = 0;

    for(int i = 0; i < n; i++){
      if(!vis[i]){
        comp++;
        dfs(i, vis, adj);
      }
    }

    return comp;
    }
}; 

//! BFS
//* TC = O(N^2) || SC = O(N)
class Solution {
public:
  int n;
    void bfs(int u, vector<bool> &vis, vector<vector<int>> &adj){
      vis[u] = 1;
      queue<int> q;
      q.push(u);

      while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int v = 0; v < n; v++){
          if(adj[node][v] == 1 && !vis[v]){
            vis[v] = 1;
            q.push(v);
          }
        }
      }
    }

    int findCircleNum(vector<vector<int>>& adj) {
    n = adj.size(); // adj matrix
    vector<bool> vis(n, 0);
    int comp = 0;

    for(int i = 0; i < n; i++){
      if(!vis[i]){
        comp++;
        bfs(i, vis, adj);
      }
    }

    return comp;
    }
};