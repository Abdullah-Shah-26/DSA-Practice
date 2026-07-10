#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll extendedGCD(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  ll x1, y1;
  ll gcd = extendedGCD(b, a % b, x1, y1);

  x = y1;
  y = x1 - (a / b) * y1;

  return gcd;
}

ll modInv(ll a, ll mod) {
  ll x, y;

  extendedGCD(a, mod, x, y);

  x %= mod;

  if (x < 0)
    x += mod;

  return x;
}

ll CRT(vector<ll> remainder, vector<ll> modulus) {
  ll M = 1;

  for (ll mod : modulus)
    M *= mod;

  ll ans = 0;

  for (int i = 0; i < remainder.size(); i++) {
    ll Mi = M / modulus[i];
    ll inverse = modInv(Mi, modulus[i]);
    ans = (ans + remainder[i] * Mi % M * inverse % M) % M;
  }

  return ans;
}

int main() {

  vector<ll> remainder = {2, 3, 2};
  vector<ll> modulus = {3, 5, 7};

  cout << CRT(remainder, modulus) << endl;

  return 0;
}
