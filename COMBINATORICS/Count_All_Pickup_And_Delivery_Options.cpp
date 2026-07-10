#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  /*
    2*n slots
    Valid way -> pickupI before deliveryI
    Total ways = x * (x - 1)
    Valid ways = (x * (x - 1))/2 
    (half of them)
  */

  int countOrders(int n) {
    if (n == 1)
      return 1;

    ll res = 1;
    ll slots = 2 * n;

    while (slots > 0) {
      ll valid = (slots * (slots - 1) / 2) % MOD;
      res = (res * valid) % MOD;
      slots -= 2;
    }

    return res;
  }
};