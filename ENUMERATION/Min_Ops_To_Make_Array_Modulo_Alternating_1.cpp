#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    int n = nums.size();

    for (int i = 0; i < n; i++)
      nums[i] %= k;

    int ans = 1e9;

    for (int x = 0; x < k; x++) {
      for (int y = 0; y < k; y++) {
        if (x == y)
          continue;

        int ops = 0;

        for (int i = 0; i < n; i += 2) { // For odd indices (1-based)
          int direct = abs(nums[i] - x); // Go directly to x
          int wrap = k - direct;         // Go the other way around the circle
          ops += min(direct, wrap);
        }

        for (int i = 1; i < n; i += 2) {
          int direct = abs(nums[i] - y); // Go directly to y
          int wrap = k - direct;         // Wrap around
          ops += min(direct, wrap);
        }

        ans = min(ans, ops);
      }
    }

    return ans;
  }
};