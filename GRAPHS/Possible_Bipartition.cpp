#include <bits/stdc++.h>
using namespace std;

//! Check if graph is Bipartite
//* DFS

class Solution {
  public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &color){  
      for(auto &nei : adj[node]){
        if(nei == parent) continue;

        if(color[nei] == -1){
          color[nei] = !color[node];
          if(dfs(nei, node, adj, color) == false){
            return false;
          }
        }
        else if(color[nei] == color[node]){
          return false;
        }
      }

      return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& edges) {
    vector<int> adj[n + 1];

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }   

    vector<int> color(n + 1, -1);

    for(int i = 1; i <= n; i++){
      if(color[i] == -1){
        color[i] = 1;
        if(dfs(i, -1, adj, color) == false)
          return false;
      }
    }

    return true;
    }
};

//* BFS

class Solution {
  public:

    bool bfs(int stNode, vector<int> adj[], vector<int> &color){
      
      vector<int> parent(color.size(), -1);
      queue<int> q;
      
      q.push(stNode);
      color[stNode] = 1;

      while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto &nei : adj[node]){
          if(nei == parent[node]) continue;

          if(color[nei] == -1){
            color[nei] = !color[node];
            parent[nei] = node;
            q.push(nei);
          }
          else if(color[nei] == color[node]){
            return false;
          }
        }
      }

    return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& edges) {
    vector<int> adj[n + 1];

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }   

    vector<int> color(n + 1, -1);

    for(int i = 1; i <= n; i++){
      if(color[i] == -1){
        if(bfs(i, adj, color) == false)
          return false;
      }
    }

    return true;
    }
};