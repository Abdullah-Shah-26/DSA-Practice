#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static const int MOD = 1e9 + 7;
  int numberOfPaths(vector<vector<int>>& grid, int k) {
  int n = grid.size();
  int m = grid[0].size();

  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (k + 1, 0)));

  for(int r = 0; r <= k; r++){
    dp[n-1][m-1][r] = ((r + grid[n-1][m-1]) % k == 0);
  }

  for(int i = n-1; i >= 0; i--){
    for(int j = m-1; j >= 0; j--){
      for(int r = 0; r <= k; r++){
        if(i == n-1 && j == m-1)
        continue;

        int rem = (r + grid[i][j]) % k;
        int down = dp[i + 1][j][rem];
        int right = dp[i][j + 1][rem];

        dp[i][j][r] = (down + right) % MOD;
      }
    }
  }

  return dp[0][0][0];
  }
};