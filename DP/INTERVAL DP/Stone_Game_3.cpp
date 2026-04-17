#include <bits/stdc++.h>
using namespace std;

//* Solving like stone game 2
//* Rec + Memo
class Solution {
  public:
    int n;
    int dp[2][50005];
    int f(int person, int i, vector<int> &piles){
      
      if(i >= n){
        return 0; 
      }

      if(dp[person][i] != -1)
        return dp[person][i];

      int result = (person == 1) ? INT_MIN : INT_MAX;
      int stones = 0;
      
      for(int x = 1; x <= min(3, n-i); x++){
        stones += piles[i + x - 1];

        if(person == 1)
          result = max(result, stones + f(0, i + x, piles));
        else
          result = min(result, f(1, i + x, piles));
      }

      return dp[person][i] = result;
    }


    string stoneGameIII(vector<int>& piles) {
    n = piles.size();

    int sum = 0;
    for(int x: piles){
      sum += x;
    }

    memset(dp, -1, sizeof(dp));

    vector<vector<int>> dp(2, vector<int>(n + 1, 0));

    for(int person = 0; person < 2; person++){
      for(int i = 0; i <= n-1; i++){

        int result = (person == 1) ? INT_MIN : INT_MAX;
        int stones = 0;

        for(int x = min(3, n-i); x >= 1; x--){
          stones += piles[i + x - 1];

          if(person == 1)
            result = max(result, stones + dp[0][i-x]);
          else
            result = min(result, dp[1][i-x]);

        } 

        dp[person][i] = result;
      }
    }

    int alice = dp[1][0];
    int bob = sum - alice;

    if(alice > bob){
      return "Alice";
    }
    else if(alice <  bob){
      return "Bob";
    }
    else
      return "Tie";
    }
};

//! Another Approach - Maximize Differance b/w Alice & BoB
//* We can compress dimension since we just have 2 players and they play alternatively

class Solution {
  public:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& stones){
      
      if(i >= n){
        return 0;
      }

      if(dp[i] != -1) 
        return dp[i];

      int ans = INT_MIN;
      int sum = 0;

      for(int x = 1; x <= min(3, n - i); x++){
        sum += stones[i + x - 1];
        ans = max(ans, sum - solve(i + x, stones)); // MyGain - Opponent Response from next state
      }
    
      return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stones) {
    n = stones.size();

    dp.assign(n+1, 0);

    for(int i = n-1; i >= 0; i--){

      int ans = INT_MIN;
      int sum = 0;

      for(int x = 1; x <= min(3, n - i); x++){
        sum += stones[i + x - 1];
        ans = max(ans, sum - dp[i + x]);

      }

      dp[i] = ans;
    }

    int diff = dp[0];

    if(diff == 0){
      return "Tie";
    }
    else if(diff > 0){
      return "Alice";
    }
    else{
      return "Bob";
    }
    
    }
};