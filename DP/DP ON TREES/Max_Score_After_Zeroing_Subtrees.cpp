#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution {
public:
  int maxScore(vector<int> &parent, vector<int> &op, vector<int> &score) {
    int n = op.size();

    vector<vector<int>> adj(n);

    for (int i = 1; i < n; i++)
      adj[parent[i]].push_back(i);

    function<int(int)> dfs = [&](int u) {
      // Leaf node
      if (adj[u].empty())
        return score[u];

      // Subtree sum of u
      int sum = score[u];

      // Child of u with min subtree sum
      int mini = INF;

      for (int v : adj[u]) {
        int curSum = dfs(v);
        sum += curSum;
        mini = min(mini, curSum);
      }

      // We must remove exactly 1 child & make all its subtree nodes = 0
      if (op[u])
        sum -= mini;

      // We have a choice
      else
        sum = max(sum, sum - mini);

      return sum;
    };

    return dfs(0);
  }
};