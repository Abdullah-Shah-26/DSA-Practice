#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void primeFactorize(int x, unordered_map<int, vector<int>> &primeFactors) {
    int original = x;
    vector<int> fact; // Prime factors of number (x)

    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0)
        fact.push_back(i);

      while (x % i == 0)
        x /= i;
    }

    if (x > 1) // X is a prime no
      fact.push_back(x);

    primeFactors[original] = fact;
  }

  int longestSubarray(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, vector<int>> primeFactors; // [value, Its prime factors]

    for (int x : nums)
      if (!primeFactors.count(x))
        primeFactorize(x, primeFactors);

    unordered_map<int, int> primeFreq; // [value, freq]

    int l = 0;
    int maxLen = 0;

    for (int r = 0; r < n; r++) {
      for (auto factor : primeFactors[nums[r]])
        primeFreq[factor]++;

      while (l <= r && primeFreq.size() > k) {
        for (auto factor : primeFactors[nums[l]]) {
          primeFreq[factor]--;

          if (primeFreq[factor] == 0)
            primeFreq.erase(factor);
        }
        l++;
      }

      maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
  }
};