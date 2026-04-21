#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
  public:
    int dfs(TreeNode* node, int maxSoFar){
      if(!node) return 0;

      int cnt = 0;
      if(node->val >= maxSoFar){
        cnt = 1;
      }

      maxSoFar = max(maxSoFar, node->val);

      cnt += dfs(node->left, maxSoFar);
      cnt += dfs(node->right, maxSoFar);

      return cnt;  
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};