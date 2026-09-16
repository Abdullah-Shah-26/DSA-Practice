#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n, m;
  int row[4] = {0, 0, -1, 1};
  int col[4] = {1, -1, 0, 0};

  vector<vector<int>> vis;
  vector<pair<int, int>> component;

  void dfs(int i, int j, vector<vector<int>> &grid, int originalColor) {
    if (i < 0 || i >= n || j < 0 || j >= m)
      return;

    if (grid[i][j] != originalColor || vis[i][j])
      return;

    vis[i][j] = true;
    component.push_back({i, j});

    for (int k = 0; k < 4; k++) {
      int ni = i + row[k];
      int nj = j + col[k];

      dfs(ni, nj, grid, originalColor);
    }
  }

  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r, int c,
                                  int color) {
    n = grid.size();
    m = grid[0].size();

    int originalColor = grid[r][c];

    vis.assign(n, vector<int>(m, false));
    component.clear();

    dfs(r, c, grid, originalColor);

    vector<pair<int, int>> border;

    for (auto [i, j] : component) {
      bool isBorder = false;

      if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
        isBorder = true;

      for (int k = 0; k < 4; k++) {
        int ni = i + row[k];
        int nj = j + col[k];

        if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
            grid[ni][nj] != originalColor)
          isBorder = true;
      }

      if (isBorder)
        border.push_back({i, j});
    }

    for (auto [i, j] : border)
      grid[i][j] = color;

    return grid;
  }
};