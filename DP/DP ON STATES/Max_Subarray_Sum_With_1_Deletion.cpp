#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// DP + Kadan 
// Finite state dp

class Solution {
public:
  int maximumSum(vector<int>& a) {
    int n = a.size();  

    // dp[i][0] = Max sum ending at i with 0 deletions
    // dp[i][1] = Max sum ending at i with 1 deletion
    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][0] = a[0];
    dp[0][1] = -INF; // Since deleting 1 element isn't allowed 

    int maxi = a[0];

    for(int i = 1; i < n; i++){
      // State 0 : No deletions 
      // Start fresh at a[i] or extend prev sum
      dp[i][0] = max(a[i], dp[i - 1][0] + a[i]);

      // State 1 : 1 deletion
      // Case 1 : Delete cur a[i] & take prev 'no deletion' sum i.e dp[i-1][0]
      // Case 2 : We deleted a guy in past, so take prev '1 deletion sum' + a[i]
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);

      maxi = max({maxi, dp[i][0], dp[i][1]});
    }

    return maxi;
  }
};