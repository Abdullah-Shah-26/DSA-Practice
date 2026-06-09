#include <bits/stdc++.h>
using namespace std;

// Top Down 
class Solution {
  public:
  
  int n,m;
  int dp[151][151];
  static const int MOD = 1e9 + 7;

  int f(int i, int curGcd, vector<vector<int>> &mat){
    if(i == n)
      return curGcd == 1;

    if(dp[i][curGcd] != -1)
      return dp[i][curGcd];

    int ans = 0;
    for(int j = 0; j < m; j++){
      if(i != 0)
        ans = (ans + f(i + 1, __gcd(curGcd, mat[i][j]), mat)) % MOD;
      else  // i == 0, means our gcd is initalized as sentinel 0, so just pick the guy from 1st row 
        ans = (ans + f(i + 1, mat[i][j], mat)) % MOD;
    }

    return dp[i][curGcd] = ans;
  }

  int countCoprime(vector<vector<int>>& mat) {
    n = mat.size();
    m = mat[0].size();

    memset(dp, -1, sizeof(dp));
    
    return f(0, 0, mat);
  }
};

// Bottom Up
class Solution {
  public:
  int countCoprime(vector<vector<int>>& mat) {
    const int MOD = 1e9 + 7;
    int n = mat.size();
    int m = mat[0].size();
    int maxGcd = 150;

    vector<int> next(maxGcd + 1, 0);

    // Base Case Initialization
    for(int j = 0; j < m; j++)
      next[mat[0][j]]++;
    
    for(int i = 1; i < n; i++){
      vector<int> cur(maxGcd + 1, 0);

      for(int g = 1; g <= maxGcd; g++){
        if(!next[g]) continue;

        for(auto x : mat[i]){
          int nxt = gcd(g, x);
          cur[nxt] = (cur[nxt] + next[g]) % MOD;
        }
      }
      
    swap(next, cur);
    }

    return next[1];
  }

};

// TODO : Use Number Theory