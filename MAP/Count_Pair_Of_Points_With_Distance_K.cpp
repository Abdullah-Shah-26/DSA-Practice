#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Using custom key, left shift by 20 since co-ordinates < 2^20
// x1 ^ x2 + y1 ^ y2 == k
// y1 ^ y2 = k - (x1 ^ x2)
// dy = k - dx

class Solution {
public:
  int countPairs(vector<vector<int>> &c, int k) {
    int n = c.size();

    int ans = 0;

    unordered_map<ll, int> mp;

    for (auto &p : c) {
      int x = p[0];
      int y = p[1];

      for (int dx = 0; dx <= k; dx++) {
        int dy = k - dx;

        int needX = x ^ dx;
        int needY = y ^ dy;

        ll key = ((long long)needX << 20) | needY;

        ans += mp[key];
      }

      ll key = ((long long)x << 20) | y;
      mp[key]++;
    }

    return ans;
  }
};