#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Tarjans - Finding Bridges
//* TC = O(V + E)  ||  SC = O(V) - Ignoring I build adjList

class Solution {
  public:
    int timer = 1;

    void dfs(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj,vector<int> &insertionTime, vector<int> &lowestTime, vector<vector<int>> &bridges){
      vis[node] = 1;
      insertionTime[node] = lowestTime[node] = timer;
      timer++;

      for(auto &nei : adj[node]){
        if(nei == parent) continue;

        if(!vis[nei]){
          dfs(nei, node, vis, adj, insertionTime, lowestTime, bridges);
          lowestTime[node] = min(lowestTime[node], lowestTime[nei]);
          
          if(lowestTime[nei] > insertionTime[node]){ // Its a bridge
            bridges.push_back({nei, node}); 
          }
        }
        else {
          //! Back Edge Formula
          // node1 ------- node2 ------- nei 
          //  |                           |
          //  -----------------------------  //? BackEdge

          lowestTime[node] = min(lowestTime[node], insertionTime[nei]);
        }
      }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }    

    vector<bool> vis(n, 0);
    vector<int> insertionTime(n, 0);
    vector<int> lowestTime(n, 0); // Lowest Reachable Time

    vector<vector<int>> bridges;

    for(int i = 0; i < n; i++){
      if(!vis[i]){
        dfs(i, -1, vis, adj, insertionTime, lowestTime, bridges);
      }
    }

    return bridges;
    }
};

//! Tarjans - Find SCC
//* TC = O(V + E)  || SC = O(V)

class Solution {
  public:
    int timer = 0;
    
    void dfs(int node,
    vector<vector<int>> &adj,
    vector<int> &tin,
    vector<int> &low,
    vector<int> &vis, 
    vector<int> &inStack,
    stack<int> &st,
    vector<vector<int>> &sccs){
    
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    
    st.push(node);
    inStack[node] = 1;
    
    for(auto &nei : adj[node]){
        if(!vis[nei]){
            // Tree Edge
            dfs(nei, adj, tin, low, vis, inStack, st, sccs);
            low[node] = min(low[node], low[nei]);
        }
        else if(inStack[nei]){ // nei is part of current dfs
            // Back Edge
            low[node] = min(low[node], tin[nei]);
        }
    }
    
    // Root of SCC
    if(low[node] == tin[node]){
        vector<int> comp;
        
        while(true){
            int u = st.top();
            st.pop();
            
            inStack[u] = 0;
            
            comp.push_back(u);
            if(u == node) break;
        }
        
        sccs.push_back(comp);
    }
    
    }
  
    int tarjans(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        
        adj[u].push_back(v);
    }
    
    vector<int> tin(V, -1); // time of insertion
    vector<int> low(V, -1); // lowest reachable time
    vector<int> vis(V, 0);
    vector<int> inStack(V, 0);
    
    stack<int> st;
    vector<vector<int>> sccs; // strongly connected components
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, adj, tin, low, vis, inStack, st, sccs);
        }
    }
    
    return sccs.size();
    }
};