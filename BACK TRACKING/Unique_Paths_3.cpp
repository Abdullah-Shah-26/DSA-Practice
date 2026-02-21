#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int,int>;
using ppi = pair<pair<int,int>, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;

const int INF = 1e9;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

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

