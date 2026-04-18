#include <bits/stdc++.h>
using namespace std;

//! Rec + Memo

class Solution {
  public:
    int dp[100001];

    int f(int n){

      if(n <= 0) return 0;
      if(dp[n] != -1) return dp[n];

      for(int i = 1; i*i <= n; i++){
        if(f(n-(i*i)) == 0) // Bob Lost - means Alice Won 
          return dp[n] = 1;
      }

      return dp[n] = 0;
    }

    bool winnerSquareGame(int n) {
      memset(dp, -1, sizeof(dp));

      return f(n);
    }
};

//! BottomUp
//* TC = O(N * sqrt(N))

class Solution {
  public:
  bool winnerSquareGame(int n) {
  vector<bool> dp(n + 1, 0);
  // dp[i] = can alice force win using current i stones
  // She can if bob lost atleast once in past 

  for(int i = 1; i <= n; i++){
    dp[i] = false; // Assume losing
    for(int k = 1; k*k <= i; k++){
      if(!dp[i - (k*k)]){
        dp[i] = true;
        break; // Early break to avoid overwriting
      }
    }
  }
  
  return dp[n];
  }
};