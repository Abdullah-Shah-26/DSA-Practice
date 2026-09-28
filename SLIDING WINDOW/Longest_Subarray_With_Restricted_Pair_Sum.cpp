#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubarray(vector<int> &nums) {
    int n = nums.size();

    int l = 0;
    int ans = 0;

    map<int, int> mp;

    auto isValid = [&](int x) {
      // x is result
      // a + b = x

      for (auto [a, cntA] : mp) {
        int b = x - a;

        if (mp.count(b)) {
          if (a == b) {
            // a and b both are same
            // They must be present at 2 different indices
            if (cntA >= 2)
              return false;
          } else {
            // a and b are different
            // And both exist along with x
            // So this is invalid subarray
            return false;
          }
        }
      }

      // Since all no's are >= 1
      // 0 + a = b is never possible so a == b is never possible
      // Implies a, b will be at distinct indices
      // And x is the incoming element

      // x + a = b
      for (auto [a, cntA] : mp) {
        int b = x + a;

        if (mp.count(b))
          return false;
      }

      return true;
    };

    for (int r = 0; r < n; r++) {

      // Can nums[r] enter this window
      while (!isValid(nums[r])) {
        mp[nums[l]]--;

        if (mp[nums[l]] == 0)
          mp.erase(nums[l]);

        l++;
      }

      // Adding nums[r] after, keeps only the old indices in map for cleaner
      // check cond'n
      mp[nums[r]]++;
      ans = max(ans, r - l + 1);
    }

    return ans;
  }
};