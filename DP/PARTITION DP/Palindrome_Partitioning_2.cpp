#include <bits/stdc++.h>
using namespace std;

// TC = O(N * N) = SC

class Solution {
  public:
    int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool> (n, false));
    vector<int> cuts(n + 1, 0);

    for(int i = 0; i < n; i++)
      dp[i][i] = true;

    for(int len = 2; len <= n; len++){
      // len = j - i + 1
      // j = i + len - 1
      for(int i = 0; i < n - len + 1; i++){
        int j = i + len - 1;

        if(s[i] == s[j]){
          if(len == 2){
            dp[i][j] = true;
          }
          else {
            dp[i][j] = dp[i+1][j-1];
          }
        }
      }
    }

    for(int i = n-1; i >= 0; i--){
      int minCost = INT_MAX;
      for(int j = i; j < n; j++){
        if(dp[i][j]){
          int cost = 1 + cuts[j + 1];
          minCost = min(minCost, cost);
        } 
      }
      cuts[i] = minCost;
    }
  
    return cuts[0] - 1; // Our code does partition at the end so we get an extra partition    
    }
};