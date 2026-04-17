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
        
        if(person == 1){
          result = max(result, stones + f(0, i + x, max(M,x), piles));
        } 
        else{
          result = min(result, f(1, i + x, max(M,x), piles));
        }
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