#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxAbsoluteSum(vector<int> &nums) {
    int n = nums.size();

    int maxSum = nums[0];
    int minSum = nums[0];
    int curSumMax = nums[0];
    int curSumMin = nums[0];

    for (int i = 1; i < n; i++) {
      curSumMax = max(nums[i], curSumMax + nums[i]);
      curSumMin = min(nums[i], curSumMin + nums[i]);

      maxSum = max(maxSum, curSumMax);
      minSum = min(minSum, curSumMin);
    }

    return max(maxSum, abs(minSum));
  }
};