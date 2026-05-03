#include <bits/stdc++.h>
using namespace std;

// For variable ht = Use BitMask DP 
// Here ht = 2 so we use simple DP

// Rec + Memo

class Solution {
  public:
    const int MOD = 1e9 + 7;
    int dp[1001];

    int solve(int n){
      if(n == 1 || n == 2) return n;
      if(n == 3) return 5; 

      if(dp[n] != -1) return dp[n];

      return dp[n] = ((1LL * 2 * solve(n-1)) % MOD + solve(n-3)) % MOD;
    }

    int numTilings(int n) {
      memset(dp, -1, sizeof(dp));

      return solve(n);      
    }
}; 

// Bottom Up

class Solution {
  public:
    const int MOD = 1e9 + 7;

    int numTilings(int n) {
      if(n == 1 || n == 2) return n;
      if(n == 3) return 5; 
      
      vector<int> dp(n+1, 0);

      dp[1] = 1;
      dp[2] = 2;
      dp[3] = 5;

      for(int i = 4; i <= n; i++)
        dp[i] = ((1LL * 2 * dp[i-1]) % MOD + dp[i-3]) % MOD;    
    
      return dp[n];
    }
}; 

// Space Optimized

class Solution {
  public:
    const int MOD = 1e9 + 7;
    using ll = long long;

    int numTilings(int n) {

    if(n == 1 || n == 2) return n;
    if(n == 3) return 5;

    // dp[1], dp[2], dp[3]
    ll prev3 = 1, prev2 = 2, prev1 = 5;

    for(int i = 4; i <= n; i++){
      ll cur = (2 * prev1 + prev3) % MOD;
    
      prev3 = prev2;
      prev2 = prev1;
      prev1 = cur;
    }

    return prev1;
    }
};