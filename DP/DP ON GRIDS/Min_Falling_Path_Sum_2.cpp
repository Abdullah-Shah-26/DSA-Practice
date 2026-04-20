#include <bits/stdc++.h>
using namespace std;

//! Rec + Memo

class Solution {
  public:
    int n;
    const int INF = 1e9;
    
    int f(int i, int prevCol, vector<vector<int>> &grid, vector<vector<int>> &dp){
      if(i == n) return 0; // Path complete, no cost to add

      if(dp[i][prevCol + 1] != -1)
        return dp[i][prevCol + 1];

      int minCost = INF;

      for(int j = 0; j < n; j++){
        if(j == prevCol) continue;

        int cost = grid[i][j] + f(i + 1, j, grid, dp);
        minCost = min(minCost, cost);
      }

      return dp[i][prevCol + 1] = minCost;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
    n = grid.size();
    vector<vector<int>> dp(n, vector<int> (n + 1, -1));

    return f(0, -1, grid, dp);
    }
};

//! BottomUp

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    if(n == 1) return grid[0][0];
    int INF = 1e9;

    vector<vector<int>> dp(n, vector<int>(n, INF)); 
    // dp[i][j] = minCost to reach (i,j)

    for(int j = 0; j < n; j++)
      dp[0][j] = grid[0][j];

    for(int i = 1; i < n; i++){
      for(int j = 0; j < n; j++){

        dp[i][j] = INF;

        for(int k = 0; k < n; k++){
          if(k == j) continue;

          dp[i][j] = min(dp[i][j], grid[i][j] + dp[i-1][k]);
        }
      }
    }

    return *min_element(dp[n-1].begin(), dp[n-1].end());
  }
};

//! Space Optimized

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    if(n == 1) return grid[0][0];
    int INF = 1e9;

    vector<int> prev(n, INF); 

    for(int j = 0; j < n; j++)
      prev[j] = grid[0][j];

    for(int i = 1; i < n; i++){
      vector<int> cur(n, INF);
     
      for(int j = 0; j < n; j++){

        cur[j] = INF;

        for(int k = 0; k < n; k++){
          if(k == j) continue;

          cur[j] = min(cur[j], grid[i][j] + prev[k]);
        }
      }

      prev = cur;
    }

    return *min_element(prev.begin(), prev.end());
  }
};