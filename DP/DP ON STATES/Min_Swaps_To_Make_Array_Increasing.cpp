#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n;
  int dp[100005][2];

  int solve(int i, int prevSwapped, vector<int> &nums1, vector<int> &nums2) {
    if (i == n)
      return 0;

    if (dp[i][prevSwapped] != -1)
      return dp[i][prevSwapped];

    int prev1 = nums1[i - 1];
    int prev2 = nums2[i - 1];

    if (prevSwapped)
      swap(prev1, prev2);

    int ans = INT_MAX;

    // Dont swap i
    if (prev1 < nums1[i] && prev2 < nums2[i])
      ans = min(ans, solve(i + 1, 0, nums1, nums2));

    // Swap i
    if (prev1 < nums2[i] && prev2 < nums1[i])
      ans = min(ans, 1 + solve(i + 1, 1, nums1, nums2));

    return dp[i][prevSwapped] = ans;
  }

  int minSwap(vector<int> &nums1, vector<int> &nums2) {
    n = nums1.size();

    memset(dp, -1, sizeof(dp));

    // At idx = 0
    int noSwap = solve(1, 0, nums1, nums2);
    int swapped = 1 + solve(1, 1, nums1, nums2);

    return min(noSwap, swapped);
  }
};