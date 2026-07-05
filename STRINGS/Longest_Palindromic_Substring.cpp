#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string transform(string &s) {
    string t = "";

    t += '^';
    t += '#';
    for (char &c : s) {
      t += c;
      t += '#';
    }
    t += '$';

    return t;
  }

  string longestPalindrome(string s) {
    if (s.empty() || s.size() == 1)
      return s;

    // Manacher

    string t = transform(s);
    int n = t.size();

    vector<int> p(n, 0);
    int center = 0, right = 0;
    int maxLen = 0, L = 0, R = 0;

    for (int i = 1; i < n - 1; i++) {
      int mirror = 2 * center - i;

      if (i < right)
        p[i] = min(p[mirror], right - i);

      while (t[i + p[i] + 1] == t[i - p[i] - 1])
        p[i]++;

      if (i + p[i] > right) {
        center = i;
        right = i + p[i];
      }

      if (p[i] > maxLen) {
        maxLen = p[i];
        L = (i - p[i]) / 2;
        R = (i + p[i]) / 2 - 1;
      }
    }

    return s.substr(L, R - L + 1);
  }
};