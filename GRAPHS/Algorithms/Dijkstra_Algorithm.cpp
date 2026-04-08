#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Using PQ - (Faster cause heap is internally implemented as array & set as RBT)
//* TC = O((V + E) LogV)  || SC = O(V + E)

class Solution {
  public:
    typedef pair<int,int> P;
        
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    
    vector<pair<int,int>> adj[V];
    
    for(auto &e : edges){ // O(E)
        int u = e[0];
        int v = e[1];
        int w = e[2];
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> dist(V, INT_MAX);
    
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int dis = it.first;
        int node = it.second;
        
        if(dis > dist[node]) continue; 
        
        for(auto &nei : adj[node]){
            int neiNode = nei.first;
            int edWt = nei.second;
            
            if(dis + edWt < dist[neiNode]){
                dist[neiNode] = dis + edWt;
                
                pq.push({dis + edWt, neiNode});
            }
        }
    }
    
    return dist;
    }
};

//! Using Ordered Set

class Solution {
  public:
    typedef pair<int,int> P;
        
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    
    vector<pair<int,int>> adj[V];
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    set<P>st;
    vector<int> dist(V, INT_MAX);
    
    dist[src] = 0;
    st.insert({0, src});
    
    while(!st.empty()){
        auto it = *st.begin();
        st.erase(it);
        
        int dis = it.first;
        int node = it.second;
        
        for(auto &nei : adj[node]){
            int v = nei.first;
            int wt = nei.second;
            
            if(dis + wt < dist[v]){
                
                if(dist[v] != INT_MAX){ // Remove Previous Stale Enteries
                    st.erase({dist[v], v});
                }
                
                dist[v] = dis + wt;
                
                st.insert({dis + wt, v});
            }
        }
    }
    
    return dist;
    }
};