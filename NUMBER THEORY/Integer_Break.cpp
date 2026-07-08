#include <bits/stdc++.h>
using namespace std;

// TC = O(N * (N-1))
// DP + Math

class Solution {
public:
  vector<int> dp;
  int solve(int n) {
    if (n == 1)
      return 1;
    if (dp[n] != -1)
      return dp[n];

    int res = INT_MIN;

    for (int i = 1; i <= n - 1; i++) {
      int prod = i * max(n - i, solve(n - i));
      res = max(res, prod);
    }

    return dp[n] = res;
  }

  int integerBreak(int n) {
    dp.assign(n + 1, -1);
    return solve(n);
  }
};

// Bottom Up

class Solution {
public:
  int integerBreak(int N) {
    vector<int> dp(N + 1, INT_MIN);
    dp[1] = 1;

    for (int n = 2; n <= N; n++) {
      int res = INT_MIN;
      for (int i = 1; i <= n - 1; i++) {
        int prod = i * max(n - i, ((n - i) > 0) ? dp[n - i] : INT_MIN);
        res = max(res, prod);
      }
      dp[n] = res;
    }

    return dp[N];
  }
};