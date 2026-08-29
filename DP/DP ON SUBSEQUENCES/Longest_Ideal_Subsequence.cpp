#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestIdealString(string s, int k) {
    int n = s.size();

    vector<int> dp(n, 1);

    int ans = 1;

    for (int i = 0; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {

        if (abs(s[i] - s[j]) <= k)
          dp[i] = max(dp[i], dp[j] + 1);
      }
      ans = max(ans, dp[i]);
    }

    return ans;
  }
};

class Solution {
public:
  int longestIdealString(string s, int k) {
    int n = s.size();

    vector<int> dp(26, 0);

    int ans = 0;

    for (int i = 0; i < n; i++) {
      int cur = s[i] - 'a';
      int L = max(0, cur - k);
      int R = min(25, cur + k);

      int longest = 0;
      for (int j = L; j <= R; j++)
        longest = max(longest, dp[j]);

      dp[cur] = max(dp[cur], longest + 1);
      ans = max(ans, dp[cur]);
    }

    return ans;
  }
};