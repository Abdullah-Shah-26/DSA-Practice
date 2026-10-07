#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

class Solution {
public:
  int numWays(string s) {
    int n = s.size();

    int ones = 0;

    for (char &ch : s)
      ones += (ch - '0');

    if (ones == 0) {
      ll x = n - 1;
      return (x * (x - 1) / 2) % MOD;
    }

    if (ones % 3 != 0)
      return 0;

    int oneThird = ones / 3;
    int twoThird = 2 * oneThird;

    ll ways1 = 0;
    ll ways2 = 0;

    ones = 0;
    for (char &ch : s) {
      ones += ch - '0';

      if (ones == oneThird)
        ways1++;

      if (ones == twoThird)
        ways2++;
    }

    return (ways1 * ways2) % MOD;
  }
};