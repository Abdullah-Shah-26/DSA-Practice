#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n, m;
  int dp[101][101][202];

  bool solve(int i, int j, int open, vector<vector<char>> &grid) {
    if (i == n - 1 && j == m - 1)
      return open == 0;

    if (open < 0)
      return false;

    if (dp[i][j][open] != -1)
      return dp[i][j][open];

    bool ans = false;

    if (i + 1 < n) {
      int newOpen = (grid[i + 1][j] == '(' ? open + 1 : open - 1);
      ans |= solve(i + 1, j, newOpen, grid);
    }

    if (j + 1 < m) {
      int newOpen = (grid[i][j + 1] == '(' ? open + 1 : open - 1);
      ans |= solve(i, j + 1, newOpen, grid);
    }

    return dp[i][j][open] = ans;
  }

  bool hasValidPath(vector<vector<char>> &grid) {
    n = grid.size();
    m = grid[0].size();

    // Edge case :
    // 1 cell with ')'
    if (n == 1 && m == 1)
      return false;

    int open = grid[0][0] == '(' ? 1 : 0;

    memset(dp, -1, sizeof(dp));

    return solve(0, 0, open, grid);
  }
};