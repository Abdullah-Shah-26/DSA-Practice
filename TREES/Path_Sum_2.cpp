#include <bits/stdc++.h>
using namespace std;

// TC = O(N) = SC
class Solution{
  public:

  vector<vector<int>> ans;

  void dfs(TreeNode* node, int target, vector<int> &path){
    if(!node) return;

    path.push_back(node->val);
    target -= node->val;
    
    // Base Case :
    if(!node->left && !node->right && target == 0){
      ans.push_back(path);
    }

    dfs(node->left, target, path);
    dfs(node->right, target, path);

    path.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode* root, int target) {
      vector<int> path;
      dfs(root, target, path);
      return ans;
    }
};