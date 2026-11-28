#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumMountainRemovals(vector<int> &nums) {
    int n = nums.size();

    // Longest increasing subsequence
    vector<int> LIS(n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          LIS[i] = max(LIS[i], LIS[j] + 1);
        }
      }
    }

    // Longest decreasing subsequence
    vector<int> LDS(n, 1);

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j > i; j--) {
        if (nums[j] < nums[i]) {
          LDS[i] = max(LDS[i], LDS[j] + 1);
        }
      }
    }

    // A valid peak idx must have atleast one element on left & atleast one on
    // right

    int mx = 0;
    for (int i = 1; i < n - 1; i++) {
      if (LIS[i] > 1 && LDS[i] > 1) {
        mx = max(mx, LIS[i] + LDS[i] - 1);
      }
    }

    return n - mx;
  }
};