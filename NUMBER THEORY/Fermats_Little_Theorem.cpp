#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int fact(int n)
{
  int f = 1;
  for (int i = 2; i <= n; i++)
  {
    f *= i;
  }
  return f;
}

int nCr(int n, int r)
{
  if (r < 0 || r > n)
  {
    return 0;
  }

  int a = fact(n);
  int b = fact(r) * fact(n - r) % MOD;

  return a * (int)pow(b, MOD - 2) % MOD;
}