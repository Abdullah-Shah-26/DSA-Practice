#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // dp[i][j] = min hp needed before entering cell(i,j) so that we reach destination alive
    vector<vector<int>> dp(n, vector<int> (m));
    
    // Base Cases : 
    dp[n-1][m-1] = max(1, 1 - grid[n-1][m-1]); // 1-(-5) = 6

    // Fill last row & col
    for(int j = m-2; j >= 0; j--){
      int need = dp[n - 1][j + 1]; // To reach (n-1, j+1) from (n-1, j)
      dp[n-1][j] = max(1, need - grid[n-1][j]);
    }

    for(int i = n-2; i >= 0; i--){
      int need = dp[i + 1][m - 1]; // To reach (i+1, m-1) from (i, m-1)
      dp[i][m - 1] = max(1, need - grid[i][m-1]); 
    }

    for(int i = n-2; i >= 0; i--){
      for(int j = m-2; j >= 0; j--){

        // To reach (i,j) from {(i+1,j) or (i,j+1)} choose min need
        int need = min(dp[i + 1][j], dp[i][j + 1]);

        dp[i][j] = max(1, need - grid[i][j]);
      }
    }

    return dp[0][0];
  }
};