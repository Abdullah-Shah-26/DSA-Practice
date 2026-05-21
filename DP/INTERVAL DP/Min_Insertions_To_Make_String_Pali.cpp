#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minInsertions(string s) {
  int n = s.size();

  vector<vector<int>> dp(n + 1, vector<int> (n + 1, 1e9));

  for(int i = 0; i < n; i++){
    dp[i][i] = 0;
  }

  for(int L = 2; L <= n; L++){
    for(int i = 0; i < n - L + 1; i++){
      int j = L + i - 1;

      if(s[i] == s[j]){
        if(L == 2){
          dp[i][j] = 0;
        }
        else{
          dp[i][j] = dp[i + 1][j - 1];
        }
      }
      else{ // s[i] != s[j]
        dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]); 
      }
    }
  }

  return dp[0][n-1];
  }
};