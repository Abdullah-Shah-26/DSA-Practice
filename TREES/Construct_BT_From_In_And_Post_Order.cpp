#include <bits/stdc++.h>
using namespace std;

// Postorder tells which node comes next
// Inorder tells where left & right split happens
// Post-Order : Left Right Root 
// So we need to create -> Root Right Left since we are traversing Postorder backwards
class Solution{
  public:

  unordered_map<int,int> pos;

  TreeNode* solve(int st, int end, int &idx, vector<int> &inorder, vector<int> &postorder){
    if(st > end)
      return NULL;
      
    int rootVal = postorder[idx];
    int i = pos[rootVal];
    idx--;

    TreeNode* root = new TreeNode(rootVal);
    root->right = solve(i + 1, end, idx, inorder, postorder);
    root->left = solve(st, i - 1, idx, inorder, postorder);

    return root;
  }

  TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder){
    int n = inorder.size();

    for(int i = 0; i < n; i++){
      pos[inorder[i]] = i;
    }

    int idx = n-1;

    return solve(0, n-1, idx, inorder, postorder);
  }
};
