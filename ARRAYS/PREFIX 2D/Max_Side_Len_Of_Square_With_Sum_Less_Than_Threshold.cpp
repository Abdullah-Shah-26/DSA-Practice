#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int getSum(int r1, int c1, int r2, int c2, vector<vector<int>> &pref) {
    return pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] +
           pref[r1 - 1][c1 - 1];
  }

  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];

    int ans = 0, l = 1, r = min(n, m);

    while (l <= r) {
      int mid = l + (r - l) / 2;

      bool find = false;

      for (int i = 1; i <= n - mid + 1; i++) {
        for (int j = 1; j <= m - mid + 1; j++) {
          if (getSum(i, j, i + mid - 1, j + mid - 1, pref) <= threshold) {
            find = true;
            break;
          }
        }

        if (find)
          break;
      }

      if (find) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return ans;
  }
};