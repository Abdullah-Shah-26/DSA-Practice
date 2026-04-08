#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(V + E)  ||   SC = O(V + E)

class Solution {
  public:
    void dfs1(int node, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &st){
        vis[node] = 1; 
        
        for(auto &nei: adj[node]){
            if(!vis[nei]){
                dfs1(nei, vis, adj, st);
            }
        }
            
        st.push(node); // processed
    }
    
    void dfs2(int node, vector<bool> &vis, vector<vector<int>> &adjT){
        vis[node] = 1;
        
        for(auto &nei : adjT[node]){
            if(!vis[nei]){
                dfs2(node, vis, adjT);
            }
        }
    }
  
    int kosaraju(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        
        adj[u].push_back(v);
    }
    
    stack<int> st;
    vector<bool> vis(V, 0);
    
    // Order by finish time
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs1(i, vis, adj, st);
        }
    }
    
    // Reverse the Graph
    vector<vector<int>> adjT(V);
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        
        adj[v].push_back(u);
    }
    
    // Process in reverse order    
    fill(vis.begin(), vis.end(), 0);
    int scc = 0;
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        if(!vis[node]){
            scc++;
            dfs2(node, vis, adjT);
        }
    }
    
    return scc;
    }
};