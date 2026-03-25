#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Brute Force : O(V * (V + E))  
//! SC = O(V + E) for building adj list

class Solution {
public:
    int result = INT_MAX;
    
    void bfs(int root, vector<vector<int>> &adj, vector<bool> &vis, vector<int > &dist){
      // node, parent
      queue<pair<int,int>>q;
      q.push({root, -1});
      dist[root] = 0;
      vis[root] = 1;

      while(!q.empty()){
        auto it = q.front();
        q.pop();
        int node = it.first;
        int parent = it.second;

        //! Pruning Step
        if(dist[node] >= result) continue;

        for(auto nei : adj[node]){
          if(!vis[nei]){
            vis[nei] = 1;
            q.push({nei, node});
            dist[nei] = dist[node] + 1; // Since its unweighted graph
          }
          else if(nei != parent){
            // already vis & not parent - cycle exist
            result = min(result, dist[nei] + dist[node] + 1);
          }
        }
      }
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n + 1);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }         

    for(int i = 0; i < n; i++){
      vector<bool> vis(n + 1, 0);
      vector<int> dist(n + 1, INT_MAX);

      bfs(i, adj, vis, dist);
    }

    if(result == INT_MAX) return -1;

    return result;
    }
};