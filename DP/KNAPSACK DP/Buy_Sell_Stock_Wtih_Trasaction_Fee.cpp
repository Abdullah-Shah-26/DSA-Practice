#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n;
  int dp[50005][2];
  int f(int i, bool flag, int fee, vector<int> &prices){
    if(i >= n) return 0;
    if(dp[i][flag] != -1) return dp[i][flag];

    if(flag == 0){
      return dp[i][flag] = max(f(i + 1, flag, fee, prices), -prices[i] + f(i + 1, !flag, fee,prices));
    }

    return dp[i][flag] = max(f(i + 1, flag, fee, prices), prices[i] - fee + f(i + 1, !flag, fee, prices));
  }

  int maxProfit(vector<int>& prices, int fee) {
  n = prices.size();

  memset(dp, -1, sizeof(dp));
  return f(0, 0, fee, prices);
  }
};


class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
  int n = prices.size();

  vector<vector<int>> dp(n + 1, vector<int> (2, 0));

  for(int i = n-1; i >= 0; i--){
    dp[i][0] = max(dp[i+1][0], -prices[i] + dp[i+1][1]);
    dp[i][1] = max(dp[i+1][1], prices[i] - fee + dp[i+1][0]);
  }

  return dp[0][0];
  }
};