#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  static const int N = 10001;
  inline static bool flag = false;
  inline static ll fact[N], invFact[N];

  ll binExpo(ll a, ll b) {
    ll ans = 1;

    while (b) {
      if (b & 1)
        ans = ans * a % MOD;

      a = a * a % MOD;
      b >>= 1;
    }

    return ans;
  }

  void precompute() {
    fact[0] = 1;

    for (ll i = 1; i < N; i++)
      fact[i] = fact[i - 1] * i % MOD;

    invFact[N - 1] = binExpo(fact[N - 1], MOD - 2);

    for (ll i = N - 2; i >= 0; i--)
      invFact[i] = invFact[i + 1] * (i + 1) % MOD;
  }

  ll nCr(ll n, ll r) {
    if (r < 0 || r > n)
      return 0;

    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
  }

  void findSets(int m, vector<ll> &cnt, vector<vector<ll>> &dp) {
    if (dp[m][1] != 0)
      return;

    dp[m][1] = 1;
    cnt[1]++; // Cnt of subsets with len = 1

    // Trying divisors of m to extend the set
    for (int div = 2; div <= m; div++) {
      if (m % div == 0) {
        findSets(m / div, cnt, dp);

        for (int len = 1; len < 15; len++) {
          if (dp[m / div][len] != 0) {
            dp[m][len + 1] = (dp[m][len + 1] + dp[m / div][len]) % MOD;
            cnt[len + 1] = (cnt[len + 1] + dp[m / div][len]) % MOD;
          }
        }
      }
    }
  }

  int idealArrays(int n, int maxVal) {
    if (flag == false) {
      flag = true;
      precompute();
    }

    // cnt[x] = No of sets of len = x
    vector<ll> cnt(15, 0);
    vector<vector<ll>> dp(maxVal + 1, vector<ll>(15, 0));

    for (int val = 1; val <= maxVal; val++)
      findSets(val, cnt, dp);

    ll ans = 0;
    for (int len = 1; len < 15; len++)
      ans = (ans + (cnt[len] * nCr(n - 1, len - 1)) % MOD) % MOD;

    return ans;
  }
};