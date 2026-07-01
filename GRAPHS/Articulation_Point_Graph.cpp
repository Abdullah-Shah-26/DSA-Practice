#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(V + E)  ||  SC = O(V + E)

class Solution {
  public:
    int timer = 0;  
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &mark){
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    
    int child = 0;
    for(auto &nei : adj[node]){
        if(nei == parent) continue;
        
        if(!vis[nei]){
            dfs(nei, node, adj, vis, tin, low, mark);
            
            low[node] = min(low[node], low[nei]);
            
            if(low[nei] >= tin[node] && parent != -1){
                mark[node] = 1;
            }
            
            child++;
        }
        else{
            // Back Edge
            low[node] = min(low[node], tin[nei]);
        }
        
        if(child > 1 && parent == -1){ // Edge Case - parent has multiple children, then its articulation pt
            mark[node] =1;
        }
     }
    }
    
    vector<int> articulationPoints(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> tin(V, 0);
    vector<int> low(V, 0);
    vector<int> mark(V, 0); // Marks  Articulation Points
    
    for(int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i, -1, adj, vis, tin, low, mark);
        }
    }    
    
    vector<int> ans;
    for(int i = 0; i < V; i++){
        if(mark[i]){
            ans.push_back(i);
        }
    }
    
    if(ans.size() == 0) 
        return {-1};
        
    return ans;
    }
};