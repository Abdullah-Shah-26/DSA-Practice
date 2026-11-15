#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

class Solution {
public:
  // To prevent product overflow
  // log(a * b) = log(a) + log(b)
  int maxLength(vector<int> &nums) {
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
      long double prod = log(nums[i]);
      ll g = nums[i];
      ll l = nums[i];

      for (int j = i + 1; j < n; j++) {
        prod += log(nums[j]);
        g = gcd(g, (ll)nums[j]);
        l = lcm(l, (ll)nums[j]);

        // Given : prod == lcm * gcd
        // prod - lcm * gcd == 0
        // log(prod) - log(lcm * gcd) == 0
        // log(prod of all) - (log(l) + log(g))
        // Since we are using floating points, we are checking if fabs is almost
        // 0 or negligible
        if (fabs(prod - (log(l) + log(g))) < 1e-9)
          maxLen = max(maxLen, j - i + 1);
      }

      maxLen = max(maxLen, 1);
    }

    return maxLen;
  }
};