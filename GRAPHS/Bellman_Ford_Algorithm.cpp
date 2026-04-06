#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* Detectes -ve cycle
//* TC = O(V * E)   ||  SC = O(V)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    
    bool updated = false;
    
    for(int i = 0; i < V-1; i++){
        updated = false;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if(!updated) break;
    }
    
    if(!updated) return dist; // No relaxation happened, This is optimal dist
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        
        if(dist[u] != 1e8 && dist[u] + w < dist[v]){ // -ve cycle exists
            return {-1};
        }
    }
    
    return dist;
    }
};