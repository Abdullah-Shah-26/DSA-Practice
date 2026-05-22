#include <bits/stdc++.h>
using namespace std;

// Rec + Memo

const int MOD = 1e9 + 7;
using ll = long long;

// flag == 1, need ways to make expression true
// flag == 0, need ways to make expression false

ll dp[201][201][2];

ll f(int i, int j, bool flag, string &s){
    if(i > j) return 0;

    if(i == j){
        if(flag == 1) return s[i] == 'T';
        else if(flag == 0) return s[i] == 'F';
    }

    if(dp[i][j][flag] != -1) return dp[i][j][flag];

    ll ways = 0;
    for(int idx = i + 1; idx <= j-1; idx++){
        ll LT = f(i, idx - 1, 1, s);
        ll LF = f(i, idx - 1, 0, s);
        ll RT = f(idx + 1, j, 1, s);
        ll RF = f(idx + 1, j, 0, s);

        if(s[idx] == '&'){
            if(flag) ways += (LT * RT);
            else ways = (ways + (LT * RF) % MOD + (LF * RF) % MOD + (LF * RT) % MOD) % MOD;
        }
        else if(s[idx] == '|'){
            if(flag) ways = (ways + (LT * RT) % MOD + (LF * RT) % MOD + (LT * RF) % MOD) % MOD;
            else ways = (ways + (LF * RF) % MOD) % MOD;
        }
        else if(s[idx] == '^'){
            if(flag) ways = (ways + (LT * RF) % MOD + (LF * RT) % MOD) % MOD;
            else ways = (ways + (LT * RT) % MOD + (LF * RF) % MOD) % MOD;
        }
    }

    return dp[i][j][flag] = ways % MOD;
}

int evaluateExp(string &s) {
    memset(dp, -1, sizeof(dp));
    return f(0, s.size() - 1, 1, s) % MOD;
}

// Bottom Up

const int MOD = 1e9 + 7;
using ll = long long;

// flag == 1, need ways to make expression true
// flag == 0, need ways to make expression false

int evaluateExp(string &s) {
  int n = s.size();

  vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll>(2, 0)));

  // Base Case :
  for(int i = 0; i < n; i++){
    if(s[i] == 'T'){
      dp[i][i][1] = 1;
      dp[i][i][0] = 0;
    }
    else{
      dp[i][i][0] = 1;
      dp[i][i][1] = 0;
    }
  }

  bool flag = 1;

  for(int i = n-1; i >= 0; i--){
    for(int j = i + 1; j < n; j++){
      for(int idx = i + 1; idx <= j - 1; idx+=2){ // Operators are at odd idx
        ll LT = dp[i][idx - 1][1];
        ll LF = dp[i][idx - 1][0];
        ll RT = dp[idx + 1][j][1];
        ll RF = dp[idx + 1][j][0];


        if(s[idx] == '&'){
          dp[i][j][1] = (dp[i][j][1] + (LT * RT) % MOD) % MOD;
          dp[i][j][0] = (dp[i][j][0] + (LT * RF) % MOD + (LF * RT) % MOD + (LF * RF) % MOD) % MOD;
        }
        else if(s[idx] == '|'){
          dp[i][j][1] = (dp[i][j][1] + (LT * RF) % MOD + (LF * RT) % MOD + (LT * RT) % MOD) % MOD; 
          dp[i][j][0] = (dp[i][j][0] + (LF * RF) % MOD) % MOD;
        }
        else if(s[idx] == '^'){
          dp[i][j][1] = (dp[i][j][1] + (LT * RF) % MOD + (LF * RT) % MOD) % MOD;
          dp[i][j][0] = (dp[i][j][0] + (LT * RT) % MOD + (LF * RF) % MOD) % MOD;
        }
      }
    }
  }
  
  return dp[0][n-1][1] % MOD;
}