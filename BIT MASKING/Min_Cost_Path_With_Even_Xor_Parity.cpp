#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const int INF = INT_MAX;

  // Cant use 1e9, cause it can be a valid answer

  int minActivationCost(vector<vector<int>> &edges, vector<int> &values) {
    int n = values.size();

    for (auto &x : values)
      x = (__builtin_popcount(x)) % 2;

    int ans = INF;

    vector<vector<pair<int, int>>> adj(n);

    for (auto &e : edges) {
      int u = e[0];
      int v = e[1];
      int w = e[2];

      adj[u].push_back({v, w});
      adj[v].push_back({u, w});

      // If parity of (u, v) is same, consider its edge wt
      // odd -- odd
      // even -- even
      if (values[u] == values[v])
        ans = min(ans, w);
    }

    // Checking : odd --- even --- odd
    //             v1 ---- u  ---- v2
    // Cause final xor parity will be : Even
    for (int u = 0; u < n; u++) {
      if (values[u])
        continue; // Center must be even

      // First & second smallest
      int min1 = INF, min2 = INF;

      for (auto [v, w] : adj[u]) {
        if (values[v]) { // Connected nodes must be odd
          min2 = min(min2, w);

          if (min2 < min1)
            swap(min1, min2);
        }
      }

      if (min2 < INF)
        ans = min(ans, min1 + min2);
    }

    if (ans == INF)
      return -1;

    return ans;
  }
};