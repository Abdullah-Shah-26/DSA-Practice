#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* Dijkstra 

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& edges, int n, int src) {
  vector<pair<int,int>> adj[n+1];

  for(auto &e : edges){
    int u = e[0];
    int v = e[1];
    int w = e[2];

    adj[u].push_back({v,w});
  }

  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  vector<int> dist(n + 1, INT_MAX);

  pq.push({0, src}); // dist, st node
  dist[src] = 0;

  while(!pq.empty()){
    auto it = pq.top();
    pq.pop();

    int dis = it.first;
    int node = it.second;

    if(dis > dist[node]) continue;

    for(auto &nei : adj[node]){
      int adjNode = nei.first;
      int wt = nei.second;

      if(dis + wt < dist[adjNode]){
        dist[adjNode] = dis + wt;

        pq.push({dis + wt, adjNode});
      }
    }
  }

  int ans = 0;

  for(int i = 1; i <= n; i++){ // nodes are 1 based
    ans = max(ans, dist[i]);
  }

  return ans == INT_MAX ? -1 : ans; 
  }
};