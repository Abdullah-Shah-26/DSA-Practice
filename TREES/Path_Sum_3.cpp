#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(N)
class Solution {
  public: 
    int ans = 0;
    unordered_map<long long, int> m;
  
    void dfs(TreeNode* node, long long curSum, int target){
      if(!node) return;

      // Extend curr path
      curSum += node->val;

      // Cnt paths ending at curr node
      ans += m[curSum - target];

      // add curr prefix sum
      m[curSum]++;

      dfs(node->left, curSum, target);
      dfs(node->right, curSum, target);

      // backtrack
      m[curSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
      // empty prefix
      m[0] = 1;

      dfs(root, 0, targetSum);

      return ans;      
    }
};