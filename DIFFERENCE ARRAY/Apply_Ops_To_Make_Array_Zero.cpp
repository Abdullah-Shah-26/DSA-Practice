#include <bits/stdc++.h>
using namespace std;

// Difference Array :

class Solution {
public:
  bool checkArray(vector<int> &nums, int k) {
    int n = nums.size();

    vector<int> diff(n + 1, 0);

    int active = 0;

    for (int i = 0; i < n; i++) {

      // Operations that started earlier & affect i
      active += diff[i];

      // How much needed to make it 0
      int need = nums[i] - active;

      if (need < 0)
        return false;

      if (need == 0)
        continue;

      // Not enough elements to apply operation
      if (i + k > n)
        return false;

      // We must start need operations here
      active += need;

      // The affect of operations remains uptil (i + k - 1)
      diff[i + k] -= need;
    }

    return true;
  }
};