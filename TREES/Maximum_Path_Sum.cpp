#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int dfs(TreeNode* node, int &maxi){
    if(!node)
     return 0;

    int left = dfs(node->left, maxi);
    int right = dfs(node->right, maxi);

    if(left < 0)
      left = 0;
    
    if(right < 0)
      right = 0;
    
    maxi = max(maxi, left + right + node->val);
    
    return node->val + max(left, right);
  }

  int maxPathSum(TreeNode* root) {
  int maxi = -1e9;

  dfs(root, maxi);
  
  return maxi;
  }
};