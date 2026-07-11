#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {

    if (x <= 1)
      return x;

    int l = 1, r = x;
    int ans = 0;

    while (l <= r) {

      int mid = l + (r - l) / 2;

      if (mid == x / mid) {
        return mid;
      }

      if (mid < x / mid) {
        ans = mid;   // mid*mid <= x
        l = mid + 1; // Try to find a larger valid square root
      } else {
        r = mid - 1; // mid*mid > x
      }
    }

    return ans;
  }
};