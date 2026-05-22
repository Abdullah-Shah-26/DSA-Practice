#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
  int n = nums.size();

  vector<int> dp(n, 1); // LIS ending at i
  vector<int> cnt(n, 1); // Cnt of LIS ending at i

  // Better path replaces 
  // Equal path accumulate

  for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
      if(nums[j] < nums[i]){
        if(dp[j] + 1 == dp[i]){
          cnt[i] += cnt[j];
        }
        else if(dp[j] + 1 > dp[i]){
          dp[i] = dp[j] + 1;
          cnt[i] = cnt[j];
        }
      }
    }
  }

  int maxi = *max_element(dp.begin(), dp.end());
  int res = 0;

  for(int i = 0; i < n; i++){
    if(dp[i] == maxi){
      res += cnt[i];
    }
  }

  return res;
  }
};