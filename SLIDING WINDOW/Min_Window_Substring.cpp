#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<int> freq(128, 0);

    for (char &ch : t)
      freq[ch]++;

    int need = t.size();

    int l = 0;
    int st = 0;
    int minLen = 1e9;

    for (int r = 0; r < n; r++) {

      if (freq[s[r]] > 0)
        need--;

      freq[s[r]]--;

      while (need == 0) {

        if (r - l + 1 < minLen) {
          minLen = r - l + 1;
          st = l;
        }

        freq[s[l]]++;

        if (freq[s[l]] > 0)
          need++;

        l++;
      }
    }

    return minLen == 1e9 ? "" : s.substr(st, minLen);
  }
};