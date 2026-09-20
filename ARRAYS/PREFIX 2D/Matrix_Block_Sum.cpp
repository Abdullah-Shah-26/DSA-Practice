#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
    int r = mat.size();
    int c = mat[0].size();

    // 2D Prefix sum
    int dp[r + 1][c + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        dp[i][j] =
            mat[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
      }
    }

    vector<vector<int>> res(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        int r1 = max(0, i - k);
        int c1 = max(0, j - k);
        int r2 = min(r - 1, i + k);
        int c2 = min(c - 1, j + k);

        r1++;
        r2++;
        c1++;
        c2++;

        res[i][j] = dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
      }
    }

    return res;
  }
};