#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

// Greedy simulation

class Solution {
public:
  int minimumCost(vector<int> &nums, int k) {
    ll cnt = 0;
    ll r = k; // We start with k units of resources

    for (auto &x : nums) {
      if (r >= x)
        r -= x;
      else { // x > r
        ll ops = (x - r + k - 1) / k; // No of ops we need = ceil((x-r)/k) = (a+b-1)/b
        cnt += ops;
        r += (k * ops); // Each operation increases resources by k
        r -= x;
      }
    }

    // op 1 : cost = 1
    // op 2 : cost = 2
    // op n : cost = n
    // To compute overall cost we can use Sum of first N natural no's forumla

    if (cnt % 2 == 0) // To avoid ll overflow
      return ((cnt / 2) % MOD) * ((cnt + 1) % MOD) % MOD;
    else
      return ((cnt + 1) / 2 % MOD) * (cnt % MOD) % MOD;
  }
};