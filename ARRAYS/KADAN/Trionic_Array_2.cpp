#include <bits/stdc++.h>
using namespace std;

// Can also be done using modified kadan

using ll = long long;
const ll LINF = 4e18;

class Solution {
public:
  int n;
  vector<vector<ll>> dp;

  ll solve(int i, int trend, vector<int> &nums) {
    if (i == n) {
      if (trend == 3) {
        return 0;
      } else {
        return -LINF;
      }
    }

    if (dp[i][trend] != LLONG_MIN)
      return dp[i][trend];

    ll take = -LINF;
    ll skip = -LINF;

    if (trend == 0) // Trend not started, can skip this as start point
      skip = solve(i + 1, trend, nums);

    if (trend == 3) // Last trend, end it here
      take = nums[i];

    if (i + 1 < n) {
      ll cur = nums[i];
      ll next = nums[i + 1];

      if (trend == 0 && next > cur)
        take = max(take, cur + solve(i + 1, 1, nums));
      else if (trend == 1) {
        if (next > cur)
          take = max(take, cur + solve(i + 1, 1, nums));
        else if (next < cur)
          take = max(take, cur + solve(i + 1, 2, nums));
      } else if (trend == 2) {
        if (next < cur)
          take = max(take, cur + solve(i + 1, 2, nums));
        else if (next > cur)
          take = max(take, cur + solve(i + 1, 3, nums));
      } else if (trend == 3 && next > cur)
        take = max(take, cur + solve(i + 1, 3, nums));
    }

    return dp[i][trend] = max(take, skip);
  }

  long long maxSumTrionic(vector<int> &nums) {
    n = nums.size();

    dp.resize(n + 1, vector<ll>(4, LLONG_MIN));

    return solve(0, 0, nums);
  }
};