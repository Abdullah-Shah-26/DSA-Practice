#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxVowels(string s, int k) {
    int n = s.length();
    int maxV = 0, count = 0;

    // Edge case
    if (k > n)
      return 0;

    auto isVowel = [&](char ch) {
      return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    };

    int l = 0;
    for (int r = 0; r < n; r++) {
      if (isVowel(s[r]))
        count++;

      if (r - l + 1 == k) {
        maxV = max(maxV, count);

        if (isVowel(s[l]))
          count--;

        l++;
      }
    }

    return maxV;
  }
};