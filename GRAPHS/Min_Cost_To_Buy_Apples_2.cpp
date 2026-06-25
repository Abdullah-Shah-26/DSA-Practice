#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

class Solution {
public:
  vector<int> minCost(int n, vector<int> &prices, vector<vector<int>> &roads) {
    vector<vector<array<int, 3>>> adj(n);

    for (auto &e : roads) {
      int u = e[0];
      int v = e[1];
      int c = e[2];
      int t = e[3];

      adj[u].push_back({v, c, t});
      adj[v].push_back({u, c, t});
    }

    vector<vector<ll>> dist(2, vector<ll>(n, 0));

    // dist[0] = when we arent carrying apples
    // dist[1] = when we are carrying apples

    auto dijkstra = [&](int src, bool apple) {
      // Init
      for (auto &x : dist[apple]) {
        x = INF;
      }
      dist[apple][src] = 0;

      priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
          pq;
      pq.push({0, src});

      while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        if (d > dist[apple][node])
          continue;

        for (auto [v, c, t] : adj[node]) {
          ll cost = (apple ? (ll)c * t : c);

          if (dist[apple][v] > dist[apple][node] + cost) {
            dist[apple][v] = dist[apple][node] + cost;
            pq.push({dist[apple][v], v});
          }
        }
      }
    };

    vector<int> ans(n, 1e9);

    for (int i = 0; i < n; i++) {
      dijkstra(i, 0); // cost without apples
      dijkstra(i, 1); // cost with apples

      ll temp = 1e9;
      for (int j = 0; j < n; j++) {
        // [Travelling cost] + cost of apples at city j + cost to reach city i from j with apples
        temp = min(temp, dist[0][j] + prices[j] + dist[1][j]);
      }
      ans[i] = (int)temp;
    }

    return ans;
  }
};