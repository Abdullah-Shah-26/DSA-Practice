#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Return ht if subtree is balanced else -1
  int dfs(TreeNode* root){   
    if(!root) return 0;

    int leftHt = dfs(root->left);
    if(leftHt == -1)
      return -1;

    int rightHt = dfs(root->right);
    if(rightHt == -1)
      return -1;

    if(abs(leftHt - rightHt) > 1) return -1;

    return max(leftHt, rightHt) + 1;
  }

  bool isBalanced(TreeNode* root) {
    return dfs(root) != -1;   
  }
};