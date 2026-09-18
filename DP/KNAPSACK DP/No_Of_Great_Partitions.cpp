#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

class Solution {
public:
  int f(int i, int target, int k, vector<int> &nums, vector<vector<int>> &dp) {
    if (target == 0)
      return 1;

    if (i == nums.size() || target < 0)
      return 0;

    if (dp[i][target] != -1)
      return dp[i][target];

    int take = 0;

    if (nums[i] <= target)
      take = f(i + 1, target - nums[i], k, nums, dp);

    int skip = f(i + 1, target, k, nums, dp);

    return dp[i][target] = (take + skip) % MOD;
  }

  int countPartitions(vector<int> &nums, int k) {
    int n = nums.size();

    ll total = 0;

    for (int x : nums)
      total += x;

    if (total < 2LL * k)
      return 0;

    ll totalSubsetCnt = 1;

    for (int i = 0; i < n; i++)
      totalSubsetCnt = (totalSubsetCnt * 2) % MOD;

    vector<vector<int>> dp(n, vector<int>(k, -1));

    ll invalid = 0;

    for (int target = 0; target < k; target++)
      invalid = (invalid + f(0, target, k, nums, dp)) % MOD;

    return (totalSubsetCnt - 2 * invalid + MOD) % MOD;
  }
};