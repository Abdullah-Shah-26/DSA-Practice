#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

/*
Semi Eulerian Graph : 

- Euler Path
- St & End node always have odd degree 
*/

/*
Eulerian Graph : 

- Both Euler Path & Circuit
- All nodes will have even degree
- Can st at any node
- St == End

*/

/*
Questions : 
Check if Graph is Eulerian ? 
- Semi Eulerian
- Non Eulerian

Find Euler Path/ Ckt in graph
*/

//!----------------------------

//* TC = O(V + E) || SC = O(V)
//* Undirected - Graph

/*
//* If Graph is Directed

End Node Will Have : 
OutDeg[node] - Indeg[node] = 1

Start Node Will Have : 
Indeg[node] - OutDeg[node] = 1

Other Nodes : 
Indeg[node] == OutDeg[node]

If All Nodes have : 
Indeg[node] == OutDeg[node] , Its Eulerian Circuit
*/

class Solution {
  public:
    
    void dfs(int node, vector<bool> &vis, vector<int> adj[]){
        vis[node] = 1;
        
        for(auto &nei : adj[node]){
            if(!vis[nei]){
                dfs(nei, vis, adj);
            }
        }
    }
    
    bool isConnected(int V, vector<int> adj[]){
    
        // Find a non zero deg verted
        int nonZeroDegVertex = -1;
        
        for(int i = 0; i < V; i++){
            if(adj[i].size() > 0){
                nonZeroDegVertex = i;
                break;
            }
        }
        
        vector<bool> vis(V, 0);

        dfs(nonZeroDegVertex, vis, adj);        
            
        for(int i = 0; i < V; i++){
            /// Its a non zero degree vertex and isnt visited (Not Connnected)
            if(!vis[i] && adj[i].size() > 0){
                return false;
            }
        }
        
        return true;
    }
  
    int isEulerCircuit(int V, vector<int> adj[]) {
    
    // Non Zero Degree Vertex should be connected
    if(!isConnected(V, adj)){
        return 0; 
    }
    
    int oddDegVertices = 0;
    
    for(int i = 0; i < V; i++){
        if(adj[i].size() & 1){
            oddDegVertices++;
        }
    }
    
    if(oddDegVertices > 2) // Neither Path nor Circuit
        return 0;
        
    if(oddDegVertices == 2) // Euler Path
        return 1;
    
    if(oddDegVertices == 0) // Euler Circuit
        return 2;
        
    }    
};