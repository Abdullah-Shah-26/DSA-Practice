#include <bits/stdc++.h>
using namespace std;

// Binary Search to maximize min allowed edge wt
// Dijkstra to find path with min score

// TC = ((V + E) LogV) * Log(W) | W = edge wt range  

using ll = long long;
using P = pair<ll, int>;

class Solution {
public:
  int n;
  bool check(int mid, vector<pair<int, int>> adj[], ll k) {

    vector<ll> dist(n, LLONG_MAX); // min cost path from src -> ith node
    priority_queue<P, vector<P>, greater<P>> pq;

    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();

      if (d > k) // Cost of all edges should'nt exceed k
        return false;

      if (u == n - 1)
        return true;

      if (d > dist[u]) // Dijkstra pruning
        continue;

      for (auto [v, cost] : adj[u]) {
        if (cost < mid) // Cost must atleast be >= mid
          continue;

        if (d + cost < dist[v]) {
          dist[v] = d + cost;
          pq.push({dist[v], v});
        }
      }
    }

    return false;
  }

  int findMaxPathScore(vector<vector<int>> &edges, vector<bool> &online,
                       long long k) {
    n = online.size();
    int l = 1e9;
    int r = 0;

    vector<pair<int, int>> adj[n];

    for (auto &e : edges) {
      int u = e[0];
      int v = e[1];
      int cost = e[2];

      if (!online[u] || !online[v])
        continue;

      adj[u].push_back({v, cost});
      l = min(cost, l);
      r = max(cost, r);
    }

    int ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1; // Only consider edges with cost >= mid

      if (check(mid, adj, k)) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }

    return ans;
  }
};