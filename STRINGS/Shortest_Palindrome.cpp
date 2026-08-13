#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string shortestPalindrome(string s) {
    string rev = s;
    reverse(begin(rev), end(rev));

    for (int i = 0; i < s.size(); i++) {

      if (!memcmp(s.c_str(), rev.c_str() + i, s.size() - i)) {
        return rev.substr(0, i) + s;
      }
    }
    return rev + s;
  }
};

