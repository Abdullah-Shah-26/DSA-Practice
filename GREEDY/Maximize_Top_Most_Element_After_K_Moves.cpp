#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumTop(vector<int> &a, int k) {
    int n = a.size();

    if (n == 1) {
      if (k & 1)
        return -1;

      return a[0];
    }

    if (k <= n) {
      int maxi = -1;

      for (int i = 0; i < k - 1; i++) {
        maxi = max(maxi, a[i]);
      }

      if (k < n)
        maxi = max(maxi, a[k]);

      return maxi;
    }

    return *max_element(begin(a), end(a));
  }
};