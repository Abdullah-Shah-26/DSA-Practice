#include <bits/stdc++.h>
using namespace std;

// TWO POINTERS (Sorted Array)
// TC = O(n) | SC = O(1)

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      int sum = nums[left] + nums[right];

      if (sum == target)
        return {left, right};

      if (sum < target)
        left++;
      else
        right--;
    }

    return {};
  }
};