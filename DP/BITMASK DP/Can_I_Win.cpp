#include <bits/stdc++.h>
using namespace std;

//! TC = (N * (2 ^ N)) | SC = O(2 ^ N)

class Solution {
  public:
  int n;
  vector<int> dp;

  bool dfs(int mask, int remaining){
    if(dp[mask] != -1)
      return dp[mask];

    for(int i = 1; i <= n; i++){
      int bit = 1 << (i-1);

      if(bit & mask) // Already used
        continue;

      if(i >= remaining)  
        return dp[mask] = 1; // Can win immediately

      // Force win - means opponent lost 
      if(!dfs(mask | bit, remaining - i)){
        return dp[mask] = 1; 
      }
    }

    return dp[mask] = 0;
  }

  bool canIWin(int maxChoice, int target) {
    if(target <= 0) return true;

    int total = maxChoice * (maxChoice + 1)/2; // Sum = First N natural no's

    if(total < target) // Can never make it
      return false;

    n = maxChoice;
    dp.assign(1 << n, -1);

    return dfs(0, target);
  }
};  