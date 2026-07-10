#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
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

  int countGoodNumbers(long long n) {
    ll evenIdx = (n + 1) / 2;
    ll oddIdx = n / 2;

    return binExpo(5, evenIdx) * binExpo(4, oddIdx) % MOD;
  }
};