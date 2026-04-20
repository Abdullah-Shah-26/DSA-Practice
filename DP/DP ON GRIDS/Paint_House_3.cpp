#include <bits/stdc++.h>
using namespace std;

// Rec + Memo

class Solution {
  public:
    const int INF = 1e9;
    int m,n;
    int dp[101][101][21] = {};

    int solve(int i, int target, int prev, vector<int> &houses, vector<vector<int>> &cost){
      
      if(i == m)
        return target == 0 ? 0 : INF;

      if(target < 0)
        return INF;

      if(dp[i][target][prev] != -1)
        return dp[i][target][prev]; 

      if(houses[i] != 0) // Current house is colored, check if its same as prev
        return dp[i][target][prev] = solve(i + 1, target - (prev != houses[i]), houses[i], houses, cost);

      auto res = INF;

      // Current house not colored try all possible colors 
      for(int col = 1; col <= cost[i].size(); col++){
        res = min(res, cost[i][col - 1] + solve(i + 1, target - (prev != col), col, houses, cost));
      }

      return dp[i][target][prev] = res;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int M, int N, int target) {
    m = M, n = N;      

    memset(dp, -1, sizeof(dp));

    auto res = solve(0, target, 0, houses, cost);

    return res == INF ? -1 : res;
    }
};

//! Bottom Up
//* TC = O(M * T * N^2)

class Solution {
public:
  using ll = long long;
  ll LINF = 1e18; 
  
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) { 
    vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>> (target + 1, vector<ll>(n + 1, LINF)));

    // prev Color
    for(int prev = 0; prev <= n; prev++){
      dp[m][0][prev] = 0; 
    }

    for(int i = m-1; i >= 0; i--){
      for(int t = 0; t <= target; t++){
        for(int prev = 0; prev <= n; prev++){

          // curHouse already colored
          if(houses[i] != 0){
            int col = houses[i];

            int T = t - (prev != col);

            if(T >= 0)
              dp[i][t][prev] = dp[i+1][T][col];
          }
          else{
            ll res = LINF;

            for(int col = 1; col <= n; col++){
              int T = t - (prev != col);

              if(T >= 0) 
                res = min(res, cost[i][col-1] + dp[i+1][T][col]);
            }

            dp[i][t][prev] = res;
          }
        }
      }
    }

  return dp[0][target][0] == LINF ? -1 : dp[0][target][0];
  }
};

//! Space Optimized

class Solution {
public:
  using ll = long long;
  ll LINF = 1e18; 
  
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) { 
    vector<vector<ll>> next(target + 1, vector<ll> (n + 1, LINF));
    vector<vector<ll>> cur(target + 1, vector<ll> (n + 1, LINF));

    // prev Color
    for(int prev = 0; prev <= n; prev++){
      next[0][prev] = 0; 
    }

    for(int i = m-1; i >= 0; i--){
      
      // reset cur before each iteration
      cur.assign(target + 1, vector<ll>(n + 1, LINF));

      for(int t = 0; t <= target; t++){
        for(int prev = 0; prev <= n; prev++){

          // curHouse already colored
          if(houses[i] != 0){
            int col = houses[i];

            int T = t - (prev != col);

            if(T >= 0)
              cur[t][prev] = next[T][col];
          }
          else{
            ll res = LINF;

            for(int col = 1; col <= n; col++){
              int T = t - (prev != col);

              if(T >= 0) 
                res = min(res, cost[i][col-1] + next[T][col]);
            }

            cur[t][prev] = res;
          }
        }

      }
      next = cur;
    }

  return next[target][0] == LINF ? -1 : next[target][0];
  }
};