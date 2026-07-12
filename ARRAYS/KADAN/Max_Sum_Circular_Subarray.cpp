#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int kadanMax(vector<int> &nums) {
    int maxi = nums[0];
    int cur = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      cur = max(nums[i], cur + nums[i]);
      maxi = max(maxi, cur);
    }

    return maxi;
  }

  int kadanMin(vector<int> &nums) {
    int mini = nums[0];
    int cur = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      cur = min(nums[i], cur + nums[i]);
      mini = min(mini, cur);
    }

    return mini;
  }

  int maxSubarraySumCircular(vector<int> &nums) {

    int totalSum = accumulate(begin(nums), end(nums), 0);
    int maxSum = kadanMax(nums);
    int minSum = kadanMin(nums);
    int maxCirSum = totalSum - minSum;

    if (maxSum > 0)
      return max(maxSum, maxCirSum);

    return maxSum;
  }
};