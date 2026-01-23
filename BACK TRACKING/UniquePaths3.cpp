class Solution {
public:
    int n, m;
    int row[4] = {0, 0, 1, -1};
    int col[4] = {1, -1, 0, 0};
    int res = 0;
    int total = 0;

    void solve(int i, int j, vector<vector<int>>& grid, int vis) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1)
            return;

        if (grid[i][j] == 2 && vis == total) {
            res++;
            return;
        }

        int old = grid[i][j];
        grid[i][j] = -1;

        for (int k = 0; k < 4; k++) {
            solve(i + row[k], j + col[k], grid, vis + 1);
        }

        grid[i][j] = old;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int stI = -1, stJ = -1;
        total = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1)
                    total++; // count all walkable cells
                if (grid[i][j] == 1)
                    stI = i, stJ = j;
            }
        }
        solve(stI, stJ, grid, 1);
        return res;
    }
};