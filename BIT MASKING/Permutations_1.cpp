#include <bits/stdc++.h>
using namespace std;

//* TC = O(N!) * N [To push into ans]
//* SC = O(N) [Recursion depth]

// mask acts like visited array

class Solution {
  public:
    int n;
    vector<vector<int>> ans;

    void dfs(vector<int> &nums, vector<int>& perm, int mask){

      if(mask == (1 << n) - 1) { // All bits set in mask, means all elements visited 
        ans.push_back(perm);
        return;
      }

      for(int i = 0; i < n; i++){
        if(!(mask & (1 << i))){
          perm.push_back(nums[i]);
          dfs(nums, perm, mask | (1 << i));
          perm.pop_back();
        }
      }

    }

    vector<vector<int>> permute(vector<int>& nums) {
    n = nums.size();
    vector<int> perm;
  
    dfs(nums, perm, 0);

    return ans;
    }
};