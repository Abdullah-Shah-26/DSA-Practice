#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestPalindrome(string s, string t) {
    int n = s.size();
    int m = t.size();

    // Find Longest Palindrome starting at every pos in s
    // and ending at every pos in t

    vector<vector<bool>> palS(n, vector<bool>(n, false));
    vector<vector<bool>> palT(m, vector<bool>(m, false));

    vector<int> bestStartS(n, 1);
    vector<int> bestEndT(m, 1);

    // palS[l][r] = is s[l..r] palindrome ?
    // s[l] [l+1 ... r-1] s[r]
    // If s[l] matches s[r]
    // palS[l + 1][r - 1]

    // For s
    for (int len = 1; len <= n; len++) {
      for (int l = 0; len + l - 1 < n; l++) {
        // len = j - i + 1
        // j = len + i - 1
        int r = len + l - 1;

        // Longest palindrome starting at l
        if (s[l] == s[r] && (len <= 2 || palS[l + 1][r - 1])) {
          palS[l][r] = true;

          bestStartS[l] = max(bestStartS[l], len);
        }
      }
    }

    // For t
    for (int len = 1; len <= m; len++) {
      for (int l = 0; len + l - 1 < m; l++) {
        int r = len + l - 1;

        // Longest palindrome ending at r
        if (t[l] == t[r] && (len <= 2 || palT[l + 1][r - 1])) {
          palT[l][r] = true;

          bestEndT[r] = max(bestEndT[r], len);
        }
      }
    }

    // A palindrome can be taken entirely from s or t
    int ans = 1;

    for (int len : bestStartS)
      ans = max(ans, len);

    for (int len : bestEndT)
      ans = max(ans, len);

    // For palindromes using both strings :
    // X + P + rev(X)

    // X comes from s
    // rev(X) comes from t i.e X comes in revT

    // Find their longest common substring

    string revT = t;
    reverse(begin(revT), end(revT));

    // match[i][j] = LCS ending at s[i - 1] revT[j - 1]
    vector<vector<int>> match(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {

        if (s[i - 1] == revT[j - 1]) {
          match[i][j] = match[i - 1][j - 1] + 1;

          int k = match[i][j];

          // Case 1 :
          // X + P + X
          // P is palindrome inside s, so P starts at s[i]

          if (i < n) {
            int middle = bestStartS[i];

            ans = max(ans, 2 * k + middle);
          }

          // Case 2 :
          // Middle part is inside tt
          // revT[j-k ... j-1] = X
          // [ middle ] [ rev(X) ]
          //            |
          //            m-j

          // (j - 1) in revT, (m - j) in T

          // So middle must end at m - j - 1

          int midEnd = m - j - 1;

          if (midEnd >= 0) {
            int middle = bestEndT[midEnd];

            ans = max(ans, 2 * k + middle);
          }

          // Case 3 :
          // We have no middle part
          // X + rev(X)

          ans = max(ans, 2 * k);
        }

        // If chars dont match then match[i][j] = 0
        // Since this is substr, prev match can't be continued
      }
    }

    return ans;
  }
};