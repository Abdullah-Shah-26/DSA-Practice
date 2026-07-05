#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

class Solution {
public:
  int n;
  int row[3] = {0, 1, 1};
  int col[3] = {1, 0, 1};
  int dp[101][101];
  int ways[101][101];

  pair<int, int> f(int i, int j, vector<string> &grid) {
    if (i >= n || j >= n)
      return {-INF, 0};

    if (grid[i][j] == 'X')
      return {-INF, 0};

    if (i == n - 1 && j == n - 1)
      return {0, 1}; // 0 cause we dont cnt 'S' & 1 cause we found 1 way

    if (dp[i][j] != -1)
      return {dp[i][j], ways[i][j]};

    int maxSum = -INF;
    int totalWays = 0;

    for (int k = 0; k < 3; k++) {
      int ni = i + row[k];
      int nj = j + col[k];

      if (ni < n && nj < n && grid[ni][nj] != 'X') {
        auto [sum, ways] = f(ni, nj, grid);

        if (sum > maxSum) {
          maxSum = sum;
          totalWays = ways;
        } else if (sum == maxSum) {
          totalWays = (totalWays + ways) % MOD;
        }
      }
    }

    if (maxSum == -INF) { // Cache
      dp[i][j] = -INF;
      ways[i][j] = 0;
      return {dp[i][j], ways[i][j]};
    }

    if (grid[i][j] >= '1' && grid[i][j] <= '9')
      maxSum += (grid[i][j] - '0');

    dp[i][j] = maxSum;
    ways[i][j] = totalWays;

    return {dp[i][j], ways[i][j]};
  }

  vector<int> pathsWithMaxScore(vector<string> &grid) {
    n = grid.size();

    memset(ways, 0, sizeof(ways));
    memset(dp, -1, sizeof(dp));

    auto [sum, ways] = f(0, 0, grid);

    if (sum == -INF)
      return {0, 0};

    return {sum, ways};
  }
};

// Bottom Up :

const int INF = 1e9;
const int MOD = 1e9 + 7;

class Solution {
public:
  int n;
  int row[3] = {1, 0, 1};
  int col[3] = {0, 1, 1};

  vector<int> pathsWithMaxScore(vector<string> &grid) {
    n = grid.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -INF));
    vector<vector<int>> ways(n + 1, vector<int>(n + 1, 0));

    dp[n - 1][n - 1] = 0;
    ways[n - 1][n - 1] = 1;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (grid[i][j] == 'X')
          dp[i][j] = -INF, ways[i][j] = 0;

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {

        if (i == n - 1 && j == n - 1)
          continue;

        if (grid[i][j] == 'X')
          continue;

        int maxSum = -INF;
        int totalWays = 0;

        for (int k = 0; k < 3; k++) {
          int ni = i + row[k];
          int nj = j + col[k];

          if (ni < n && nj < n && grid[ni][nj] != 'X') {
            auto sum = dp[ni][nj];
            auto childWays = ways[ni][nj];

            if (sum > maxSum) {
              maxSum = sum;
              totalWays = childWays;
            } else if (sum == maxSum) {
              totalWays = (childWays + totalWays) % MOD;
            }
          }
        }

        if (maxSum == -INF) {
          dp[i][j] = -INF;
          ways[i][j] = 0;
          continue;
        }

        if (grid[i][j] >= '1' && grid[i][j] <= '9')
          maxSum += (grid[i][j] - '0');

        dp[i][j] = maxSum;
        ways[i][j] = totalWays;
      }
    }

    auto sum = dp[0][0];
    auto totalWays = ways[0][0];

    if (sum < 0)
      return {0, 0};

    return {sum, totalWays};
  }
};