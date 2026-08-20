#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    int n = nums.size();

    int maxi = 0;

    unordered_map<int, int> mp;

    int l = 0, sum = 0;
    for (int r = 0; r < n; r++) {
      mp[nums[r]]++;
      sum += nums[r];

      while (mp[nums[r]] > 1) {
        sum -= nums[l];
        mp[nums[l]]--;
        l++;
      }

      maxi = max(maxi, sum);
    }

    return maxi;
  }
};