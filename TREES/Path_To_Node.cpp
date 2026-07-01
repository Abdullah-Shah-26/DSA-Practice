#include <bits/stdc++.h>
using namespace std;

/**
  * Definition for binary tree
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */ 

bool f(TreeNode* root, int val , vector<int>&res)
{
    if(!root) return false;
    
    res.push_back(root->val);
    
    if(root->val == val ) return true;
    
    if(f(root->left, val, res) || f(root->right, val,res))
    
    return true;
    
    res.pop_back();
    return false;
}
 
 
vector<int> Solution::solve(TreeNode* root, int B){
    vector<int>res;
    if(!root) 
    return res;
    
    bool ans = f(root, B, res);
    return res;
}
 