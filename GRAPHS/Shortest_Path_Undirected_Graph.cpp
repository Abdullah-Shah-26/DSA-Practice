#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! All Edge Wt = 1
//! Normal BFS + dist array
//* TC = O(V + 2E)  || SC = O(V)

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dist(V, INT_MAX);

    queue<int> q;
    q.push(src);
    
    dist[src] = 0;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto &nei : adj[node]){
            if(dist[node] + 1 < dist[nei]){
                dist[nei] = dist[node] + 1;
                q.push(nei);
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
