#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n;
  vector<vector<bool>> dp; // Checks if s[l..r] is palindrome in O(1)
  vector<int> memo;

  int f(int i, string &s, int k) {
    if (i >= n)
      return 0;

    if (memo[i] != -1)
      return memo[i];

    // Consider palindrome starting at i
    int cnt = 0;
    for (int end = i + k - 1; end < n; end++) {
      if (dp[i][end]) {
        cnt = max(cnt, 1 + f(end + 1, s, k));
      }
    }

    // Dont consider palindrome starting at i
    cnt = max(cnt, f(i + 1, s, k));

    return memo[i] = cnt;
  }

  int maxPalindromes(string s, int k) {
    n = s.size();
    dp.resize(n, vector<bool>(n, false));
    memo.resize(n, -1);

    for (int i = 0; i < n; i++)
      dp[i][i] = true;

    for (int len = 2; len <= n; len++) {
      for (int i = 0; len + i - 1 < n; i++) {
        // len = j - i + 1
        // j = len + i - 1
        int j = len + i - 1;

        if (s[i] == s[j]) {
          if (len == 2)
            dp[i][j] = true;
          else
            dp[i][j] = dp[i + 1][j - 1];
        }
      }
    }

    return f(0, s, k);
  }
};