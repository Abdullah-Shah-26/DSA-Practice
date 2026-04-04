#include <bits/stdc++.h>
using namespace std;
 
//! For D-A-G
//* TC = O(V + E) || SC = O(V)

class Solution {
  public:
    void dfs(int node, stack<int> &st, vector<vector<int>> &adj, vector<bool> &vis){
        vis[node] = 1;
        
        for(auto &nei : adj[node]){
            if(!vis[nei]){
                dfs(nei, st, adj, vis);
            }
        }
        
        st.push(node);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
    }
    
    vector<bool> vis(V,0);
    stack<int> st;
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, st, adj, vis);
        }
    }
    
    vector<int> ans;
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
    }
};

//! BFS - Khan's Algo
//* TC = O(V + E) || SC = O(V)

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<int> ans;
    vector<int> inDeg(V,0);
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        inDeg[v]++;
        adj[u].push_back(v);
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
        
        ans.push_back(node);
        
        for(auto &nei : adj[node]){
            inDeg[nei]--;
            
            if(inDeg[nei] == 0){
                q.push(nei);
            }
        }
    }
    
    return ans;
    }
};