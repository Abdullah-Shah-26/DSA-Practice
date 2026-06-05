#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static const int MOD = 1e9 + 7;

  int numberOfPaths(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();

    // dp[i][j][rem] = number of paths from (0,0) -> (i,j)
    // whose path sum % k == rem
    vector dp(n,vector(m,vector<int>(k, 0)));

    dp[0][0][grid[0][0] % k] = 1;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {

        if(i == 0 && j == 0)
          continue;

        for(int oldRem = 0; oldRem < k; oldRem++) {

          int newRem = (oldRem + grid[i][j]) % k;

          if(i > 0) {
            dp[i][j][newRem] =
              (dp[i][j][newRem] + dp[i - 1][j][oldRem]) % MOD;
          }

          if(j > 0) {
            dp[i][j][newRem] =
              (dp[i][j][newRem] + dp[i][j - 1][oldRem]) % MOD;
          }
        }
      }
    }

    return dp[n - 1][m - 1][0];
  }
};