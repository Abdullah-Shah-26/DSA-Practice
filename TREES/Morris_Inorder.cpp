#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
  vector<int> ans;
  
  TreeNode* cur = root;

  while(cur != NULL){
    
    if(cur->left == NULL){ // Left Node Right
      ans.push_back(cur->val);
      cur = cur->right;
    }
    else{
      TreeNode* leftChild = cur->left;

      while(leftChild->right != NULL){
        leftChild = leftChild->right;
      }

      leftChild->right = cur; // Thread connected

      TreeNode* temp = cur;
      cur = cur->left;
      temp->left = NULL;
    }
  }

  return ans;    
  }
};