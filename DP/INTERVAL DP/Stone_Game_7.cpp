#include <bits/stdc++.h>
using namespace std;

//! Rec + Memo

class Solution {
  public:
    int dp[1001][1001];
        int f(int i, int j, vector<int> &piles, vector<int> &pref){
      if(i > j) 
        return 0;

      if(dp[i][j] != -1)  
        return dp[i][j];

      // score = sum[i+1.....j]
      int pickL = (pref[j+1] - pref[i+1]) - f(i+1, j, piles, pref);
      // score = sum[i.....j-1]
      int pickR = (pref[j-1+1] - pref[i]) - f(i, j-1, piles, pref);

      return dp[i][j] = max(pickL, pickR);
    }

    bool stoneGameVII(vector<int>& piles) {
      int n = piles.size();

      vector<int> pref(n + 1, 0);

      for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + piles[i-1];
      }

      memset(dp, -1, sizeof(dp));

      return f(0, n-1, piles, pref);
    }
};

//! Bottom Up - DP + PrefixSum

class Solution {
public: 
  int stoneGameVII(vector<int>& piles) {
    int n = piles.size();

    vector<int> pref(n + 1, 0);

    for(int i = 1; i <= n; i++){
      pref[i] = pref[i-1] + piles[i-1];
    }

    // dp[i][j] = maxScore diff in subarr[i...j] (currPlayer - opponent)
    vector<vector<int>> dp(n + 1, vector<int> (n + 1,0));

    for(int len = 1; len <= n; len++){
      // len = j-i+1
      // j = len+i-1
      for(int i = 0; len + i - 1 < n; i++){
        int j = len + i - 1;

        if(i == j){
          dp[i][j] = 0; 
          continue;
        }

        int total = pref[j+1] - pref[i];

        int pickL = (total - piles[i]) - dp[i+1][j];
        int pickR = (total - piles[j]) - dp[i][j-1];

        dp[i][j] = max(pickL, pickR);
      }
    }

  return dp[0][n-1];
  }
};

//! Space Optimization

class Solution {
public: 
  int stoneGameVII(vector<int>& piles) {
    int n = piles.size();

    vector<int> pref(n + 1, 0);

    for(int i = 1; i <= n; i++){
      pref[i] = pref[i-1] + piles[i-1];
    }

    vector<int> prev(n + 1, 0);

    for(int i = n-1; i >= 0; i--){
    vector<int> cur(n, 0);

    for(int j = i; j < n; j++){
        if(i == j){
            cur[j] = 0;
            continue;
        }

        int total = pref[j+1] - pref[i];

        int pickL = (total - piles[i]) - prev[j];
        int pickR = (total - piles[j]) - cur[j-1];

        cur[j] = max(pickL, pickR);
      }

      prev = cur;
    }

  return prev[n-1];
  }
};