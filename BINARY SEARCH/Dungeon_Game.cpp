#include <bits/stdc++.h>
using namespace std;

// Brute Force :
// TC = O(N * M * Log(1e4))

class Solution {
public:
  int n, m;
  vector<vector<int>> mat;
  vector<vector<int>> vis;

  bool dfs(int r, int c, int hp) {
    hp += mat[r][c]; // Process current cell

    // Died
    if (hp <= 0)
      return false;

    // Reached end
    if (r == n - 1 && c == m - 1)
      return true;

    // Alrady vis here with better hp
    if (vis[r][c] >= hp)
      return false;

    vis[r][c] = hp;

    bool down = false;
    bool right = false;

    if (r + 1 < n)
      down = dfs(r + 1, c, hp);

    if (c + 1 < m)
      right = dfs(r, c + 1, hp);

    return down || right;
  }

  bool check(int stHp) {
    vis.assign(n, vector<int>(m, false));
    return dfs(0, 0, stHp);
  }

  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    mat = dungeon;
    n = mat.size();
    m = mat[0].size();

    int l = 1;
    int r = 1e4;
    int ans = r;

    while (l <= r) {
      int mid = (l + r) >> 1;

      if (check(mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }
};