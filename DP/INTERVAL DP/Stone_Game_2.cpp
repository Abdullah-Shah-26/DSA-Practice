#include <bits/stdc++.h>
using namespace std;

//* Rec + Memo

class Solution {
  public:
    int n;
    int dp[2][101][101]; 

    int f(int person, int i, int M, vector<int> &piles){
      if(i >= n){
        return 0; // No Stones Left
      }
      
      if(dp[person][i][M] != -1) return dp[person][i][M];

      // Alice will maximize score
      // Bob will try to minimize her score
      int result = (person == 1) ? -1 : INT_MAX; 
      int stones = 0; 

      for(int x = 1; x <= min(2*M, n-i); x++){
        stones += piles[i + x - 1];
        
        if(person == 1)
          result = max(result, stones + f(0, i + x, max(M,x), piles));
        else
          result = min(result, f(1, i + x, max(M,x), piles));
      }

      return dp[person][i][M] = result;
    }

    int stoneGameII(vector<int>& piles) {
      n = piles.size();
      memset(dp, -1, sizeof(dp));
      // 1 = Alice
      // 2 = Bob
      return f(1, 0, 1, piles);
    }
};


//! DP Bottom UP

/*
 Alice + Bob = Total
 Alice - Bob = Diff 

 2*Alice = Total + Diff
 Alice = (Total + Diff)/2
*/

class Solution {
  public:
    int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

    for(int i = n-1; i >= 0; i--){
      for(int M = 1; M <= n; M++){

        int res = INT_MIN;
        int stones = 0;

        for(int x = 1; x <= 2*M && i + x <= n; x++){
          stones += piles[i + x - 1];

          int opponent = (i + x < n) ? dp[i + x][max(M,x)] : 0; 
          res = max(res, stones - opponent);
        }

        dp[i][M] = res;
      }
    }    

    int total = accumulate(piles.begin(), piles.end(), 0);
    int diff = dp[0][1];

    return (total + diff)/2;
    }
};
