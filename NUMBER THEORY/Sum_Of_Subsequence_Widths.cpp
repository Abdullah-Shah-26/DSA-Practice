#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  int sumSubseqWidths(vector<int> &a) {
    static bool precompute = false;
    static vector<ll> pow2(100001);

    if (!precompute) {
      precompute = true;

      pow2[0] = 1;
      for (int i = 1; i <= 100000; i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    sort(begin(a), end(a));
    ll sum = 0;
    int n = a.size();

    for (int i = 0; i < n; i++) {
      int L = i;         // Elements to the left that will be min
      int R = n - i - 1; // Elements to the right that will be max

      // Contribution = a[i] * (Being maximum - Being minimum)
      ll C = a[i] * (pow2[L] - pow2[R]) % MOD;
      sum = (sum + C) % MOD;
    }

    return sum;
  }
};