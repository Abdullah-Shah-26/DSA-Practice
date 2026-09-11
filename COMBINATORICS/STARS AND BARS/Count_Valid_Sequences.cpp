#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  static const int MOD = 1e9 + 7;

  ll binExpo(ll a, ll b) {
    ll res = 1;

    while (b) {
      if (b & 1)
        res = res * a % MOD;

      a = a * a % MOD;
      b >>= 1;
    }

    return res;
  }

  int countValidSequences(int n, int k) {
    vector<ll> fact(n), invFact(n);

    fact[0] = 1;

    for (int i = 1; i < n; i++)
      fact[i] = fact[i - 1] * i % MOD;

    invFact[n - 1] = binExpo(fact[n - 1], MOD - 2);

    for (int i = n - 1; i >= 1; i--)
      invFact[i - 1] = invFact[i] * i % MOD;

    auto nCr = [&](int n, int r) {
      return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    };

    ll total = nCr(n - 1, k - 1);
    ll odd = 0;

    if ((n - k) % 2 == 0)
      odd = nCr((n + k) / 2 - 1, k - 1);

    return (total - odd + MOD) % MOD;
  }
};