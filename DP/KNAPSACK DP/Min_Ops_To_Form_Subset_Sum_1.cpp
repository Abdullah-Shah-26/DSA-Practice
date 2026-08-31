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

  int minOperations(vector<int> &nums, int sum) {
    int n = nums.size();

    vector<vector<pair<int, int>>> mat(n); // {value, operations}

    for (int i = 0; i < n; i++) {
      int val = nums[i]; // Take
      int ops = 0;

      while (val <= sum) {
        mat[i].push_back({val, ops});
        val *= 2;
        ops++;
      }

      val = nums[i] / 2;
      ops = 1;

      while (val >= 1) {
        mat[i].push_back({val, ops});
        val /= 2;
        ops++;
      }

      mat[i].push_back({0, 0}); // Not take
    }

    memset(dp, -1, sizeof(dp));

    int ans = f(0, sum, mat);

    return ans == 1e9 ? -1 : ans;
  }
};