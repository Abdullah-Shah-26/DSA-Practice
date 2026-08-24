#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Interval DP - Conventional Template
// TC = O(N^2)
// SC = O(N^2)

class Solution {
public:
  int countPS(string &s) {
    int n = s.size();
    long long dp[n][n];

    // Current Substring Length
    for (int len = 1; len <= n; len++) {
      // i = Starting idx
      for (int i = 0; i + len - 1 < n; i++) {
        // j = Ending idx
        int j = i + len - 1;

        if (len == 1) {
          dp[i][j] = 1;
        } else if (len == 2) {
          // aa = a,a,aa
          // ab = a,b
          dp[i][j] = (s[i] == s[j]) ? 3 : 2;
        } else {
          if (s[i] == s[j]) {
            // abc
            // a, b, c
            dp[i][j] = ((dp[i][j - 1] + dp[i + 1][j]) % MOD + 1) % MOD;
          } else {
            dp[i][j] =
                ((dp[i][j - 1] + dp[i + 1][j]) % MOD - dp[i + 1][j - 1] + MOD) %
                MOD;
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};