#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {

    int left = 0;
    int right = nums.size() - 1;

    // If target is larger than every element,
    // insert it at the end.
    int ans = nums.size();

    while (left <= right) {

      int mid = left + (right - left) / 2;

      if (nums[mid] >= target) {
        ans = mid;  
        right = mid - 1; // Look for an earlier position
      } else {
        left = mid + 1; // Target must be on the right
      }
    }

    return ans;
  }
};