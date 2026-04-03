#include <bits/stdc++.h>
using namespace std;

//! BFS 
//* TC = O(V + E) || SC = O(V)
class Solution {
  public:
    bool bfs(int src, vector<vector<int>> &adj, vector<bool> &vis){
        vis[src] = 1;

        queue<pair<int,int>> q;
        q.push({src, -1});
        
        while(!q.empty()){
            auto [node, parent] = q.front();
            q.pop();
            
            for(auto &nei : adj[node]){
                if(!vis[nei]){
                    vis[nei] = 1;
                    q.push({nei, node});
                }
                // Already visited by some other node which isn't parent
                else if(nei != parent){
                    return true;
                }
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
    
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> vis(V, 0);
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            if(bfs(i, adj, vis)){
                return true;
            }
        }
    }
    
    return false;
    }
};

//! DFS - Recursive

class Solution {
  public:
    bool dfs(int node,int parent, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node] = 1;
        
        for(auto &nei : adj[node]){
            if(!vis[nei]){
                if(dfs(nei, node, vis, adj)){
                    return true;
                }
            }
            else if(nei != parent){
                return true;
            }
        }
        
        return false;
    }
        
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        vector<bool> vis(V, 0);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, -1, vis, adj)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//! DFS - Iterative

class Solution {
  public:
    bool dfs(int src, vector<bool> &vis, vector<vector<int>> &adj){
        vis[src] = 1;
        
        stack<pair<int,int>> st;
        st.push({src, -1});
        
        while(!st.empty()){
            auto [node, parent] = st.top();
            st.pop();
            
            for(auto &nei : adj[node]){
                if(!vis[nei]){
                    vis[nei] = 1;
                    st.push({nei, node});
                }
                else if(nei != parent){
                    return true;
                }
            }
        }
        return false;
    }
        
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        vector<bool> vis(V, 0);
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, vis, adj)){
                    return true;
                }
            }
        }
        
        return false;
    }
};