#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countLocalMaximums(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<vector<int>>> pref(
        201, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));

    for (int v = 1; v <= 200; v++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) //  Top + Left - OverLap + Current cell
          pref[v][i][j] = pref[v][i - 1][j] + pref[v][i][j - 1] -
                          pref[v][i - 1][j - 1] + (v == mat[i - 1][j - 1]);

    int ans = 0;

    for (int r = 0; r < n; r++) {
      for (int c = 0; c < m; c++) {

        int x = mat[r][c];

        if (x == 0)
          continue;

        bool flag = true;

        int r1 = max(0, r - x);
        int c1 = max(0, c - x);
        int r2 = min(n - 1, r + x);
        int c2 = min(m - 1, c + x);

        for (int v = x + 1; v <= 200; v++) {

          // No of cells with value exactly v
          int cnt = pref[v][r2 + 1][c2 + 1] - pref[v][r1][c2 + 1] -
                    pref[v][r2 + 1][c1] + pref[v][r1][c1];

          // No of ignored corners with value exactly v
          int ignored = 0;

          if (r - x >= 0 && c - x >= 0 && mat[r - x][c - x] == v)
            ignored++;
          if (r - x >= 0 && c + x < m && mat[r - x][c + x] == v)
            ignored++;
          if (r + x < n && c - x >= 0 && mat[r + x][c - x] == v)
            ignored++;
          if (r + x < n && c + x < m && mat[r + x][c + x] == v)
            ignored++;

          if (cnt - ignored > 0) {
            flag = false;
            break;
          }
        }

        if (flag)
          ans++;
      }
    }

    return ans;
  }
};