#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  bool f(int i, vector<ll> &side, vector<int> &sticks, int target) {
    if (i == sticks.size())
      return true;

    int x = sticks[i];

    for (int j = 0; j < 4; j++) {
      if (side[j] + x > target)
        continue;

      if (j > 0 && side[j] == side[j - 1])
        continue;

      side[j] += x;

      if (f(i + 1, side, sticks, target))
        return true;

      side[j] -= x;
    }

    return false;
  }

  bool makesquare(vector<int> &sticks) {
    ll sum = accumulate(begin(sticks), end(sticks), 0LL);

    if (sum % 4 != 0)
      return false;

    ll sideLen = sum / 4;

    ll maxSideLen = *max_element(begin(sticks), end(sticks));

    if (maxSideLen > sideLen)
      return false;

    sort(sticks.begin(), sticks.end(), greater<int>());

    vector<ll> side(4, 0);

    return f(0, side, sticks, sideLen);
  }
};