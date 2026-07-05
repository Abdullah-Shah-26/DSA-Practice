#include <bits/stdc++.h>
using namespace std;

// TC = O(N Log (Max - Min))

class Solution {
public:
  int n;
  bool can(int mid, vector<int> &nums, int p) {
    int cnt = 0;
    int i = 0;

    while (i + 1 < n) {
      if (abs(nums[i + 1] - nums[i]) <= mid) {
        i += 2;
        cnt++;
      } else {
        i++;
      }
    }

    return cnt >= p;
  }

  int minimizeMax(vector<int> &nums, int p) {
    n = nums.size();
    sort(begin(nums), end(nums));

    int l = 0, r = nums[n - 1] - nums[0];
    int ans = 1e9;

    while (l <= r) {
      int mid = (l + r) >> 1;
      if (can(mid, nums, p)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }
};

