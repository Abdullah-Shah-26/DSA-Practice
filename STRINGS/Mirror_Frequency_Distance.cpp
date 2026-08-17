#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mirrorFrequency(string s) {
    unordered_map<char, int> m;

    for (auto &ch : s)
      m[ch]++;

    int cnt = 0;

    for (char ch = 'a'; ch <= 'm'; ch++) {
      char mch = 'z' - (ch - 'a');
      cnt += abs(m[ch] - m[mch]);
    }

    for (char ch = '0'; ch <= '4'; ch++) {
      char mch = '9' - (ch - '0');
      cnt += abs(m[ch] - m[mch]);
    }

    return cnt;
  }
};