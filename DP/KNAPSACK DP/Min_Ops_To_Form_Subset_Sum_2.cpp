#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int dp[101][5001];

  int f(int i, int sumLeft, vector<vector<pair<int, int>>> &mat) {
    if (sumLeft < 0)
      return 1e9;

    if (i == mat.size()) {
      if (sumLeft == 0)
        return 0;

      return 1e9;
    }

    if (dp[i][sumLeft] != -1)
      return dp[i][sumLeft];

    int ans = 1e9;

    for (int j = 0; j < mat[i].size(); j++)
      ans =
          min(ans, mat[i][j].second + f(i + 1, sumLeft - mat[i][j].first, mat));

    return dp[i][sumLeft] = ans;
  }

  void pushRemaining(vector<vector<pair<int, int>>> &mat, int val, int i,
                     int ops, int sum) {
    if (val <= 0)
      return;

    while (val <= sum) {
      mat[i].push_back({val, ops});
      val *= 2;
      ops++;
    }
  }

  int minOperations(vector<int> &nums, int sum) {
    int n = nums.size();

    // Set of final values each number can become
    vector<vector<pair<int, int>>> mat(n); // {value, operations}

    for (int i = 0; i < n; i++) {

      // Take
      pushRemaining(mat, nums[i], i, 0, sum);

      int val = nums[i];
      int ops = 0;

      while (val >= 1) {
        if (val & 1)
          pushRemaining(mat, val / 2, i, ops + 1, sum);
        else if (val / 2 >= 1)
          mat[i].push_back({val / 2, ops + 1});

        ops++;
        val /= 2;
      }

      // Not Take
      mat[i].push_back({0, 0});
    }

    memset(dp, -1, sizeof(dp));

    int ans = f(0, sum, mat);

    return ans == 1e9 ? -1 : ans;
  }
};