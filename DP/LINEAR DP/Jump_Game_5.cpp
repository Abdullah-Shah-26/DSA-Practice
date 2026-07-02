#include <bits/stdc++.h>
using namespace std;

// Top-down

class Solution {
public:
  int n;
  int dp[1001];
  int solve(int i, int d, vector<int> &arr) {
    int ans = 1;

    if (dp[i] != -1)
      return dp[i];

    // Go right
    for (int j = i + 1; j <= min(n - 1, i + d); j++) {
      if (arr[j] >= arr[i])
        break;

      ans = max(ans, 1 + solve(j, d, arr));
    }

    // Go left
    for (int j = i - 1; j >= max(0, i - d) && arr[i] > arr[j]; j--) {
      if (arr[j] >= arr[i])
        break;

      ans = max(ans, 1 + solve(j, d, arr));
    }

    return dp[i] = ans;
  }

  int maxJumps(vector<int> &arr, int d) {
    n = arr.size();
    memset(dp, -1, sizeof(dp));

    int res = 1;
    for (int i = 0; i < arr.size(); i++)
      res = max(res, solve(i, d, arr));

    return res;
  }
};

// Bottom - up

class Solution {
public:
  int maxJumps(vector<int> &arr, int d) {
    int n = arr.size();

    // Process values in ascending order (valid dependency order here is arr[j] < arr[i])
    vector<int> order(n);
    iota(begin(order), end(order), 0);

    sort(begin(order), end(order),
         [&](int a, int b) { return arr[a] < arr[b]; });

    int ans = 1;
    vector<int> dp(n, 1);

    for (int i : order) {
      dp[i] = 1;

      // Go Left
      for (int j = i - 1; j >= max(0, i - d); j--) {
        if (arr[j] >= arr[i])
          break;

        dp[i] = max(dp[i], 1 + dp[j]);
      }

      // Go Right
      for (int j = i + 1; j <= min(n - 1, i + d); j++) {
        if (arr[j] >= arr[i])
          break;

        dp[i] = max(dp[i], 1 + dp[j]);
      }

      ans = max(ans, dp[i]);
    }

    return ans;
  }
};