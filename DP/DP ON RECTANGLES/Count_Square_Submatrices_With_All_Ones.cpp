#include <bits/stdc++.h>
using namespace std;

// TC = O(N * M) = SC

class Solution {
public:
  int countSquares(vector<vector<int>>& mat) {
  int n = mat.size();
  int m = mat[0].size();   

  vector<vector<int>> dp(n, vector<int> (m, 0));

  // Filling 1st col
  for(int i = 0; i < n; i++){
    dp[i][0] = mat[i][0];
  }

  // Filling 1st row
  for(int j = 0; j < m; j++){
    dp[0][j] = mat[0][j];
  }

  // dp[i][j] = largest square ending at (i,j)
  for(int i = 1; i < n; i++){
    for(int j = 1; j < m; j++){
      if(mat[i][j] == 0) {
        dp[i][j] = 0;
      }
      else{
        dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
      }
    }
  }

  int sum = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      sum += dp[i][j];
    }
  }

  return sum;
  }
};

