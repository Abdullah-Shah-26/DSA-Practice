#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> dp;
  bool f(int i, int j, string &s, string &p) {
    if (i == 0 && j == 0)
      return 1; // Both matched perfectly

    if (j == 0 && i > 0)
      return 0; // Pattern itself got exhausted

    if (i == 0 &&
        j > 0) { // String got exhausted but if Pattern has all * it can make up
      for (int k = 0; k < j; k++) {
        if (p[k] != '*')
          return 0;
      }
      return 1;
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
      return dp[i][j] = f(i - 1, j - 1, s, p);

    if (p[j - 1] == '*')
      return dp[i][j] = f(i - 1, j, s, p) || f(i, j - 1, s, p);
    // * consumed i - th char  || * as empty string

    return dp[i][j] = 0;
  }

  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    dp.assign(n + 1, vector<int>(m + 1, -1));

    return f(n, m, s, p);
  }
};

// Tabulation :

class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= m; j++) {
      bool allStars = true;
      for (int k = 0; k < j; k++) {
        if (p[k] != '*') {
          allStars = false;
          break;
        }
      }
      dp[0][j] = allStars;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
        }
      }
    }

    return dp[n][m];
  }
};

// Space Optimized

class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    vector<bool> prev(m + 1, false);

    prev[0] = true;

    for (int j = 1; j <= m; j++) { // O(M^2)
      bool allStars = true;
      for (int k = 0; k < j; k++) {
        if (p[k] != '*') {
          allStars = false;
          break;
        }
      }
      prev[j] = allStars;
    }

    for (int i = 1; i <= n; i++) {
      vector<bool> cur(m + 1, false);

      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
          cur[j] = prev[j - 1];
        } else if (p[j - 1] == '*') {
          cur[j] = (prev[j] || cur[j - 1]);
        }
      }

      prev = cur;
    }

    return prev[m];
  }
};

// Space Optimized

class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();

    vector<int> prev(m + 1, false);
    vector<int> cur(m + 1, false);

    prev[0] = true;

    for (int j = 1; j <= m; j++) { // O(M)
      prev[j] = prev[j - 1] && (p[j - 1] == '*');
    }

    for (int i = 1; i <= n; i++) {
      fill(cur.begin(), cur.end(), false);

      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
          cur[j] = prev[j - 1];
        } else if (p[j - 1] == '*') {
          cur[j] = (prev[j] || cur[j - 1]);
        }
      }

      prev = cur;
    }

    return prev[m];
  }
};