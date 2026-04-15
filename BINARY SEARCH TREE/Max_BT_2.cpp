#include <bits/stdc++.h>
using namespace std;

//! Recursive

class Solution {
  public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);

    if(val > root->val){
      TreeNode* newRoot = new TreeNode(val);
      newRoot->left = root;
      return newRoot;
    } 
    else{
      root->right = insertIntoMaxTree(root->right, val);
    }   
    
    return root;
    }
};

//! Iterative

class Solution {
  public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);

    if(val > root->val){
      TreeNode* newRoot = new TreeNode(val);
      newRoot->left = root;
      return newRoot;
    } 

    TreeNode *cur = root;
    while(cur->right && cur->right->val > val){
      cur = cur->right;
    }

    TreeNode* node = new TreeNode(val);
    node->left = cur->right;
    cur->right = node;

    return root;
    }
};