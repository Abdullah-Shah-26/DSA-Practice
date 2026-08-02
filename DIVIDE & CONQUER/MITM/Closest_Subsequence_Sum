#include <bits/stdc++.h>
using namespace std;

// TC = O(N1 * 2^N1 + N2 * 2^N2 + N1 * Log N2)
 
class Solution {
public:
  int minAbsDifference(vector<int> &nums, int goal) {
    int n = nums.size();

    int n1 = n / 2;
    int n2 = n - n1;

    vector<int> sum1(1 << n1);
    for (int mask = 0; mask < (1 << n1); mask++) {
      int s = 0;

      for (int i = 0; i < n1; i++) {
        if (mask & (1 << i))
          s += nums[i];
      }

      sum1[mask] = s;
    }

    vector<int> sum2(1 << n2);
    for (int mask = 0; mask < (1 << n2); mask++) {
      int s = 0;

      for (int i = 0; i < n2; i++) {
        if (mask & (1 << i))
          s += nums[n1 + i];
      }

      sum2[mask] = s;
    }

    sort(begin(sum2), end(sum2));

    int mini = INT_MAX; // abs(sum - goal)

    for (int s1 : sum1) {
      int need = goal - s1;
      int low = lower_bound(begin(sum2), end(sum2), need) - begin(sum2);

      if (low < sum2.size()) {
        int s2 = sum2[low];
        int total = s1 + s2;
        mini = min(mini, abs(total - goal));
      }

      if (low > 0) {
        int s2 = sum2[low - 1];
        int total = s1 + s2;
        mini = min(mini, abs(total - goal));
      }
    }

    return mini;
  }
};