#include <bits/stdc++.h>
using namespace std;

// Non trivial state

class Solution {
public:
  int dp[1000005][2];

  int find(int st, int target, vector<int> &nums) {
    int j = lower_bound(begin(nums) + st, end(nums), target) - begin(nums);

    if (j < nums.size() && nums[j] == target)
      return j;

    return -1;
  }

  // Increment by 0/1
  int solve(int i, int inc, vector<int> &nums) {
    if (i >= nums.size())
      return 0;

    if (dp[i][inc] != -1)
      return dp[i][inc];

    int len = 1;
    int cur = nums[i] + inc;

    // Find (cur + 1)
    int j = find(i + 1, cur + 1, nums);

    if (j != -1) {
      len = max(len, 1 + solve(j, 0, nums));
    }

    // Find cur then increment by 1
    j = find(i + 1, cur, nums);

    if (j != -1) {
      len = max(len, 1 + solve(j, 1, nums));
    }

    return dp[i][inc] = len;
  }

  int maxSelectedElements(vector<int> &nums) {
    int n = nums.size();
    int ans = 1;

    // Need to sort for binary search to work
    sort(begin(nums), end(nums));

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
      ans = max({ans, solve(i, 0, nums), solve(i, 1, nums)});
    }

    return ans;
  }
};