#include <bits/stdc++.h>
using namespace std;

// Rec + Memo 

class Solution {
public:
    vector<int> dp;
    int f(int i, vector<int>&arr, int k){
      if(i >= arr.size()) return 0;
      if(dp[i] != -1) return dp[i];

      int res = 0;
      int curMax = 0;
      
      for(int j = i; j < arr.size() && j - i + 1 <= k; j++){
        curMax = max(curMax, arr[j]);

        res = max(res, curMax * (j - i + 1) + f(j + 1, arr, k));
      }

      return dp[i] = res;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
    dp.assign(arr.size() + 1, -1);
    return f(0, arr, k);
    }
};

// Tabulation

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for(int i = n - 1; i >= 0; i--){
      
      int len = 0;
      int res = 0;
      int maxi = 0;

      for(int j = i; j < min(i + k, n); j++){
        len++;
        maxi = max(maxi, arr[j]);
        res = max(res, len * maxi + dp[j + 1]);
      }

      dp[i] = res;
    }

    return dp[0];
    }
};