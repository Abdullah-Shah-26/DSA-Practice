#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int nonSpecialCount(int l, int r) {
    int limit = sqrt(r);

    vector<bool> prime(limit + 1, true);
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i <= limit; i++) {
      if (prime[i]) {
        for (int j = i * i; j <= limit; j += i) {
          prime[j] = false;
        }
      }
    }

    int special = 0;

    for (int i = 2; i <= limit; i++) {
      if (prime[i]) {
        int sq = i * i;

        if (sq >= l && sq <= r)
          special++;
      }
    }

    return (r - l + 1) - special;
  }
};