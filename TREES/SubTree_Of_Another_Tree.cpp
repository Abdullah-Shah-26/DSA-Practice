#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool solve(TreeNode* p, TreeNode* q){
    if(p == NULL && q == NULL) return true;
    if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
    if(p->val != q->val) return false;

    return solve(p->left, q->left) && solve(p->right, q->right);
  }

  bool isSameTree(TreeNode* p, TreeNode* q){
    return solve(p, q);
  }
  
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
  if(!subRoot) return true;
  if(!root) return false; 

  // Starts here
  bool here = solve(root, subRoot);

  // Left
  bool left = isSubtree(root->left, subRoot);

  // Right
  bool right = isSubtree(root->right, subRoot);

  return here || left || right;
  }
};