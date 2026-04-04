#include <bits/stdc++.h>
using namespace std;

//! BFS 
class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
    vector<int> inDeg(V,0);
    vector<vector<int>> adj(V);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      adj[v].push_back(u);
      inDeg[u]++;
    }

    queue<int> q;
    for(int i = 0; i < V; i++){
      if(inDeg[i] == 0){
        q.push(i);
      }
    }
    int cnt = 0;

    while(!q.empty()){
      int node = q.front();
      q.pop();
      cnt++;

      for(auto &nei : adj[node]){
        inDeg[nei]--;

        if(inDeg[nei] == 0){
          q.push(nei);
        }
      }
    }

    return cnt == V;
    }
};

//! DFS 

class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
      vis[node] = 1; // In current Recursion

      for(auto &nei : adj[node]){
        if(vis[nei] == 0){
          if(dfs(nei, vis, adj)) return true;
        }
        else if(vis[nei] == 1){
          return true;
        }
      }

      vis[node] = 2; // Fully Processed
      return false;
    }
    
    bool canFinish(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[v].push_back(u);
    }

    vector<int> vis(V, 0);

    for(int i = 0; i < V; i++){
      if(!vis[i]){
        dfs(i, vis, adj);
      }
    }

    int cnt = 0;
    for(int i = 0; i < V; i++){
      if(vis[i] == 2){
        cnt++;
      }
    }

    return cnt == V;
    }
};