#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxArea(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    int maxi = 0; // Max possible side length for BS upper bound

    // dp[r][c] = largest valid square ending at (r, c)
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (mat[r][c] == 0)
          continue;

        if (r == 0 || c == 0) // Submatrix of size = 1
          dp[r][c] = 1;
        else {
          dp[r][c] = 1 + min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]});
        }

        maxi = max(maxi, dp[r][c]);
      }
    }

    vector<int> rowMax(m, 0);
    vector<int> colMax(n, 0);

    // rowMax[r] = largest sq that can be found
    // with its bottom row somewhere in rows [0 .. r]
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        rowMax[r] = max(rowMax[r], dp[r][c]);
      }

      if (r > 0)
        rowMax[r] = max(rowMax[r], rowMax[r - 1]);
    }

    // colMax[c] = largest sq that can be found
    // with its right col somewhere in cols [0 .. c]
    for (int c = 0; c < n; c++) {
      for (int r = 0; r < m; r++) {
        colMax[c] = max(colMax[c], dp[r][c]);
      }

      if (c > 0)
        colMax[c] = max(colMax[c], colMax[c - 1]);
    }

    auto can = [&](int k) {
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {

          // There is no k * k square ending at (r, c)
          if (dp[r][c] < k)
            continue;

          // Current square occupies ros [r-k+1 .. r]
          // So other square must end at row <= r - k
          if (r >= k && rowMax[r - k] >= k)
            return true;

          // Current square occupies col [c-k+1 .. c]
          // So other square must end at col <= c - k
          if (c >= k && colMax[c - k] >= k)
            return true;
        }
      }

      return false;
    };

    int low = 1, high = maxi;
    int ans = 0;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (can(mid)) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return ans * ans;
  }
};