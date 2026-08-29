#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int ans;

  void solve(int i, vector<int> &nums, unordered_map<int, int> &mp, int k) {
    if (i >= nums.size()) {
      ans++;
      return;
    }

    // Skip
    solve(i + 1, nums, mp, k);

    // Take
    if (!mp.count(nums[i] - k) && !mp.count(nums[i] + k)) {
      mp[nums[i]]++;             // Do
      solve(i + 1, nums, mp, k); // Explore
      mp[nums[i]]--;             // Undo

      if (mp[nums[i]] == 0)
        mp.erase(nums[i]);
    }
  }

  int beautifulSubsets(vector<int> &nums, int k) {
    ans = 0;

    unordered_map<int, int> mp;

    solve(0, nums, mp, k);

    return ans - 1; // Excluding empty subset
  }
};