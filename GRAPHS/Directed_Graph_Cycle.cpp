#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DFS

class Solution {
  public:
  
    bool dfs(int i, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> &adj){
      vis[i] = 1;
      pathVis[i] = 1;
      
      for(auto &nei : adj[i]){
          if(!vis[nei]){
              if(dfs(nei, vis, pathVis, adj)) return true;
          }
          else if(pathVis[nei]){
              return true;
          }
      }
      
      pathVis[i] = 0;
      return false;
    } 
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        
        adj[u].push_back(v);
    }
    
    vector<bool> vis(V,0), pathVis(V,0);
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            if(dfs(i, vis, pathVis, adj)) return true;
        }
    }
    return false;
    }
};

//! Using Single Visited Array

class Solution {
  public:
  
    bool dfs(int i, vector<int> &vis, vector<vector<int>> &adj){
      vis[i] = 1; // Visited
      vis[i] = 2; // In Current Path

      for(auto &nei : adj[i]){
          if(vis[nei] == 0){
              if(dfs(nei, vis,adj)) return true;
          }
          else if(vis[nei] == 2){
              return true;
          }
      }
      
      vis[i] = 1;
      return false;
    } 
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        
        adj[u].push_back(v);
    }
    
    vector<int> vis(V,0);
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            if(dfs(i, vis, adj)) return true;
        }
    }
    return false;
    }
};

//! Using BFS - Khan's Algo

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
    int cnt = 0;
    vector<vector<int>> adj(V);
    vector<int> inDeg(V,0);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        inDeg[v]++;
    }
    
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(inDeg[i] == 0){
            q.push(i);
        }
    }
    
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
    
    return cnt != V;
    }
};