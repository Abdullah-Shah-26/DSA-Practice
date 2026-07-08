#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  int countTrapezoids(vector<vector<int>> &points) {
    unordered_map<int, int> m;

    for (auto &it : points) {
      int y = it[1];
      m[y]++; // Cnt of points with same y - cordinate
    }

    ll ans = 0;
    ll pastPairs = 0; // No of possible horizontal segments that can be formed
                      // from all prev processed y - levels

    for (auto &[y, cnt] : m) {
      ll pairs = (1LL * cnt * (cnt - 1) / 2) % MOD;
      ans = (ans + (pairs * pastPairs) % MOD) % MOD;
      pastPairs += pairs;
    }

    return (int)ans;
  }
};

