#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Floyd's Warshall 
//* TC = O(V^3)  ||  SC = O(V^2)

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distThreshold) {
    vector<vector<int>> dist(n, vector<int> (n, INT_MAX));

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      int wt = e[2];

      dist[u][v] = wt;
      dist[v][u] = wt;
    }

    for(int i = 0; i < n; i++) dist[i][i] = 0; 

    for(int k = 0; k < n; k++){
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          // Unreachable 
          if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;

          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }   

    int ans = -1;
    int minCnt = n;

    for(int i = 0; i < n; i++){
      int cnt = 0;
      for(int j = 0; j < n; j++){
        if(dist[i][j] <= distThreshold)
          cnt++;
      }
      if(cnt <= minCnt){
        minCnt = cnt;
        ans = i;
      }   
    }

    return ans; 
    }
};

//! Dijkstra From Each Node to compute Shortest Distance
//* TC = O(V^3 LogV)   SC = O(V + E)

class Solution {
public:
    int n, dT;
    vector<int> dijkstra(int src, vector<pair<int,int>> adj[]){
      vector<int> dist(n, INT_MAX);

      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

      pq.push({0,src});
      dist[src] = 0;

      while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int dis = it.first;
        int node = it.second;

        if(dis > dist[node]) continue;

        //* Early pruning
        if(dis > dT) continue;

        for(auto &nei : adj[node]){
          int adjNode = nei.first;
          int edWt = nei.second;

          if(dis + edWt < dist[adjNode]){
            dist[adjNode] = dis + edWt;

            pq.push({dis + edWt, adjNode});
          }
        }
      }
      return dist;
    }

    int findTheCity(int _n, vector<vector<int>>& edges, int distThreshold) {
    n = _n;
    dT = distThreshold;
    vector<pair<int,int>> adj[n];

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      int w = e[2];
      
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }

    int minCnt = n;
    int ans = -1;

    for(int i = 0; i < n; i++){
      vector<int> dist = dijkstra(i, adj);

      int cnt = 0;
      for(int j = 0; j < n; j++){
        if(dist[j] <= distThreshold){
          cnt++;
        }
      }

      if(cnt <= minCnt){
        minCnt = cnt;
        ans = i;
      }
    }

    return ans;
    }
};