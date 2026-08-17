#include <bits/stdc++.h>
using namespace std;

// Tricky Grid Problem :

class Solution {
public:
  int minCost(vector<vector<int>> &grid, int k) {
    int r = grid.size();
    int c = grid[0].size();

    vector<vector<int>> dp(r, vector<int>(c, 1e9));
    dp[r - 1][c - 1] = 0;

    int maxi = 0;
    for (auto &row : grid)
      for (auto &val : row)
        maxi = max(maxi, val);

    // Teleportation depends on values of grid
    vector<int> teleCost(maxi + 1, 1e9); // Teleportation cost

    for (int t = 0; t <= k; t++) {
      for (int i = r - 1; i >= 0; i--) {
        for (int j = c - 1; j >= 0; j--) {

          if (i + 1 < r)
            dp[i][j] = min(dp[i][j], grid[i + 1][j] + dp[i + 1][j]);

          if (j + 1 < c)
            dp[i][j] = min(dp[i][j], grid[i][j + 1] + dp[i][j + 1]);

          // Reduction of dp cost via teleportation
          if (t > 0)
            dp[i][j] = min(dp[i][j], teleCost[grid[i][j]]);
        }
      }

      // Updating teleportation cost for next round
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          teleCost[grid[i][j]] = min(teleCost[grid[i][j]], dp[i][j]);
        }
      }

      // Prefix min of teleportation cost
      // Since we can reach larger values by teleporting to smaller values for
      // free
      for (int i = 1; i < teleCost.size(); i++)
        teleCost[i] = min(teleCost[i], teleCost[i - 1]);
    }

    return dp[0][0];
  }
};