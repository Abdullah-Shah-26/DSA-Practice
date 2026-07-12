#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution {
public:
  int maxScore(vector<vector<int>> &grid) {
    int r = grid.size();
    int c = grid[0].size();

    int ans = -INF;

    // Max path intersection sum :

    // Kadan on all rows (len >= 2)
    for (int i = 0; i < r; i++) {
      int curSum = grid[i][0];
      int maxSum = -INF;

      for (int j = 1; j < c; j++) {
        maxSum = max(maxSum, curSum + grid[i][j]);
        curSum = max(grid[i][j], curSum + grid[i][j]);
      }

      ans = max(ans, maxSum);
    }

    // Kadan on all cols (len >= 2)
    for (int j = 0; j < c; j++) {
      int curSum = grid[0][j];
      int maxSum = -INF;

      for (int i = 1; i < r; i++) {
        maxSum = max(maxSum, curSum + grid[i][j]);
        curSum = max(grid[i][j], curSum + grid[i][j]);
      }

      ans = max(ans, maxSum);
    }

    // Exactly 1 cell is common among both - Edge case 
    for (int i = 1; i < r - 1; i++) {
      for (int j = 1; j < c - 1; j++) {
        ans = max(ans, grid[i][j]);
      }
    }

    return ans;
  }
};