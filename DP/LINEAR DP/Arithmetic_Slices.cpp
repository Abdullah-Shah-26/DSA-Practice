#include <bits/stdc++.h>
using namespace std;

// TC = O(N) = SC

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
  int n = nums.size();
  if(n < 3) return 0;    

  int ans = 0;
  vector<int> dp(n, 0);
  
  for(int i = 2; i < n; i++){
    if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
      dp[i] = dp[i-1] + 1;
      ans += dp[i];
    }
  }

  return ans;
  }
};

// TC = O(1) = SC

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
  int n = nums.size();
  if(n < 3) return 0;    

  int ans = 0;
  int prev = 0;
  
  for(int i = 2; i < n; i++){
    if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
      prev = prev + 1;
      ans += prev;
    }
    else{
      prev = 0;
    }
  }

  return ans;
  }
};