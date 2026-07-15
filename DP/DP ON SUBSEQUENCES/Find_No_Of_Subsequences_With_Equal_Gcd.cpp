#include <bits/stdc++.h>
using namespace std;

// Rec + Memo

const int MOD = 1e9 + 7;

class Solution {
public:
  int dp[201][201][201];

  int solve(int i, int gcd1, int gcd2, vector<int> &nums) {

    if (i >= nums.size()) {

      if (gcd1 != 0 && gcd2 != 0)
        return gcd1 == gcd2;

      return 0;
    }

    if (dp[i][gcd1][gcd2] != -1)
      return dp[i][gcd1][gcd2];

    int skip = solve(i + 1, gcd1, gcd2, nums);
    int takeInS1 = solve(i + 1, __gcd(gcd1, nums[i]), gcd2, nums);
    int takeInS2 = solve(i + 1, gcd1, __gcd(gcd2, nums[i]), nums);

    return dp[i][gcd1][gcd2] = ((skip + takeInS1) % MOD + takeInS2) % MOD;
  }

  int subsequencePairCount(vector<int> &nums) {
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, 0, nums);
  }
};

// Bottom Up :

const int MOD = 1e9 + 7;

class Solution {
public:
  int subsequencePairCount(vector<int> &nums) {
    int n = nums.size();
    int maxi = *max_element(begin(nums), end(nums));

    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(maxi + 1, vector<int>(maxi + 1, 0)));

    for (int g1 = 0; g1 <= maxi; g1++)
      for (int g2 = 0; g2 <= maxi; g2++)
        if (g1 != 0 && g2 != 0 && g1 == g2)
          dp[n][g1][g2] = 1;

    for (int i = n - 1; i >= 0; i--) {
      for (int g1 = maxi; g1 >= 0; g1--) {
        for (int g2 = maxi; g2 >= 0; g2--) {

          int skip = dp[i + 1][g1][g2];
          int takeInS1 = dp[i + 1][__gcd(g1, nums[i])][g2];
          int takeInS2 = dp[i + 1][g1][__gcd(g2, nums[i])];

          dp[i][g1][g2] = ((skip + takeInS1) % MOD + takeInS2) % MOD;
        }
      }
    }

    return dp[0][0][0];
  }
};

// Space Optimization :

const int MOD = 1e9 + 7;

class Solution {
public:
  int subsequencePairCount(vector<int> &nums) {
    int n = nums.size();
    int maxi = *max_element(begin(nums), end(nums));

    vector<vector<int>> next(maxi + 1, vector<int>(maxi + 1, 0));
    vector<vector<int>> cur(maxi + 1, vector<int>(maxi + 1, 0));

    for (int g1 = 0; g1 <= maxi; g1++)
      for (int g2 = 0; g2 <= maxi; g2++)
        if (g1 != 0 && g2 != 0 && g1 == g2)
          next[g1][g2] = 1;

    for (int i = n - 1; i >= 0; i--) {

      // Every g1 & g2 is overwritten so no need to clear up
      // for(auto &row : cur)
      //   fill(begin(row), end(row), 0);

      for (int g1 = maxi; g1 >= 0; g1--) {
        for (int g2 = maxi; g2 >= 0; g2--) {

          int skip = next[g1][g2];
          int takeInS1 = next[__gcd(g1, nums[i])][g2];
          int takeInS2 = next[g1][__gcd(g2, nums[i])];

          cur[g1][g2] = ((skip + takeInS1) % MOD + takeInS2) % MOD;
        }
      }

      swap(cur, next);
    }

    return next[0][0];
  }
};