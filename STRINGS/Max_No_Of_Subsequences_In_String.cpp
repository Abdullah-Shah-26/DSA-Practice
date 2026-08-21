#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  ll dp[100005][3];

  // Rec + Memo
  ll solve(int i, int j, string &text, string &pattern) {
    if (j == pattern.size()) // Pattern found in text
      return 1;

    if (i == text.size()) // Could'nt find pattern in text
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    ll ans = solve(i + 1, j, text, pattern); // Skip

    if (text[i] == pattern[j])
      ans += solve(i + 1, j + 1, text, pattern); // Take

    return dp[i][j] = ans;
  }

  ll cntRec(string &text, string &pattern) {
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, text, pattern);
  }

  // Bottom - Up
  ll cnt(string &text, string &pattern) {
    int m = pattern.size();

    vector<ll> dp(m + 1);
    dp[0] = 1;

    for (char ch : text) {
      for (int j = m; j >= 1; j--) {
        if (ch == pattern[j - 1])
          dp[j] = (dp[j] + dp[j - 1]);
      }
    }

    return dp[m];
  }

  long long maximumSubsequenceCount(string text, string pattern) {

    string s1 = text + pattern[1];
    string s2 = pattern[0] + text;

    return max(cntRec(s1, pattern), cntRec(s2, pattern));
  }
};