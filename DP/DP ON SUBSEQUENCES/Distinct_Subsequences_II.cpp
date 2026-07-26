#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  static const int MOD = 1e9 + 7;
  int distinctSubseqII(string s) {
    int n = s.size();
    vector<long long> dp(n + 1);
    // Empty Subsequence
    dp[0] = 1;

    unordered_map<char, int> m;

    for (int i = 1; i <= n; i++) {
      dp[i] = (2 * dp[i - 1]) % MOD;

      char ch = s[i - 1];

      if (m.count(ch)) {
        int j = m[ch];
        dp[i] = (dp[i] - dp[j - 1] + MOD) % MOD;
      }
      m[ch] = i;
    }
    return (dp[n] - 1 + MOD) % MOD;
  }
};