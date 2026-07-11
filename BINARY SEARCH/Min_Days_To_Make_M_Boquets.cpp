#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool check(int x, vector<int> &bloomDay, int m, int k) {
    int cnt = 0;
    int boq = 0;

    for (int i = 0; i < bloomDay.size(); i++) {

      if (x >= bloomDay[i]) {
        cnt++;
      } else {
        cnt = 0;
      }

      if (cnt == k) {
        cnt = 0;
        boq++;
      }
    }

    return boq >= m;
  }

  int minDays(vector<int> &bloomDay, int m, int k) {

    int l = 0, r = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;

    while (l <= r) {
      int mid = (l + r) >> 1;

      if (check(mid, bloomDay, m, k)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }
};