#include <bits/stdc++.h>
using namespace std;

// Dijkstra + DP

using ll = long long;
const ll INF = 1e18;
using T = tuple<ll,int,int>;

class Solution {
public:

  vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int src, int target) {
    vector<vector<pair<int,int>>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      int t = e[2];

      adj[u].push_back({v,t});
    }  

    // dp[node][usedPower] = minTime
    vector<vector<ll>> dp(n, vector<ll> (power + 1, INF));

    priority_queue<T, vector<T>, greater<T>> pq; 
    
    dp[src][0] = 0;
    pq.push({0, 0, src}); // [time, powerUsed, node]

    while(!pq.empty()){
      auto [curT, used, u] = pq.top();
      pq.pop();

      if(curT > dp[u][used]) // Pruning
        continue;

      if(u == target)
        return {curT, (ll)(power - used)}; // [remPower = power - usedPower]

      int nextUsed = used + cost[u];
      if(nextUsed > power)
        continue;

      for(auto &[v,t] : adj[u]){
        ll nexT = curT + t;

        if(nexT < dp[v][nextUsed]){
          dp[v][nextUsed] = nexT;
          pq.push({nexT, nextUsed, v});
        }
      }
    }
    
    return {-1,-1};
  }
};