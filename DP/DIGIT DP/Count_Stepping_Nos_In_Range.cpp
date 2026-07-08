#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  string num;
  ll dp[100][11][2][2];

  ll dfs(int i, int prev, int tight, int lz) {
    if (i == num.size())
      return !lz; // Built valid +ve no

    if (dp[i][prev][tight][lz] != -1)
      return dp[i][prev][tight][lz];

    ll limit = tight ? num[i] - '0' : 9;
    ll ans = 0;

    for (int d = 0; d <= limit; d++) {
      int newT = tight && (d == limit);

      if (lz) {
        // Leading zeros are continued, invalid prev
        if (d == 0)
          ans = (ans + dfs(i + 1, 10, newT, 1)) % MOD;
        else // First non zero digit placed, no need to check adj difference 1st
             // time
          ans = (ans + dfs(i + 1, d, newT, 0)) % MOD;
      } else {
        // Adjacent digit diff == 1
        if (abs(d - prev) == 1)
          ans = (ans + dfs(i + 1, d, newT, 0)) % MOD;
      }
    }

    return dp[i][prev][tight][lz] = ans;
  }

  // No is of 100 digits, can't do stoi() or stoll()
  string subtractOne(string s) {
    int i = s.size() - 1;

    while (s[i] == '0') { // Ex : 1000
      s[i] = '9';
      i--;
    }

    // 1999
    s[i]--; // Non-zero digit, decrement normally

    // 0999
    int pos = 0; // Remove Leading zeros, don't erase last zero
    while (pos + 1 < s.size() && s[pos] == '0')
      pos++;

    return s.substr(pos);
  }

  ll solve(string s) {
    num = s;
    memset(dp, -1, sizeof(dp));
    return dfs(0, 10, 1, 1);
  }

  int countSteppingNumbers(string low, string high) {
    int highCnt = solve(high);

    int lowCnt = 0;
    if (low != "1") {
      string lowMinusOne = subtractOne(low);
      lowCnt = solve(lowMinusOne);
    }

    return (highCnt - lowCnt + MOD) % MOD;
  }
};