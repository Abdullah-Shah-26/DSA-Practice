#include <bits/stdc++.h>
using namespace std;

//! Rec + Memo

class Solution {
public:
int n;

int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
    if (j < 0 || j >= n) return 1e9;          // invalid
    if (i == n - 1) return mat[i][j];         // base

    if (dp[i][j] != -1) return dp[i][j];      // memo

    int down      = f(i + 1, j, mat, dp);
    int leftDiag  = f(i + 1, j - 1, mat, dp);
    int rightDiag = f(i + 1, j + 1, mat, dp);

    return dp[i][j] = mat[i][j] + min({down, leftDiag, rightDiag});
}

int minFallingPathSum(vector<vector<int>>& mat) {
    n = mat.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int ans = 1e9;
    for (int j = 0; j < n; j++) {
        ans = min(ans, f(0, j, mat, dp));
    }
    return ans;
}
};

//! Bottom Up

class Solution {
  public:
  const int INF = 1e9;
  int minFallingPathSum(vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e9));

    for(int j = 0; j < n; j++){
      dp[0][j] = mat[0][j]; 
    }

    for(int row = 1; row < n; row++){
      for(int col = 0; col < n; col++){

        int up = dp[row-1][col];
        int left = INF, right = INF;

        if(col - 1 >= 0){
          left = dp[row-1][col-1];
        }
        if(col + 1 < n){
          right = dp[row-1][col+1];
        }

        dp[row][col] = mat[row][col] + min({up, left, right});
      }
    }

    return *min_element(dp[n-1].begin(), dp[n-1].end());
  }
};

//! InPlace

class Solution {
  public:
  const int INF = 1e9;
  int minFallingPathSum(vector<vector<int>>& mat) {
    int n = mat.size();

    for(int row = 1; row < n; row++){
      for(int col = 0; col < n; col++){

        int up = mat[row-1][col];
        int left = col ? mat[row-1][col-1] : INF; 
        int right = col + 1 < n ? mat[row-1][col+1] : INF;

        mat[row][col] = mat[row][col] + min({up, left, right});
      }
    }

    return *min_element(mat[n-1].begin(), mat[n-1].end());
  }
};