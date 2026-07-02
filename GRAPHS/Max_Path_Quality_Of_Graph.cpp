#include <bits/stdc++.h>
using namespace std;

/*

Key Observation

maxTime <= 100
min edge weight = 10

=> Maximum edge traversals = 100 / 10 = 10
=> Maximum DFS depth = 10

Each node has degree <= 4
=> Branching factor <= 4

Worst-case search states ≈ 4^10 = 2^20 ≈ 1,048,576

Hence, exhaustive DFS + backtracking is feasible.

*/

class Solution {
public:
  int n, maxT, ans;
  vector<int> vals;
  vector<int> freq; // How many times node i appeared in current path
  vector<vector<pair<int, int>>> adj;

  void dfs(int u, int timeUsed, int score) {
    if (u == 0) {
      ans = max(ans, score);
    }

    for (auto [v, wt] : adj[u]) {
      if (timeUsed + wt > maxT)
        continue;

      int add = (freq[v] == 0) ? vals[v] : 0;

      freq[v]++;
      dfs(v, timeUsed + wt, score + add);
      freq[v]--;
    }
  }

  int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges,
                         int maxTime) {
    n = values.size();
    maxT = maxTime;
    vals = values;

    adj.assign(n, {});
    freq.assign(n, 0);

    for (auto &e : edges) {
      int u = e[0];
      int v = e[1];
      int t = e[2];

      adj[u].push_back({v, t});
      adj[v].push_back({u, t});
    }

    freq[0] = 1;
    dfs(0, 0, values[0]);

    return ans;
  }
};