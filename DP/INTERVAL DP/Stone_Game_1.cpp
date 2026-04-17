#include <bits/stdc++.h>
using namespace std;

//* Recursion + Memo
//* TC = O(N*N) + recStack | SC = O(N*N)

class Solution {
  public:
    int n;
    int dp[501][501];
    int f(int i, int j, vector<int>& a){
      if(i > j) return 0;
      if(i == j) return a[i];

      if(dp[i][j] != -1) return dp[i][j];

      int pickL = a[i] + min(f(i+2, j, a), f(i+1, j-1, a));
      int pickR = a[j] + min(f(i+1, j-1, a), f(i, j-2, a));

      return dp[i][j] = max(pickL, pickR);
    }

    bool stoneGame(vector<int>& a) {
    n = a.size();

    int sum = 0;
    for(int x : a) sum += x;

    memset(dp, -1, sizeof(dp));

    int p1 = f(0, n-1, a);    
    int p2 = sum - p1;

    return p1 >= p2;
    }
};

//* dp[i][j] = maxScore player 1 can obtain from [i....j]

class Solution {
  public:
    bool stoneGame(vector<int>& a) {
    int n = a.size();

    int sum = 0;
    for(int x : a) sum += x;

    vector<vector<int>> dp(n, vector<int> (n,0));

    for(int len = 1; len <= n; len++){
      // len = j-i+1
      // j = len+i-1
      for(int i = 0; len + i - 1 < n; i++){
        int j = len + i - 1;

        if(len == 1){ // means (i == j)
          dp[i][j] = a[i];
        } 
        else if(len == 2){
          dp[i][j] = max(a[i], a[j]);
        } 
        else{
        int pickL = a[i] + min(dp[i+2][j], dp[i+1][j-1]);
        int pickR = a[j] + min(dp[i+1][j-1], dp[i][j-2]);

        dp[i][j] = max(pickL, pickR);
        }
      }
    }

    int p1 = dp[0][n-1];    
    int p2 = sum - p1;

    return p1 >= p2;
    }
};