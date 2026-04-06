#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! MINIMUM SPANNING TREE
//* LAZY PRIM'S ALGORITHM - TC = O(E Log E)

class Solution {
  public:
    typedef pair<int,pair<int,int>> P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        
    vector<vector<pair<int,int>>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
        
    priority_queue<P, vector<P>, greater<P>> pq;
    // wt, node, parent
    pq.push({0,{0, -1}});
    vector<bool> inMST(V, false);
    int sum = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;
        
        if(inMST[node] == 1) continue;
        
        inMST[node] = 1;
        sum += wt;
        
        for(auto &temp : adj[node]){
            
            int adjNode = temp.first;
            int edWt    = temp.second;
            
            if(!inMST[adjNode]){
                pq.push({edWt,{adjNode, node}});
            }
        }
    }
    return sum;
    }
};

//! OPTIMIZED PRIMS - TC = O(E Log V)
//* Pushes Good Edges

class Solution{
    public: 
    int spanningTree(int V, vector<vector<int>> &edges){
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> minDist(V, INT_MAX);
        vector<int> inMST(V,0);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        int sum = 0;

        pq.push({0,0}); //* Cost, Node
        minDist[0] = 0;

        while(!pq.empty()){
            auto[wt, u] = pq.top();
            pq.pop();

            if(inMST[u]) continue;

            inMST[u] = 1;
            sum += wt;

            for(auto &[v,w] : adj[u]){
                if(!inMST[v] && w < minDist[v]){
                    minDist[v] = w;
                    pq.push({w, v});
                }
            }
        }
        return sum;
    }
};