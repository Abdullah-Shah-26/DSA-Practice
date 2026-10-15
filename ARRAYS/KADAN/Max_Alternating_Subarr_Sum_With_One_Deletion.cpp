#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LINF = 4e18;
const ll sentinel = LLONG_MIN;

class Solution {
public:
  int n;
  ll dp[100005][2][2];

  ll solve(int i, bool parity, bool deleted, vector<int> &nums) {

    if (i >= n)
      return -LINF;

    if (dp[i][parity][deleted] != sentinel)
      return dp[i][parity][deleted];

    ll value = (parity == 0) ? nums[i] : -nums[i];

    // Start a new subarray
    ll ans = value;

    // Take the current element (i.e extend the subarray), for next idx parity
    // changes
    ans = max(ans, value + solve(i + 1, parity ^ 1, deleted, nums));

    // Delete the current element, parity remains same since all elements
    // shifted
    if (!deleted)
      ans = max(ans, solve(i + 1, parity, 1, nums));

    return dp[i][parity][deleted] = ans;
  }

  long long maxAlternatingSum(vector<int> &nums) {
    ll ans = -LINF;

    n = nums.size();

    for (int i = 0; i < 100005; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)
          dp[i][j][k] = sentinel;

    // Try every valid start
    for (int i = 0; i < n; i++)
      ans = max(ans, solve(i, 0, 0, nums));

    return ans;
  }
};