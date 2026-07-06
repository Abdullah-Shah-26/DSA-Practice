#include <bits/stdc++.h>
using namespace std;

// TC = O(2^N * (N*N) * (N*N)) 
//    = No of States * Work done per state

class Solution {
public:
  int n;
  string label;
  vector<vector<int>> adj;

  int dp[14][14][1 << 14];

  int dfs(int u, int v, int mask) {
    int &res = dp[u][v][mask];

    if (res != -1)
      return res;

    res = max(res, __builtin_popcount(mask));

    for (int x : adj[u]) {
      if (mask & (1 << x))
        continue;

      for (int y : adj[v]) {
        if (mask & (1 << y))
          continue;

        if (x == y) // Skip, both are same nodes
          continue;

        if (label[x] != label[y]) // Diff nodes diff labels
          continue;

        // Diff nodes, same labels, valid expansion
        res = max(res, dfs(x, y, mask | (1 << x) | (1 << y)));
      }
    }

    return res;
  }

  int maxLen(int N, vector<vector<int>> &edges, string s) {
    n = N;
    label = s;
    adj.assign(n, {});

    for (auto &e : edges) {
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int ans = 1;
    memset(dp, -1, sizeof(dp));

    // Odd centers
    for (int i = 0; i < n; i++)
      ans = max(ans, dfs(i, i, 1 << i));

    // Even centers
    for (auto it : edges) {
      int u = it[0];
      int v = it[1];

      if (label[u] == label[v])
        ans = max(ans, dfs(u, v, (1 << u) | (1 << v)));
    }

    return ans;
  }
};