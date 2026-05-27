#include <bits/stdc++.h>
using namespace std;

// Preorder tells which node comes next
// Inorder tells where left/right split happens

class Solution {
public:
  unordered_map<int,int> pos; // rootVal, Idx in Inorder
  TreeNode* solve(int st, int end, int &idx, vector<int> &preorder, vector<int> &inorder){
    if(st > end)
      return NULL;

    int rootVal = preorder[idx];
    int i = pos[rootVal];

    idx++;

    TreeNode* root = new TreeNode(rootVal);
    root->left = solve(st, i - 1, idx, preorder, inorder);
    root->right = solve(i + 1, end, idx, preorder, inorder);

    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();

    for(int i = 0; i < n; i++){
      pos[inorder[i]] = i;
    }

    int idx = 0;
    return solve(0, n-1, idx, preorder, inorder);    
  }
};