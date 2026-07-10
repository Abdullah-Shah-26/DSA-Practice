#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(N)

class Solution {
public:
  void computeLPS(string pat, vector<int> &LPS) {
    int len = 0;
    int i = 1;
    LPS[0] = 0;

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

  int minChar(string &s) {
    string rev = s;
    reverse(begin(rev), end(rev));

    string temp = s + "-" + rev;

    vector<int> LPS(temp.size());
    computeLPS(temp, LPS);

    int longestLPSLen = LPS[temp.size() - 1];

    string culprint = rev.substr(0, s.size() - longestLPSLen);

    return culprint.size();
  }
};
