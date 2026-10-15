#include <bits/stdc++.h>
using namespace std;

// Finite state dp

using ll = long long;
const ll INF = 4e18;

class Solution {
public:
  long long maxSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();

    vector<vector<ll>> dp(n, vector<ll>(3, -INF));

    // dp[i][0] = max subarr sum upto i with no tranforms
    // dp[i][1] = max subarr sum upto i using transforms
    // dp[i][2] = max subarr sum upto i, before this chunk we ended transforms

    // Multiplication
    dp[0][0] = nums[0];
    dp[0][1] = 1LL * nums[0] * k;

    for (int i = 1; i < n; i++) {
      dp[i][0] = max(0LL, dp[i - 1][0]) + nums[i];
      dp[i][1] = max({0LL, dp[i - 1][0], dp[i - 1][1]}) + 1LL * nums[i] * k;
      dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + nums[i];
    }

    ll ans = -INF;
    for (auto &d : dp)
      ans = max({ans, d[0], d[1], d[2]});

    dp.assign(n, vector<ll>(3, -INF));

    // Division
    dp[0][0] = nums[0];
    dp[0][1] = nums[0] / k;

    for (int i = 1; i < n; i++) {
      dp[i][0] = max(0LL, dp[i - 1][0]) + nums[i];
      dp[i][1] = max({0LL, dp[i - 1][0], dp[i - 1][1]}) + nums[i] / k;
      dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + nums[i];
    }

    for (auto &d : dp)
      ans = max({ans, d[0], d[1], d[2]});

    return ans;
  }
};