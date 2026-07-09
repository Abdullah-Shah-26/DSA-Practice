#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int N = 1e6 + 6;

ll fact[N], invFact[N];

ll modPow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

ll modInv(ll n) { return modPow(n, MOD - 2); }

void precompute() {
  fact[0] = 1;

  for (int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * 1LL * i) % MOD;
  }

  invFact[N - 1] = modInv(fact[N - 1]);

  for (int i = N - 2; i >= 0; i--) {
    invFact[i] = (invFact[i + 1] * 1LL * (i + 1)) % MOD;
  }
}

ll nCr(ll a, ll b) {
  if (b < 0 || b > a)
    return 0;
  return (((fact[a] * invFact[b]) % MOD) * invFact[a - b]) % MOD;
}

// ---------- Solve ---------
void solve() {
  int q;
  cin >> q;
  while (q--) {
    ll a, b;
    cin >> a >> b;
    cout << nCr(a, b) << endl;
  }
}

// ---------- Main ----------
int main() {
  precompute();
  solve();
  return 0;
}