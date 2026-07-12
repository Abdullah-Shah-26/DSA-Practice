#include <bits/stdc++.h>
using namespace std;

// In - Out DP

// Take +ve contribution
// Discard -ve contribution
class Solution {
public:
  // For each node compute the best contribution from taking good nodes from up
  // + down
  vector<int> wt;
  vector<int> down; // down Score
  vector<int> up;   // up Score
  vector<int> ans;
  vector<vector<int>> adj;

  // Post-Order dfs, Compute child score first - Then pass to parent
  void dfs1(int u, int p) {
    down[u] = wt[u];

    for (int v : adj[u]) {
      if (v == p)
        continue;
      dfs1(v, u);
      down[u] += max(0, down[v]);
    }
  }

  // Pre-Order dfs, Compute parent score first - Then pass to child
  void dfs2(int u, int p) {
    ans[u] = down[u] + up[u];

    for (int v : adj[u]) {
      if (v == p)
        continue;

      int removedScore = down[u] - max(0, down[v]);
      up[v] = max(0, removedScore + up[u]);

      dfs2(v, u);
    }
  }

  vector<int> maxSubgraphScore(int n, vector<vector<int>> &edges,
                               vector<int> &good) {
    adj.resize(n);
    wt.resize(n);
    down.resize(n);
    up.resize(n);
    ans.resize(n);

    for (auto &e : edges) {
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
      if (good[i] == 0) // bad
        wt[i] = -1;
      else // good
        wt[i] = 1;
    }

    dfs1(0, -1);
    dfs2(0, -1);

    return ans;
  }
};