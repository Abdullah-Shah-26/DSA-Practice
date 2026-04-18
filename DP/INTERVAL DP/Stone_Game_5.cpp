#include <bits/stdc++.h>
using namespace std;

//! Recursion + Memo
//* TC = O(N^2) * N (Trying N splits)
//* SC = O(N^2)

class Solution {
  public:
    int n;
    int dp[501][501];
    int f(int st, int end, vector<int> &stones, vector<int> &pref){
      if(st > end) return 0;

      if(dp[st][end] != -1)
        return dp[st][end];

      int ans = 0;

      for(int k = st; k <= end; k++){
        int LSum = pref[k + 1] - pref[st]; // [st...k]
        int RSum = pref[end + 1] - pref[k + 1]; // [k+1.....end] 

        if(LSum < RSum){
          ans = max(ans, LSum + f(st, k, stones, pref));
        }
        else if(LSum == RSum){
          ans = max({ans, LSum + f(st, k, stones, pref), RSum + f(k + 1, end, stones, pref)});
        }
        else{
          ans = max(ans, RSum + f(k + 1, end, stones, pref));
        }
      }

      return dp[st][end] = ans;
    }
    
    int stoneGameV(vector<int>& stones) {
    n = stones.size();
    memset(dp, -1, sizeof(dp));
    vector<int> pref(n + 1, 0);

    for(int i = 1; i <= n; i++){
      pref[i] = pref[i - 1] + stones[i - 1];
    }

    return f(0, n-1, stones, pref);
    }
};

//! Bottom Up - DP + PrefixSum
//* TC = O(N^3)
//* SC = O(N^2)

class Solution {  
  public:
    int stoneGameV(vector<int>& stones){
    int n = stones.size();

    vector<int> pref(n + 1, 0);

    for(int i = 1; i <= n; i++){
      pref[i] = pref[i-1] + stones[i-1];
    }

    vector<vector<int>> dp(n, vector<int> (n,0));
    // dp[i][j] = max score from subarray from [i....j]

    for(int len = 1; len <= n; len++){
      // len = j-i+1
      // j = len + i - 1
      for(int i = 0; i + len - 1 < n; i++){
        int j = len + i - 1;

        if(len == 1){
          dp[i][j] = 0; 
          continue;
        }

        for(int k = i; k < j; k++){
          
          int LSum = pref[k+1] - pref[i]; // [i....k]
          int RSum = pref[j+1] - pref[k+1]; // [k+1.....j]

          // Take smaller sum & go that side
          // If Equal explore both options & Take maximum

          if(LSum < RSum){
            dp[i][j] = max(dp[i][j], LSum + dp[i][k]);
          }
          else if(LSum == RSum){
            dp[i][j] = max({dp[i][j], LSum + dp[i][k], RSum + dp[k+1][j]});
          }
          else{
            dp[i][j] = max(dp[i][j], RSum + dp[k+1][j]);
          }
        }
      }
    }

    return dp[0][n-1];
    }
};