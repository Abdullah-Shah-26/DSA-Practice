#include <bits/stdc++.h>
using namespace std;
  
class Solution {
 public:
  int n; 
  int dp[30004][2];
  int f(int i, bool flag, vector<int> &prices){
    if(i >= n) return 0;

    if(dp[i][flag] != -1) return dp[i][flag];

    if(flag == 0){
      // We can skip this day or choose to buy at this day
      return dp[i][flag] = max(f(i + 1, flag, prices), -prices[i] + f(i + 1, !flag, prices));
    }
    // We can skip this day, or choose to sell at this day
    return dp[i][flag] = max(f(i + 1, flag, prices), prices[i] + f(i + 1, !flag, prices)); 
  }

  int maxProfit(vector<int>& prices) {
  n = prices.size();

  memset(dp, -1, sizeof(dp));
  return f(0, 0, prices);
  }
};


class Solution {
 public:
  int maxProfit(vector<int>& prices) {
  int n = prices.size();

  vector<vector<int>> dp(n + 1, vector<int> (2, false));

  for(int i = n-1; i >= 0; i--){
    for(int flag = 0; flag < 2 ; flag++){

      if(flag == 0){
      // We can skip this day or choose to buy at this day
      dp[i][flag] = max(dp[i + 1][flag], -prices[i] + dp[i + 1][!flag]);
      }
      else if(flag == 1){
      // We can skip this day, or choose to sell at this day
      dp[i][flag] = max(dp[i + 1][flag], prices[i] + dp[i + 1][!flag]); 
      }
      
    }
  }

  return dp[0][0];
  }
};


class Solution {
 public:
  int maxProfit(vector<int>& prices) {
  int n = prices.size();

  vector<vector<int>> dp(n + 1, vector<int> (2, false));
  
  for(int i = n-1; i >= 0; i--){
    dp[i][0] = max(dp[i + 1][0], -prices[i] + dp[i + 1][1]);
    dp[i][1] = max(dp[i + 1][1], prices[i] + dp[i + 1][0]); 
  }

  return dp[0][0];
  }
};