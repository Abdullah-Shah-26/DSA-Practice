#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int r, c;
  int dp[51][51];
 
  // f(r, c) = min additional cost to go from (r,c) to the last row, assuming the value of (r,c) has already been paid.
  int f(int r, int c, vector<vector<int>> &moveCost, vector<vector<int>> &grid){
    if(r + 1 == grid.size()) 
      return 0; 

    int &ans = dp[r][c];
    if(ans != -1) return ans;

    ans = 1e9;
    for(int nxtC = 0; nxtC < grid[0].size(); nxtC++){
      int cost = grid[r + 1][nxtC] + moveCost[grid[r][c]][nxtC];
      ans = min(ans, cost + f(r + 1, nxtC, moveCost, grid));
    }

    return ans;
  }

  int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
  // moveCost[grid[r][c]][nextCol]    
  r = grid.size();
  c = grid[0].size();

  memset(dp, -1, sizeof(dp));

  int ans = 1e9;
  for(int j = 0; j < c; j++) // Initally choose the col with minVal
    ans = min(ans, grid[0][j] + f(0, j, moveCost, grid)); 

  return ans;
  }
};