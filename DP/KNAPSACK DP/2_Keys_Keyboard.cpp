#include <bits/stdc++.h>
using namespace std;

// Rec + Memo

class Solution {
public:
  int dp[1001][1001];
  int f(int curA, int clipA, int n){
    if(curA == n) return 0;
    if(curA > n) return 1e9;
    if(dp[curA][clipA] != -1) return dp[curA][clipA];

    int copyAll = 1 + 1 + f(curA + curA, curA, n);
    int paste = 1 + f(curA + clipA, clipA, n);

    return dp[curA][clipA] = min(paste, copyAll);
  }

  int minSteps(int n) {
  if(n == 1) return 0;

  memset(dp, -1, sizeof(dp));
  return 1 + f(1, 1, n);      
  }
};


// Greedy + Bottom Up - TC = O(N^2)

class Solution {
public:
  int minSteps(int n) {
  if(n == 1) return 0;

  vector<long long> dp(n + 1, 0);
  dp[1] = 0;
  dp[2] = 2; // Need 1 copy + 1 paste

  for(long long i = 3; i <= n; i++){
  long long factor = i / 2;
  
    while(factor >= 1){
      if(i % factor == 0){
        dp[i] = dp[factor] + (i / factor);
        break;
      }

      factor--;
    }
  }

  return dp[n];
  }
};