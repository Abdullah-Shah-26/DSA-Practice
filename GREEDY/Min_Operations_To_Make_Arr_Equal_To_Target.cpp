#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long minimumOperations(vector<int> &nums, vector<int> &target) {
    int n = nums.size();
    vector<int> diff(n);

    long long ans = 0;

    for (int i = 0; i < n; i++)
      diff[i] = target[i] - nums[i];

    int cur = 0;
    int prev = 0;

    for (int i = 0; i < n; i++) {
      int cur = diff[i];

      // If sign change -> solve those subarrays independently
      if ((cur < 0 && prev > 0) || (cur > 0 && prev < 0))
        ans += abs(cur);
      else if (abs(cur) > abs(prev))
        ans += abs(cur - prev);

      prev = cur;
    }

    return ans;
  }
};