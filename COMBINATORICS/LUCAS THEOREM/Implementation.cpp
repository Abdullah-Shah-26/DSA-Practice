#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int p; // Should be prime
vector<ll> fact;
vector<ll> invFact;

ll binExpo(ll base, ll exp) {
  ll ans = 1;
  while (exp > 0) {
    if (exp & 1)
      ans = (ans * base) % p;

    base = (base * base) % p;
    exp >>= 1;
  }
  return ans;
}

// nCr where n < p
ll nCr(int n, int r) {
  if (r > n)
    return 0;

  return ((fact[n] * invFact[r] % p) * invFact[n - r]) % p;
}

ll lucas(ll n, ll r) {
  if (r > n)
    return 0;

  ll ans = 1;

  while (n > 0 || r > 0) {
    int digitN = n % p;
    int digitR = r % p;

    if (digitR > digitN)
      return 0;

    ans = (ans * nCr(digitN, digitR)) % p;

    n /= p;
    r /= p;
  }

  return ans;
}

int main() {
  cin >> p;

  // Precomputing factorials
  fact.resize(p);
  invFact.resize(p);

  fact[0] = 1;

  for (int i = 1; i < p; i++)
    fact[i] = (fact[i - 1] * i) % p;

  // Inverse factorial 
  invFact[p - 1] = binExpo(fact[p - 1], p - 2);

  for(int i = p-2; i >= 0; i--)
    invFact[i] = (invFact[i + 1] * (i + 1)) % p;

  ll n, r;
  cin >> n >> r;

  cout << lucas(n, r) << endl;

  return 0;
}