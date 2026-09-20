#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int f(int i, int sum, vector<int> &squares, vector<vector<int>> &dp) {
    if (sum == 0)
      return 0;

    if (i == 0) {
      if (sum % squares[0] == 0)
        return sum / squares[0];

      return 1e7;
    }

    if (dp[i][sum] != -1)
      return dp[i][sum];

    int skip = f(i - 1, sum, squares, dp);
    int take = 1e7;

    if (squares[i] <= sum)
      take = 1 + f(i, sum - squares[i], squares, dp);

    return dp[i][sum] = min(take, skip);
  }

  int numSquares(int n) {
    int x = sqrt(n);

    if (x * x == n)
      return 1;

    vector<int> squares;

    for (int i = 1; i * i <= n; i++)
      squares.push_back(i * i);

    int N = squares.size();

    vector<vector<int>> dp(N + 1, vector<int>(n + 1, -1));

    return f(N - 1, n, squares, dp);
  }
};