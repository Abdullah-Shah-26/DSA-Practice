#include <bits/stdc++.h>
using namespace std;

//! Recursion + Memo
class Solution {
  public:
    int dp[501][501];
    int f(int i, int j, string &s1, string &s2){
      if(i < 0) return j + 1; 
      if(j < 0) return i + 1;

      if(dp[i][j] != -1) return dp[i][j];

      if(s1[i] == s2[j]){
        return f(i-1, j-1, s1, s2);
      }

      return dp[i][j] = 1 + min(f(i-1, j, s1, s2), f(i, j-1, s1, s2));
    }

    int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    if(n == 0) return m;
    else if(m == 0) return n;
    else if(s1 == s2) return 0;

    memset(dp, -1, sizeof(dp));
    
    return f(n-1,m-1,s1,s2);   
    }
};

//! Bottom Up
class Solution {
  public:
    int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    if(n == 0) return m;
    else if(m == 0) return n;
    else if(s1 == s2) return 0;

    vector<vector<int>> dp(n+1, vector<int> (m+1,0));

    for(int i = 0; i <= n; i++){
      dp[i][0] = i;
    }
    for(int j = 0; j <= m; j++){
      dp[0][j] = j;
    }

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        if(s1[i-1] == s2[j-1]){
          dp[i][j] = dp[i-1][j-1];
        }
        else{
          dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
      }
    }

    return dp[n][m];
    }
};

//! Space Optimized
class Solution {
  public:
    int minDistance(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    if(n == 0) return m;
    else if(m == 0) return n;
    else if(s1 == s2) return 0;

    vector<int> prev(m + 1, 0);

    for(int j = 0; j <= m; j++){
      prev[j] = j;
    }

    for(int i = 1; i <= n; i++){
      vector<int> cur(m + 1,0);
      cur[0] = i;
      for(int j = 1; j <= m; j++){
        if(s1[i-1] == s2[j-1]){
          cur[j] = prev[j-1];
        }
        else{
          cur[j] = 1 + min(prev[j], cur[j-1]);
        }
      }
      prev = cur;
    }

    return prev[m];
    }
};