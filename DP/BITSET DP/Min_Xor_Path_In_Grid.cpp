#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCost(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bitset<1024>>> dp(n, vector<bitset<1024>>(m));

    // dp[i][j] = stores bitset<1024>
    //          = [0,0,0, ........   0]
    // idx      =  0,1,2           1023

    dp[0][0][grid[0][0]] = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {

        if (i == 0 && j == 0)
          continue;

        bitset<1024> up;
        bitset<1024> left;

        if (i > 0)
          up = dp[i - 1][j];

        if (j > 0)
          left = dp[i][j - 1];

        bitset<1024> combined = up | left;

        for (int xorVal = 0; xorVal < 1024; xorVal++) {
          if (combined[xorVal]) {
            int resXor = grid[i][j] ^ xorVal;
            dp[i][j][resXor] = 1;
          }
        }
      }
    }

    for (int xorVal = 0; xorVal < 1024; xorVal++)
      if (dp[n - 1][m - 1][xorVal])
        return xorVal;

    return -1;
  }
};