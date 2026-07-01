#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool check(int x, vector<int> &weights, int days) {
    int sum = 0;
    int cnt = 1;

    for (int i = 0; i < weights.size(); i++) {
      if (sum + weights[i] > x) {
        sum = weights[i];
        cnt++;
        continue;
      }
      sum += weights[i];
    }

    return cnt <= days;
  }

  int shipWithinDays(vector<int> &weights, int days) {
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 0);

    int ans = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;

      if (check(mid, weights, days)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }
};