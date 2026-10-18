#include <bits/stdc++.h>
using namespace std;

class KMP {
private:
  vector<int> buildLps(string &s) {
    int m = s.size();

    vector<int> lps(m);

    for (int i = 1, j = 0; i < m;) {
      if (s[i] == s[j]) {
        lps[i] = j + 1;
        i++;
        j++;
      } else {
        if (j == 0) {
          lps[i] = 0;
          i++;
        } else
          j = lps[j - 1];
      }
    }

    return lps;
  }

public:
  vector<int> find(string &text, string &pat) {
    int n = text.size();
    int m = pat.size();

    vector<int> lps = buildLps(pat);

    vector<int> ans;

    for (int i = 0, j = 0; i < n;) {

      if (text[i] == pat[j]) {
        i++;
        j++;
      }

      if (j == m) {
        ans.push_back(i - m);
        j = lps[j - 1];
      }

      else if (i < n && text[i] != pat[j]) {

        if (j)
          j = lps[j - 1];

        else
          i++;
      }
    }

    // Ans contains indices where the pattern starts in text
    return ans;
  }
};