class Solution {
public:
    int solve(int idx, vector<int>&arr, int tar,vector<vector<int>>&dp)
    {
      if(tar == 0){
        return 1;
      }
      if(idx >= arr.size() || tar < 0)
      {
        return 0;
      }

      if(dp[idx][tar] != -1)
      return dp[idx][tar];

      int take = solve(0,arr, tar - arr[idx],dp);
      int notTake = solve(idx + 1, arr, tar,dp);

      return dp[idx][tar] = take + notTake;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        return solve(0,nums,target,dp);
    }
};

