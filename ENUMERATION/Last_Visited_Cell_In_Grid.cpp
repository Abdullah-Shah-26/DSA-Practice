#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  //            R  L  U  D
  int row[4] = {0, 0, -1, 1};
  int col[4] = {1, -1, 0, 0};

  int n, m;
  vector<vector<int>> vis;

  bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j];
  }

  vector<int> lastVisitedCell(vector<vector<char>> &grid) {
    n = grid.size();
    m = grid[0].size();

    vis.assign(n, vector<int>(m, false));

    int r = 0, c = 0;
    vis[r][c] = 1;

    int lr = r, lc = c;
    bool valid = true;

    while (1) {
      char ch = grid[r][c];

      int d;
      if (ch == 'R')
        d = 0;
      else if (ch == 'L')
        d = 1;
      else if (ch == 'U')
        d = 2;
      else
        d = 3;

      int nr = r + row[d];
      int nc = c + col[d];

      if (!isValid(nr, nc)) {
        break;
      }

      r = nr, c = nc;
      vis[nr][nc] = 1;
      lr = nr, lc = nc;
    }

    return {lr, lc};
  }
};