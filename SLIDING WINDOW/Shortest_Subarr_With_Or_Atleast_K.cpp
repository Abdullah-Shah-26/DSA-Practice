#include <bits/stdc++.h>
using namespace std;

// TC = O(N * 32)

class Solution {
public:
  int cnt[32];
  int curOR = 0;

  void add(int x) {
    for (int b = 0; b < 32; b++) {
      if (x & (1 << b)) {
        cnt[b]++;
        curOR |= (1 << b);
      }
    }
  }

  void remove(int x) {
    for (int b = 0; b < 32; b++) {
      if (x & (1 << b)) {
        cnt[b]--;

        if (cnt[b] == 0) {
          curOR ^= (1 << b); // Clear this bit
        }
      }
    }
  }

  int minimumSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size();
    int ans = 1e9;
    int l = 0;

    for (int r = 0; r < n; r++) {
      add(nums[r]);

      while (l <= r && curOR >= k) {
        ans = min(ans, r - l + 1);
        remove(nums[l]);
        l++;
      }
    }

    return ans == 1e9 ? -1 : ans;
  }
};