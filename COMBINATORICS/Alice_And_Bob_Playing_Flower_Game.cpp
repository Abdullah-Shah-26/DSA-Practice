#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:

  // Range [1..n] [1..m]
  // No of odd no's in range from 1..N = Ceil(N/2)
  // Every odd sum causes alice to win
  // Ways to make sum as odd
  // odd + even
  // even + odd

  long long flowerGame(int n, int m) {
    ll oddN = (n + 1) / 2;
    ll evenN = n / 2;
    ll oddM = (m + 1) / 2;
    ll evenM = m / 2;

    return (oddN * evenM) + (evenN * oddM);
  }
};