#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  int countOrders(int n) {
    if (n == 1)
      return 1;

    ll res = 1;

    for (int i = 2; i <= n; i++) {
      ll spaces = (i - 1) * 2 + 1;
      // spacesC2/2, divide by 2 because half set of choices where di before pi are invalid
      ll possiblities = (spaces * (spaces + 1) / 2) % MOD; 
      res = (res * possiblities) % MOD;
    }

    return res;
  }
};