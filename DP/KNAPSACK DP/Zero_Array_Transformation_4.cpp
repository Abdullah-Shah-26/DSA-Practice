#include <bits/stdc++.h>
using namespace std;

// 0/1 Subset sum dp

class Solution {
public:
  int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
      int need = nums[i];

      if (need == 0)
        continue;

      vector<bool> dp(need + 1);
      dp[0] = true;

      // dp[x] = using the queries so far, can we make x total decrements

      for (int k = 0; k < queries.size(); k++) {
        auto it = queries[k];
        int l = it[0], r = it[1], val = it[2];

        if (i >= l && i <= r) {
          for (int x = need; x >= val; x--)
            dp[x] = dp[x] || dp[x - val];
        }

        if (dp[need]) {
          ans = max(ans, k + 1);
          break;
        }
      }

      if (!dp[need])
        return -1;
    }

    return ans;
  }
};