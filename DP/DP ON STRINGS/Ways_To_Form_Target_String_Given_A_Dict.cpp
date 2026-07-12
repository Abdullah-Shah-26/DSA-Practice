#include <bits/stdc++.h>
using namespace std;

// Knapsack dp on string

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  int t, l;
  vector<vector<ll>> freq;
  vector<vector<ll>> dp;

  ll f(int i, int j, vector<string> &words, string &target) {
    if (i == t)
      return 1;

    if (j == l)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    ll skip = f(i, j + 1, words, target);
    ll take = (freq[target[i] - 'a'][j] * f(i + 1, j + 1, words, target)) % MOD;

    return dp[i][j] = (take + skip) % MOD;
  }

  int numWays(vector<string> &words, string target) {
    t = target.size();
    l = words[0].size();

    // 2D freq to store freq of each char at each idx to compute all ways to
    // form target string efficiently
    freq.assign(26, vector<ll>(l, 0));
    dp.assign(t, vector<ll>(l, -1));

    for (int col = 0; col < l; col++) {
      for (auto &w : words) {
        char ch = w[col];
        freq[ch - 'a'][col]++;
      }
    }

    return f(0, 0, words, target);
  }
};

// Bottom up :

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  int t, l;
  vector<vector<ll>> freq;
  vector<vector<ll>> dp;

  int numWays(vector<string> &words, string target) {
    t = target.size();
    l = words[0].size();

    // 2D freq to store freq of each char at each idx to compute all ways to
    // form target string efficiently
    freq.assign(26, vector<ll>(l, 0));
    dp.assign(t + 1, vector<ll>(l + 1, 0));

    for (int col = 0; col < l; col++) {
      for (auto &w : words) {
        char ch = w[col];
        freq[ch - 'a'][col]++;
      }
    }

    // Base cases :
    for (int i = 0; i <= t; i++)
      dp[i][l] = 0;

    for (int j = 0; j <= l; j++)
      dp[t][j] = 1;

    for (int i = t - 1; i >= 0; i--) {
      for (int j = l - 1; j >= 0; j--) {

        ll skip = dp[i][j + 1];
        ll take = (freq[target[i] - 'a'][j] * dp[i + 1][j + 1]) % MOD;

        dp[i][j] = (take + skip) % MOD;
      }
    }

    return dp[0][0];
  }
};