#include <bits/stdc++.h>
using namespace std;

// Rec + Memo - TLE

using ll = long long;
const int MOD = 1e9 + 7;

// needGreater = 1 -> Increase
// needGreater = 0 -> Decrease

// TC = O(N * M * 2) * (M)
//    = (No of states) * (Work done per each state)

class Solution {
public:
  int n, m;
  ll dp[2001][2001][2];

  int f(int i, int prev, bool needGreater) { // prev value
    if (i == n)
      return 1;

    if (dp[i][prev][needGreater] != -1)
      return dp[i][prev][needGreater];

    ll res = 0;

    if (needGreater)                               // Increasing
      for (int next = prev + 1; next <= m; next++) // Next value
        res = (res + f(i + 1, next, false)) % MOD;

    else // Decreasing
      for (int next = 1; next <= prev - 1; next++)
        res = (res + f(i + 1, next, true)) % MOD;

    return dp[i][prev][needGreater] = res % MOD;
  }

  int zigZagArrays(int N, int l, int r) {
    n = N;
    m = (r - l + 1);
    l = 1;

    ll ans = 0;
    memset(dp, -1, sizeof(dp));

    for (int st = l; st <= m; st++) { // Start value at idx = 0

      // Inc
      ans = (ans + f(1, st, true)) % MOD;

      // Dec
      ans = (ans + f(1, st, false)) % MOD;
    }

    return ans;
  }
};

// Finite state dp
// Prefix sum optimization
// Rolling dp - space optimization

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    int m = (r - l + 1);

    // vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>> (m + 1, vector<ll> (2, 0)));
    vector<array<ll, 2>> nxt(m + 1);
    vector<array<ll, 2>> cur(m + 1);

    for (int prev = 1; prev <= m; prev++) {
      nxt[prev][0] = 1;
      nxt[prev][1] = 1;
    }

    for (int i = n - 1; i >= 1; i--) {

      // We overwrite cur completely, so not reinitializing not requried
      // fill(begin(cur), end(cur), array<ll,2>{0, 0});

      vector<ll> pref0(m + 1, 0);
      vector<ll> pref1(m + 1, 0);

      for (int val = 1; val <= m; val++) {
        pref0[val] = (pref0[val - 1] + nxt[val][0]) % MOD;
        pref1[val] = (pref1[val - 1] + nxt[val][1]) % MOD;
      }

      for (int prev = 1; prev <= m; prev++) {

        /* Optimizing Inner loops using prefix sum */

        // Inc
        // for(int next = prev + 1; next <= m; next++)
        //   dp[i][prev][1] = (dp[i][prev][1] + dp[i + 1][next][0]) % MOD;

        cur[prev][1] = (pref0[m] - pref0[prev] + MOD) % MOD;

        // Dec
        // for(int next = 1; next < prev; next++)
        //   dp[i][prev][0] = (dp[i][prev][0] + dp[i + 1][next][1]) % MOD;

        cur[prev][0] = pref1[prev - 1];
      }

      swap(nxt, cur);
    }

    ll ans = 0;

    for (int st = 1; st <= m; st++) {
      ans = (ans + nxt[st][1]) % MOD;
      ans = (ans + nxt[st][0]) % MOD;
    }

    return ans;
  }
};