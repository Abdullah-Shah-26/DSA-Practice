#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LINF = 1e18;
using pll = pair<ll,ll>;

class Solution {
public:
  long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
    vector<vector<pll>> adj(n), adjRev(n);

    for(auto &e : edges){
      ll u = e[0];
      ll v = e[1];
      ll w = e[2];
      
      adj[u].push_back({v, w});
      adjRev[v].push_back({u, w});
    }

    // 3 Dijkstra's
    // src1 -> all cities - dist1
    // src2 -> all cities - dist2

    // Use reverse graph  - Since graph is directed we need to reverse it
    // dest -> all cities - dist3

    // src1 & src2 have common point that reaches dest
    // Assume every city to be that common point & take the one with minimal distance

    vector<ll> dist1(n, LINF), dist2(n, LINF), dist3(n, LINF);
  
    auto dijkstra = [&](vector<vector<pll>> &adj, ll src, vector<ll> &dist){
      priority_queue<pll, vector<pll>, greater<pll>> pq;
      
      dist[src] = 0;
      pq.push({0LL, src});

      while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) 
          continue;

        for(auto [v, edWt] : adj[u]){
          if(dist[v] > dist[u] + edWt){
            dist[v] = dist[u] + edWt;
            pq.push({dist[v], v});
          }
        }
      }
    };

    dijkstra(adj, src1, dist1);
    dijkstra(adj, src2, dist2);
    dijkstra(adjRev, dest, dist3);
    
    ll ans = LINF;

    for(int i = 0; i < n; i++){
      if(dist1[i] == LINF || dist2[i] == LINF || dist3[i] == LINF)
        continue;
      
      // A common point x 
      // dist1 from src1
      // dist2 from src2 
      // dist3 from dest 
      
      ans = min(ans, dist1[i] + dist2[i] + dist3[i]);
    }

    return ans == LINF ? -1 : ans;
  }
};