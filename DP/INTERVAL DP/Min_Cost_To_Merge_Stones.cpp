#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mergeStones(vector<int> &stones, int k) {
    int n = stones.size();

    if ((n - 1) % (k - 1) != 0)
      return -1;

    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
      prefix[i + 1] = prefix[i] + stones[i];

    const long long INF = 1e18;

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    // len = length of current interval
    for (int len = k; len <= n; len++) {

      for (int l = 0; l + len <= n; l++) {

        int r = l + len - 1;

        dp[l][r] = INF;

        // Only consider splits where left part
        // can be reduced to exactly one pile.
        for (int mid = l; mid < r; mid += k - 1) {
          dp[l][r] = min(dp[l][r], dp[l][mid] + dp[mid + 1][r]);
        }

        // Can this whole interval become one pile?
        if ((len - 1) % (k - 1) == 0) {
          dp[l][r] += prefix[r + 1] - prefix[l];
        }
      }
    }

    return dp[0][n - 1];
  }
};