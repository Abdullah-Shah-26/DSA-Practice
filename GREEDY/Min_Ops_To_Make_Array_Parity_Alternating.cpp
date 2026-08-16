#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LINF = 4e18;

// Tricky Problem : 

class Solution {
public:
  vector<int> makeParityAlternating(vector<int> &nums) {
    int n = nums.size();

    if (n == 1)
      return {0, 0};

    // 2 Patterns :
    // 010101
    // 101010

    ll cost0 = 0, cost1 = 0;

    for (int i = 0; i < n; i++) {
      if ((nums[i] & 1) != (i & 1))
        cost0++;
      if ((nums[i] & 1) != ((i + 1) & 1))
        cost1++;
    }

    ll minCost = min(cost0, cost1);
    ll bestRange = LLONG_MAX;

    for (int t = 0; t < 2; t++) {
      ll cost = 0;

      if (t == 0) // 010101
        cost = cost0;
      else if (t == 1) // 101010
        cost = cost1;

      if (cost != minCost)
        continue;

      ll maxi = -LINF, mini = LINF;

      vector<int>
          change; // Need parity adjustment, doens't follow their target parity

      for (int i = 0; i < n; i++) {
        ll x = nums[i];

        int targetParity;

        if (t == 0)
          targetParity = (i & 1);
        else
          targetParity = ((i + 1) & 1);

        if ((x & 1) == targetParity) {
          mini = min(mini, x);
          maxi = max(maxi, x);
        } else {
          change.push_back(x);
        }
      }

      if (!change.empty()) {
        int m = change.size();

        if (m == 1) {
          ll x = change[0];

          for (auto add : {-1, 1}) {
            bestRange = min(bestRange, max(maxi, x + add) - min(mini, x + add));
          }
        } else {
          sort(change.begin(), change.end());

          ll x = change[0], y = change[m - 1];

          for (auto dx : {-1, 1}) {
            for (auto dy : {-1, 1}) {
              bestRange = min(bestRange, max({maxi, x + dx, y + dy}) -
                                             min({mini, x + dx, y + dy}));
            }
          }
        }
      } else {
        bestRange = min(bestRange, maxi - mini);
      }
    }

    return {(int)minCost, (int)bestRange};
  }
};