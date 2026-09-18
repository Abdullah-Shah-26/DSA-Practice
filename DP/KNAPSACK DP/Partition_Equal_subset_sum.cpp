#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);

    if (total & 1) // Odd sum can never be split into 2 equal halfs
      return false;

    int target = total / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int t = 1; t <= target; t++) {

        bool take = false;
        if (t >= nums[i]) {
          take = dp[i + 1][t - nums[i]];
        }
        bool skip = dp[i + 1][t];

        dp[i][t] = (take || skip);
      }
    }

    return dp[0][target];
  }
};