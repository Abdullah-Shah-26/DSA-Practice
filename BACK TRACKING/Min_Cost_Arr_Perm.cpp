class Solution {
public:
    void solve(vector<int>&nums,int score,vector<bool>&vis,vector<int>&perm, vector<int>&resPerm, int &mini, int n){
      if(score > mini){
        return;
      }
      
      if(perm.size() == n){
        score += abs(perm.back() - nums[perm[0]]);
        if(score < mini){
          mini = score;
          resPerm = perm;
        }
      }
      for(int num = 0; num < n ; num++){
        if(!vis[num]){
          vis[num] = 1;
          perm.push_back(num);
          int s = perm.size();
          solve(nums,score + abs(perm[s-2] - nums[perm[s-1]]), vis, perm, resPerm, mini,n);
          vis[num] = 0;
          perm.pop_back();
        }
      }
    }

    vector<int> findPermutation(vector<int>& nums) {
      int n = nums.size();
      vector<int>resPerm;
      vector<int>perm = {0};
      vector<bool>vis(n,0);
      int mini = 1e9;
      int score = 0;
      vis[0] = 1;
      solve(nums,score,vis,perm,resPerm,mini,n);
      return resPerm;   
    }
};