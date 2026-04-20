#include <bits/stdc++.h>
using namespace std;

//! Rec + Memo

class Solution {
  public:
    int n;
    using ll = long long;
    ll dp[100001][4][4];

    //           i,      i-1,      n-(i+1)
    ll solve(int i, int prev1, int prev2, vector<vector<int>> &cost){
      if(i >= n/2) return 0; // works only when n is even
      if(dp[i][prev1+1][prev2+1] != -1) return dp[i][prev1+1][prev2+1];

      ll res = LLONG_MAX;

      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          if(j != k && j != prev1 && k != prev2){
            res = min(res, 
              cost[i][j] + 
              cost[n-i-1][k] +
              solve(i+1, j, k, cost));
          }
        }
      }

      return dp[i][prev1+1][prev2+1] = res;
    }

    long long minCost(int _n, vector<vector<int>>& cost) {
    n = _n;
    memset(dp, -1, sizeof(dp));

    return solve(0, -1, -1, cost);
    }
};


//! Bottom Up

class Solution {
  public:
    using ll = long long;
    const ll LINF = 1e18;

    long long minCost(int n, vector<vector<int>>& cost) {
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(4, vector<ll> (4, LINF)));

    for(int i = n/2; i <= n; i++){
      for(int j = 0; j < 4; j++){
        for(int k = 0; k < 4; k++){
          dp[i][j][k] = 0;
        }
      }
    }

    // dp[idx][prev1][prev2]
    // Initally prev1 = -1, prev2 = -1
    // Shift Idx prev1 = 0, prev2 = 0;
    
    for(int i = n/2 - 1; i >= 0; i--){
    
      for(int prev1 = -1; prev1 < 3; prev1++){
        for(int prev2 = -1; prev2 < 3; prev2++){

          ll best = LINF;

          for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){

              if(j != k && j != prev1 && k != prev2){
                best = min(best, 
                cost[i][j] + 
                cost[n-i-1][k] + 
                dp[i+1][j+1][k+1]
                );
              }
            }
          }

          dp[i][prev1 + 1][prev2 + 1] = best;
        }
      }
    }

    return dp[0][0][0];
    }
};