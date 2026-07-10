#include <bits/stdc++.h>
using namespace std;

// Rec + Memo

class Solution {
public:
  int dp[21][21];
  bool f(int i, int j, string s, string p) {
    if (j == p.size()) { // Pattern exhausted, string should also exhaust
      return i == s.size();
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    bool firstCharMatched = false;

    if (i < s.size())
      firstCharMatched = ((p[j] == s[i]) || (p[j] == '.'));

    if (p[j + 1] == '*') {
      bool skip = f(i, j + 2, s, p);
      bool take = firstCharMatched && f(i + 1, j, s, p);

      return dp[i][j] = take || skip;
    }

    return dp[i][j] = firstCharMatched && f(i + 1, j + 1, s, p);
  }

  bool isMatch(string s, string p) {
    memset(dp, -1, sizeof(dp));
    return f(0, 0, s, p);
  }
};

// Tabulation :

class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 2, false));

    dp[n][m] = true;

    for (int i = n; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {

        bool firstChMatch = (i < n && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < m && p[j + 1] == '*') {
          bool skip = dp[i][j + 2];
          bool take = firstChMatch && dp[i + 1][j];

          dp[i][j] = take || skip;
        } else {
          dp[i][j] = firstChMatch && dp[i + 1][j + 1];
        }
      }
    }

    return dp[0][0];
  }
};