#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minDeletionSize(vector<string> &strs) {
    int rows = strs.size();
    int cols = strs[0].size();

    vector<int> dp(cols, 1); // LIS Modified
    // dp[i] = LIS ending at idx = i

    int LIS = 1;

    for (int i = 0; i < cols; i++) {
      for (int j = 0; j < i; j++) {
        bool safe = true;

        // s[j] <= s[i]
        // Should be true for all strings
        for (auto &s : strs) {
          if (s[j] > s[i]) {
            safe = false;
            break;
          }
        }

        if (safe)
          dp[i] = max(dp[i], dp[j] + 1);
      }
      LIS = max(LIS, dp[i]);
    }

    // Need min deletions
    return cols - LIS;
  }
};