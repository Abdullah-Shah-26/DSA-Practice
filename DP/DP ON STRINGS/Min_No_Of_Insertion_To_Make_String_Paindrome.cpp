#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Returns LCS length of two strings
  int lcs(string &a, string &b) {
    int n = a.size(), m = b.size();

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 1; i <= n; i++) {
      curr[0] = 0;

      for (int j = 1; j <= m; j++) {
        if (a[i - 1] == b[j - 1])
          curr[j] = 1 + prev[j - 1];
        else
          curr[j] = max(prev[j], curr[j - 1]);
      }

      prev = curr;
    }

    return prev[m];
  }

  // Longest Palindromic Subsequence = LCS(s, reverse(s))
  int lps(string &s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return lcs(s, rev);
  }

  int minInsertions(string s) {
    // Keep the longest palindromic subsequence,
    // insert characters for the remaining ones.
    return s.size() - lps(s);
  }
};