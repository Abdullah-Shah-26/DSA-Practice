#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

using vll = vector<ll>;
using vvll = vector<vector<ll>>;

// Total TC = O(N^3 * Log(exp))

// O(N cube) | N = matrix dimension
vvll multiply(const vvll &A, const vvll &B) {

  int n = A.size();

  vvll C(n, vll(n, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;

  return C;
}

// O(Log(exp))
vvll matExpo(vvll base, ll exp) {

  int n = base.size();

  vvll ans(n, vll(n, 0));

  // Build the identity matrix
  for (int i = 0; i < n; i++)
    ans[i][i] = 1;

  while (exp) {
    if (exp & 1)
      ans = multiply(ans, base);

    base = multiply(base, base);
    exp >>= 1;
  }

  return ans;
}

int main() {
  ll n;
  cin >> n;

  if (n == 0) {
    cout << 0;
    return 0;
  }

  // For fibonacci series
  vvll T = {{1, 1}, {1, 0}};
  vvll res = matExpo(T, n - 1);

  cout << res[0][0] << endl;

  return 0;
}