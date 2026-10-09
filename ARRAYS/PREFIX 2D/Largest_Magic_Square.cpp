#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(vector<vector<int>> &grid, int i, int j, int k) {
    int sum = 0;

    for (int x = i; x < i + k; x++) {
      int s = 0;

      for (int y = j; y < j + k; y++)
        s += grid[x][y];

      // This is what sum is supposed to be for every row, col diagonal, save it
      if (x == i)
        sum = s;
      // If others don't have same sum, this can't be magic square
      else if (sum != s)
        return false;
    }

    for (int y = j; y < j + k; y++) {
      int s = 0;

      for (int x = i; x < i + k; x++)
        s += grid[x][y];

      if (s != sum)
        return false;
    }

    int s = 0;
    for (int d = 0; d < k; d++)
      s += grid[i + d][j + d];

    if (sum != s)
      return false;

    s = 0;
    for (int d = 0; d < k; d++)
      s += grid[i + d][j + k - d - 1];

    if (sum != s)
      return false;

    return true;
  }

  int largestMagicSquare(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    for (int k = min(m, n); k >= 2; k--) {
      for (int i = 0; i + k - 1 < n; i++) {
        for (int j = 0; j + k - 1 < m; j++) {
          if (isValid(grid, i, j, k))
            return k;
        }
      }
    }

    return 1;
  }
};