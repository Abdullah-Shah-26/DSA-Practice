#include <bits/stdc++.h>
using namespace std;

//! Interval DP

class Solution {
public:
  /*
  dp[l][r]={all results from every valid parenthesization of s[l..r]}

  It is literally all results of that sub-expression.
  */
  vector<int> diffWaysToCompute(string s) {
    int n = s.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));

    for (int i = 0; i < n; i++) {
      if (isdigit(s[i])) {
        int num = 0, j = i;
        while (j < n && isdigit(s[j])) {
          num = num * 10 + (s[j] - '0');
          j++;
        }
        dp[i][j - 1].push_back(num);
        i = j - 1;
      }
    }

    for (int len = 1; len <= n; len++) {
      for (int l = 0; l + len - 1 < n; l++) {
        // len = r - l + 1
        int r = l + len - 1;
        for (int k = l; k <= r; k++) {
          if (s[k] == '+' || s[k] == '-' || s[k] == '*') {

            for (int x : dp[l][k - 1]) {
              for (int y : dp[k + 1][r]) {
                if (s[k] == '+')
                  dp[l][r].push_back(x + y);
                else if (s[k] == '-')
                  dp[l][r].push_back(x - y);
                else
                  dp[l][r].push_back(x * y);
              }
            }
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};
