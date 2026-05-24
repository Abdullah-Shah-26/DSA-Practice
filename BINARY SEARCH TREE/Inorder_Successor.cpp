// TC = O(N) | SC = O(N)
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  // returns the inorder successor of the TreeNode x in BST (rooted at 'root')
  int inOrderSuccessor(TreeNode *root, TreeNode *x)
  {
    int ans = -1;
    while (root)
    {
      if (x->val >= root->val)
      {
        root = root->right;
      }
      else
      {
        ans = root->val;
        root = root->left;
      }
    }
    return ans;
  }
};