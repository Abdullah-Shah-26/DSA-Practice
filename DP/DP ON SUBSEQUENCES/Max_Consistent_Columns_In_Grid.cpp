#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxConsistentColumns(vector<vector<int>> &grid, int limit) {
    int r = grid.size();
    int c = grid[0].size();

    vector<int> LIS(c, 1); // Should have atleast 1 column remaining
    // dp[j] = best sequence ending at column j

    for (int j = 1; j < c; j++) {
      for (int i = 0; i < j; i++) {
        bool valid = true;

        for (int row = 0; row < r; row++) { 
          if (abs(grid[row][j] - grid[row][i]) > limit) {
            valid = false;
            break;
          }
        }

        if (valid)
          LIS[j] = max(LIS[j], LIS[i] + 1);
      }
    }

    return *max_element(LIS.begin(), LIS.end());
  }
};