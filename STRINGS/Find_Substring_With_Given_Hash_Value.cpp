#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Sliding Window in reverse direction 

class Solution {
public:
  string subStrHash(string s, int power, int modulo, int k, int hashValue) {
    int n = s.size();

    ll pk = 1;
    for (int i = 1; i < k; i++)
      pk = (pk * power) % modulo;

    ll hash = 0;
    ll p = 1;
    int stIdx = -1;

    // Hash of last window
    for (int i = n - k; i < n; i++) {
      ll val = s[i] - 'a' + 1;
      hash = (hash + val * p) % modulo;
      p = (power * p) % modulo;
    }

    // Assuming last window is ans
    stIdx = n - k;
    if (hash != hashValue)
      stIdx = -1;

    // Sliding from R -> L
    for (int i = n - k - 1; i >= 0; i--) {
      int remove = s[i + k] - 'a' + 1;
      int add = s[i] - 'a' + 1;

      // Remove the contribution of char that is leaving the window
      hash = (hash - remove * pk % modulo + modulo) % modulo;
      hash = (hash * power) % modulo;

      // Add the constribution of new char
      hash = (hash + add) % modulo;

      if (hash == hashValue)
        stIdx = i;
    }

    return s.substr(stIdx, k);
  }
};