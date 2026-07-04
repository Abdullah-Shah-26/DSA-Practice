#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int offset = 72;

/*
10 ^ 15 = 16 digits (0 - 15)
16 * 9 = 144

diff = oddsum - evensum

Odd = 9*8 = 72 (Largest diff)
Even = 0

Odd = 0
Even = 9*8 = 72  (diff = -72) [Smallest diff]

Range :  [-72 .. 72]

72 + 72 = 144
-72 + offset = 0 idx
*/

class Solution {
public:
  string s;

  // pos, cnt of non zero digits placed, diff, started, tight
  ll dp[17][17][145][2][2];

  // started = atleast one non 0 digit placed

  ll dfs(int pos, int cnt, int diff, bool started, bool tight) {
    if (pos == s.size())
      return started && cnt >= 2 && diff == 0;

    if (dp[pos][cnt][diff + offset][started][tight] != -1)
      return dp[pos][cnt][diff + offset][started][tight];

    int limit = tight ? s[pos] - '0' : 9;

    ll ans = 0;

    for (int d = 0; d <= limit; d++) {
      bool ntight = tight && (d == limit);

      if (!started && d == 0)
        ans += dfs(pos + 1, cnt, diff, false, ntight);
      else {
        int ndiff = diff;

        // cur digit placed
        // Now cnt = (cnt + 1)

        if ((cnt + 1) & 1)
          ndiff = diff + d; // cur digit is placed at odd pos
        else
          ndiff = diff - d; //                        even pos

        ans += dfs(pos + 1, cnt + 1, ndiff, true, ntight);
      }
    }

    return dp[pos][cnt][diff + offset][started][tight] = ans;
  }

  ll solve(ll n) {
    if (n <= 0)
      return 0;

    s = to_string(n);

    memset(dp, -1, sizeof(dp));

    return dfs(0, 0, 0, false, true);
  }

  long long countBalanced(long long low, long long high) {
    return solve(high) - solve((ll)low - 1);
  }
};