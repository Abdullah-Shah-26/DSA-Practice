#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Dijkstra + Counting Ways
//* TC = O(V + E)LogV  || SC  = O(V + E)

class Solution {
public:
    static const int MOD = 1e9 + 7;
    typedef pair<long long,long long> P;
    int countPaths(int n, vector<vector<int>>& edges) {
    vector<pair<int,int>> adj[n];

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      long long w = e[2];

      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }    

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<long long> dist(n, LLONG_MAX), ways(n, 0);

    pq.push({0,0}); // dist, node
    dist[0] = 0;
    ways[0] = 1;

    while(!pq.empty()){
      auto it = pq.top();
      pq.pop();
      long long dis = it.first;   
      int node = it.second;

      if(dis > dist[node]) continue;
    
      for(auto it : adj[node]){
        int v = it.first;
        long long w = it.second;

        if(dis + w < dist[v]){
          dist[v] = (dis + w);
          pq.push({dist[v],v});

          ways[v] = ways[node]; // First Time arrival with this less dist 
        }
        else if(dis + w == dist[v]){ // Same Dist - Count Total Ways
          ways[v] = (ways[v] + ways[node])%MOD; 
        }
      }
    }
    return ways[n-1]%MOD;
    }
};