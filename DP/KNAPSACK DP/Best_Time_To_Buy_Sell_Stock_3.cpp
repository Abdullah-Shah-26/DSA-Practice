#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n;
  int dp[100005][2][3];
  int f(int i, bool flag, int cnt, vector<int>& prices){
    if(i == n || cnt == 2) return 0;
    if(cnt > 2) return -1e9;
    
    if(dp[i][flag][cnt] != -1) return dp[i][flag][cnt];

    if(flag == 0 && cnt < 2){ // I can buy or skip 
      return dp[i][flag][cnt] = max(f(i + 1, flag, cnt, prices), -prices[i] + f(i + 1, !flag, cnt, prices));
    }

    // I can sell or skip
    return dp[i][flag][cnt] = max(f(i + 1, flag, cnt, prices), prices[i] + f(i + 1, !flag, cnt + 1, prices));
  }

  int maxProfit(vector<int>& prices) {
    n = prices.size();

    memset(dp, -1, sizeof(dp));
    return f(0, 0, 0, prices);
  }
};


class Solution {
public:
  int n;

  int maxProfit(vector<int>& prices) {
    n = prices.size();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int>(3, 0)));
  
    for(int i = n-1; i >= 0; i--){
      for(int cnt = 1; cnt >= 0; cnt--){

        dp[i][0][cnt] = max(dp[i+1][0][cnt], -prices[i] + dp[i+1][1][cnt]);
        dp[i][1][cnt] = max(dp[i+1][1][cnt], prices[i] + dp[i+1][0][cnt + 1]);
      }
    }
    
    return dp[0][0][0];
  }
};

class Solution {
public:
  int n;

  int maxProfit(vector<int>& prices) {
    n = prices.size();

    vector<vector<int>> next(2, vector<int> (3, 0));

    for(int i = n-1; i >= 0; i--){
      vector<vector<int>> cur(2, vector<int> (3, 0));

      for(int cnt = 1; cnt >= 0; cnt--){
        cur[0][cnt] = max(next[0][cnt], -prices[i] + next[1][cnt]);
        cur[1][cnt] = max(next[1][cnt], prices[i] + next[0][cnt + 1]);
      }

      next = cur;
    }
    
    return next[0][0];
  }
};