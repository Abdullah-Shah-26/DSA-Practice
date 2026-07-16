#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubarrayLen(vector<int> &nums, int k) {
    int n = nums.size();
    int maxLen = 0;
    int l = 0;

    unordered_map<int, int> m;

    for (int r = 0; r < n; r++) {
      m[nums[r]]++;

      while (m[nums[l]] > k && l <= r) {
        m[nums[l]]--;
        l++;
      }

      maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
  }
};