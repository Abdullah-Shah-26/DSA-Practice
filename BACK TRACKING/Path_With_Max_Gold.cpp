  // TC = (4 ^ (m*n))
  class Solution
  {
  public:
    int maxi = 0;
    int n, m;
    int row[4] = {0, 0, -1, 1};
    int col[4] = {1, -1, 0, 0};

    void solve(int i, int j, int pathSum, vector<vector<int>> &grid)
    {
      if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
        return;

      // int pathSum = 0;
      int temp = grid[i][j];
      grid[i][j] = 0;
      pathSum += temp;
      maxi = max(maxi, pathSum);
      for (int k = 0; k < 4; k++)
      {
        int nr = i + row[k];
        int nc = j + col[k];
        solve(nr, nc, pathSum, grid);
      }
      grid[i][j] = temp;
      pathSum -= temp;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
      n = grid.size();
      m = grid[0].size();
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          if (grid[i][j] != 0)
          {
            solve(i, j, 0, grid);
          }
        }
      }
      return maxi;
    }
  };

