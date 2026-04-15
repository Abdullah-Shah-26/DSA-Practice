#include <bits/stdc++.h>
using namespace std;

//! Rec + Memo
class Solution {
  public: 
    int dp[1002][1002];

    int f(int i, int j, string &s1, string &s2, vector<int> &pref1, vector<int> &pref2){
      if(i == 0) return pref2[j];
      if(j == 0) return pref1[i];

      if(dp[i][j] != -1) return dp[i][j]; 

      if(s1[i-1] == s2[j-1]){
        return f(i-1, j-1, s1, s2, pref1, pref2);
      }

      return dp[i][j] = min(s1[i-1] + f(i-1, j, s1, s2, pref1, pref2), s2[j-1] + f(i, j-1, s1, s2, pref1, pref2));
    }

    int minimumDeleteSum(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int> pref1(n + 1, 0);
    for(int i = 1; i <= n; i++){
      pref1[i] = pref1[i-1] + s1[i - 1];
    }    

    vector<int> pref2(m + 1, 0);
    for(int i = 1; i <= m; i++){
      pref2[i] = pref2[i-1] + s2[i - 1];
    }

    if(n == 0) return pref2[m-1];
    else if(m == 0) return pref1[n-1];
    else if(s1 == s2) return 0;

    memset(dp, -1, sizeof(dp));

    return f(n, m, s1, s2, pref1, pref2);
    }
};

//! BottomUp  
class Solution {
  public: 
    int minimumDeleteSum(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int> pref1(n + 1, 0);
    for(int i = 1; i <= n; i++){
      pref1[i] = pref1[i-1] + s1[i - 1];
    }    

    vector<int> pref2(m + 1, 0);
    for(int i = 1; i <= m; i++){
      pref2[i] = pref2[i-1] + s2[i - 1];
    }

    if(n == 0) return pref2[m-1];
    else if(m == 0) return pref1[n-1];
    else if(s1 == s2) return 0;

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    for(int i = 0; i <= n; i++){
      dp[i][0] = pref1[i];
    }

    for(int j = 0; j <= m; j++){
      dp[0][j] = pref2[j];
    }

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){

        if(s1[i-1] == s2[j-1]){
          dp[i][j] = dp[i-1][j-1];
        }
        else{
          dp[i][j] = min(s1[i-1] + dp[i-1][j], s2[j-1] + dp[i][j-1]);
        }
      }
    }

    return dp[n][m];
    }
};

//! Space Optimization
class Solution {
  public: 
    int minimumDeleteSum(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int> pref1(n + 1, 0);
    for(int i = 1; i <= n; i++){
      pref1[i] = pref1[i-1] + s1[i - 1];
    }    

    vector<int> pref2(m + 1, 0);
    for(int i = 1; i <= m; i++){
      pref2[i] = pref2[i-1] + s2[i - 1];
    }

    if(n == 0) return pref2[m];
    else if(m == 0) return pref1[n];
    else if(s1 == s2) return 0;

    vector<int> prev(m + 1, 0);

    for(int j = 0; j <= m; j++){
      prev[j] = pref2[j];
    }

    for(int i = 1; i <= n; i++){
      vector<int> cur(m + 1, 0);
      cur[0] = pref1[i]; 

      for(int j = 1; j <= m; j++){
        if(s1[i-1] == s2[j-1]){
          cur[j] = prev[j-1];
        }
        else{
          cur[j] = min(s1[i-1] + prev[j], s2[j-1] + cur[j-1]);
        }
      }

      prev = cur;
    }

    return prev[m];
    }
};