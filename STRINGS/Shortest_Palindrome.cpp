#include <bits/stdc++.h>
using namespace std;

// TC = O(N^2) | SC = O(N)

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

// Using KMP Algorithm :

class Solution {
public:
  void computeLPS(string &pat, vector<int> &LPS) {
    int len = 0;
    LPS[0] = 0;
    int i = 1;
    while (i < pat.size()) {
      if (pat[i] == pat[len]) {
        len++;
        LPS[i] = len;
        i++;
      } else {
        if (len > 0) {
          len = LPS[len - 1];
        } else {
          LPS[i] = 0;
          i++;
        }
      }
    }
  }

  string shortestPalindrome(string s) {
    string rev = s;
    reverse(begin(rev), end(rev));
    string temp = s + "-" + rev;

    vector<int> LPS(temp.size(), 0);
    computeLPS(temp, LPS);

    int longestLPSLen = LPS[temp.size() - 1];

    string culprint = rev.substr(0, s.size() - longestLPSLen);

    return culprint + s;
  }
};