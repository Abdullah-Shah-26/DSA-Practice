#include <bits/stdc++.h>
using namespace std;

// Rec + Memo

class Solution {
public:
  int n;
  int dp[1001];

  int f(int i, vector<int> &nums, int target) {
    if (i == n - 1)
      return 0; // Reached destination, no further steps needed

    if (dp[i] != -1)
      return dp[i];

    int ans = INT_MIN;

    for (int j = i + 1; j < n; j++) {
      if (abs(nums[i] - nums[j]) <= target) {
        ans = max(ans, 1 + f(j, nums, target));
      }
    }

    return dp[i] = ans;
  }

  int maximumJumps(vector<int> &nums, int target) {
    n = nums.size();

    memset(dp, -1, sizeof(dp));

    int res = f(0, nums, target);

    return res < 0 ? -1 : res;
  }
};

// TC = O(N) = SC - Bottom Up

class Solution {
public:
  int maximumJumps(vector<int> &nums, int target) {
    int n = nums.size();

    vector<int> dp(n + 1, INT_MIN);
    dp[n - 1] = 0; // Base Case

    for (int i = n - 2; i >= 0; i--) {
      int ans = INT_MIN;

      for (int j = i + 1; j < n; j++)
        if (abs(nums[i] - nums[j]) <= target && dp[j] != INT_MIN)
          ans = max(1 + dp[j], ans);

      dp[i] = ans;
    }

    return dp[0] < 0 ? -1 : dp[0];
  }
};