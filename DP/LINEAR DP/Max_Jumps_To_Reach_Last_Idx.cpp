#include <bits/stdc++.h>
using namespace std;

// TC = O(N) = SC - Bottom Up

class Solution {
  public:
    int maximumJumps(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> dp(n + 1, INT_MIN);
    dp[n-1] = 0; // Base Case    

    for(int i = n-2; i >= 0; i--){
      int ans = INT_MIN;
      for(int j = i + 1; j < n; j++){
        if(abs(nums[i] - nums[j]) <= target && dp[j] != INT_MIN){
          ans = max(1 + dp[j], ans);
        }
      }
      dp[i] = ans;
    }

    return dp[0] < 0 ? - 1 : dp[0];
    }
};