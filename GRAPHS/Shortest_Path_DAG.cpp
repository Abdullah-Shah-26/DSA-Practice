#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Topo-Sort + Edge Relaxation
//* TC = O(V + E)  ||   SC = O(V) 

// User function Template for C++
class Solution {
  public:
    void dfs(int node, vector<bool> &vis, stack<int> &st, vector<vector<pair<int,int>>> &adj){
        vis[node] = 1;
        
        for(auto &it : adj[node]){
            int nei = it.first;
            if(!vis[nei]){
                dfs(nei, vis, st, adj);
            }
        }
        
        st.push(node);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        
        adj[u].push_back({v,w});
    }
    
    vector<bool> vis(V, 0);
    stack<int> st;
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, vis, st, adj);
        }
    }
    
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        for(auto &it : adj[node]){
            int nei = it.first;
            int edWt = it.second;
            
            if(dist[node] != INT_MAX && dist[node] + edWt < dist[nei]){
                dist[nei] = dist[node] + edWt;
            }
        }
    }
    
    for(int i = 0; i < V; i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;                
        }
    }
    
    return dist;
    }
};

