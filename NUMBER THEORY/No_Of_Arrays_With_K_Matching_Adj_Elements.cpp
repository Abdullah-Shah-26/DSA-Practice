#include <bits/stdc++.h>
using namespace std;

// Combinatorics

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  vector<ll> fact;
  vector<ll> invFact;

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

  ll nCr(ll n, ll r) { // n! / (r! * (n - r)!)
    return ((fact[n] * invFact[r]) % MOD * invFact[n - r]) % MOD;
  }

  int countGoodArrays(int n, int m, int k) {

    // Factorial
    fact.assign(n + 1, 1);
    fact[0] = 1;
    fact[1] = 1;

    for (int i = 2; i <= n; i++)
      fact[i] = (fact[i - 1] * i) % MOD;

    // Inverse factorial using Fermats theorem
    invFact.assign(n + 1, 1);

    for (int i = 0; i <= n; i++)
      invFact[i] = binExpo(fact[i], MOD - 2);

    // (N - 1)C(k) * m * (m - 1) ^ (n - k - 1)
    ll ans = (nCr(n - 1, k) % MOD * binExpo(m - 1, n - k - 1) % MOD) * m % MOD;

    return ans;
  }
};