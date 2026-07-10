#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Returns the length of the Longest Common Subsequence
  int LCS(string &s, string &t) {
    int n = s.size();
    int m = t.size();

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int i = 1; i <= n; i++) {
      curr[0] = 0;

      for (int j = 1; j <= m; j++) {
        if (s[i - 1] == t[j - 1])
          curr[j] = 1 + prev[j - 1];
        else
          curr[j] = max(prev[j], curr[j - 1]);
      }

      prev = curr;
    }

    return prev[m];
  }

  int minOperations(string &s1, string &s2) {
    // Keep the LCS.
    // Delete the remaining characters from s1.
    // Insert the remaining characters from s2.
    int lcs = LCS(s1, s2);

    return (s1.size() - lcs) + (s2.size() - lcs);
  }
};