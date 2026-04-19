#include <bits/stdc++.h>
using namespace std;

//* TC = O(N!) * N [To push into ans]
//* SC = O(N) [Recursion depth]

class Solution {
  public:
    int n;
    vector<vector<int>> ans;
    
    void dfs(vector<int> &nums, vector<int> &perm, int mask){
      
      if(mask == (1 << n) - 1){ // visited all
        ans.push_back(perm);
        return;
      }
    
      for(int i = 0; i < n; i++){

        if(mask & (1 << i)) 
          continue;
        
        // Use duplicates in index order 
        // Ex : [1a 1b 2]
        // Cannot make perm like [1b 1a 2] 
        if(i > 0 && nums[i] == nums[i-1] && (!(mask & (1 << (i-1)))))
          continue;


        perm.push_back(nums[i]);
        dfs(nums, perm, mask | (1 << i));
        perm.pop_back();
      }
    
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
    n = nums.size();    
    vector<int> perm;

    // Adj duplicate comparision only works when array is sorted
    sort(begin(nums), end(nums));

    dfs(nums, perm, 0);

    return ans;
    }
};