#include <bits/stdc++.h>
using namespace std;

// Bottom Up

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();  

  if(grid[0][0] == 1) return 0;

  vector<vector<int>> dp(n, vector<int>(m, 0));
  dp[0][0] = 1;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){

      // Obstacle
      if(grid[i][j] == 1){
        dp[i][j] = 0;
        continue;
      }

      // Skip st cell
      if(i == 0 && j == 0) continue;

      int up = 0;
      int left = 0;

      if(i > 0) up = dp[i-1][j];
      if(j > 0) left = dp[i][j-1];

      dp[i][j] = up + left;
    }
  }

  return dp[n-1][m-1];
  }
};


// Space Optimized

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if(grid[0][0] == 1) return 0;

    vector<int> prev(m, 0);
    prev[0] = 1;

    for(int i = 0; i < n; i++) {
      vector<int> cur(m, 0);

      for(int j = 0; j < m; j++) {

        if(grid[i][j] == 1) { // Obstacle
          cur[j] = 0;
          continue;
        }

        if(i == 0 && j == 0){ // Start Point
          cur[0] = 1; // 1 - Way to reach it always
          continue;
        }

        int up = (i > 0) ? prev[j] : 0;
        int left = (j > 0) ? cur[j - 1] : 0;

        cur[j] = up + left;
      }

      prev = cur;
    }

    return prev[m - 1];
  }
};