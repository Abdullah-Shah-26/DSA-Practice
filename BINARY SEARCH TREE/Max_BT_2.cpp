// TC = O(N) | SC = O(N)
#include <bits/stdc++.h>
using namespace std;

//! Recursive

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
  TreeNode *insertIntoMaxTree(TreeNode *root, int val)
  {
    if (!root)
    {
      return new TreeNode(val);
    }

    if (val > root->val)
    {
      TreeNode *newRoot = new TreeNode(val);
      newRoot->left = root;
      return newRoot;
    }
    else
    {
      root->right = insertIntoMaxTree(root->right, val);
    }

    return root;
  }
};

//! Iterative

class Solution2
{
public:
  TreeNode *insertIntoMaxTree(TreeNode *root, int val)
  {
    if (!root)
    {
      return new TreeNode(val);
    }

    if (val > root->val)
    {
      TreeNode *newRoot = new TreeNode(val);
      newRoot->left = root;
      return newRoot;
    }

    TreeNode *cur = root;
    while (cur->right && cur->right->val > val)
    {
      cur = cur->right;
    }

    TreeNode *node = new TreeNode(val);
    node->left = cur->right;
    cur->right = node;

    return root;
  }
};