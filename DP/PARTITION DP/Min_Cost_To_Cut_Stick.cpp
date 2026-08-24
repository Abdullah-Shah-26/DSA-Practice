#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int dp[102][102];
  int solve(int l, int r, vector<int> &cuts) {
    if (r - l < 2)
      return 0;

    if (dp[l][r] != -1)
      return dp[l][r];

    int ans = INT_MAX;

    for (int idx = l + 1; idx <= r - 1; idx++) {
      int cost =
          (cuts[r] - cuts[l]) + solve(l, idx, cuts) + solve(idx, r, cuts);
      ans = min(ans, cost);
    }

    return dp[l][r] = ans;
  }

  int minCost(int n, vector<int> &cuts) {
    sort(begin(cuts), end(cuts));

    cuts.insert(begin(cuts), 0);
    cuts.push_back(n);

    memset(dp, -1, sizeof(dp));

    return solve(0, cuts.size() - 1, cuts);
  }
};

// Bottom Up DP :

class Solution {
public:
  int minCost(int n, vector<int> &cuts) {
    sort(begin(cuts), end(cuts));

    cuts.insert(begin(cuts), 0);
    cuts.push_back(n);

    int m = cuts.size();

    vector<vector<int>> dp(m, vector<int>(m, 0));

    for (int len = 2; len < m; len++) {
      for (int l = 0; l + len < m; len++) {
        // len = r - l
        // r = l + len
        int r = l + len;

        dp[l][r] = INT_MAX;

        for (int idx = l + 1; idx <= r - 1; idx++) {
          int cost = (cuts[r] - cuts[l]) + dp[l][idx] + dp[idx][r];

          dp[l][r] = min(dp[l][r], cost);
        }
      }
    }

    return dp[0][m - 1];
  }
};