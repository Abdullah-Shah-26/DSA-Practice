#include <bits/stdc++.h>
using namespace std;

// TC: O(log N)
// SC: O(1)

class Solution {
public:
  int cubeRoot(int n) {

    if (n <= 1)
      return n;

    int l = 1;
    int r = n;
    int ans = 0;

    while (l <= r) {

      int mid = l + (r - l) / 2;

      long long cube = 1LL * mid * mid * mid;

      if (cube <= n) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return ans;
  }
};