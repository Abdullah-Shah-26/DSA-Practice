#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
const int MOD = 1e9 + 7;

class Solution {
public:
  vvll multiply(const vvll &A, const vvll &B) {
    int n = A.size();

    vvll C(n, vll(n, 0));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;

    return C;
  }

  vvll matExpo(vvll base, ll exp) {
    int n = base.size();

    vvll ans(n, vll(n, 0));

    // Identity matrix
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

  int countGoodStrings(long long n) {

    // It has fibonacci like recurrence 
    vvll T = {{1, 1}, {1, 0}};
    vvll ans = matExpo(T, n - 1);

    return 2LL * ans[0][0] % MOD;
  }
};