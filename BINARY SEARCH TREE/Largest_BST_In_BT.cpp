// TC = O(N) | SC = O(N)
#include <bits/stdc++.h>
using namespace std;

class NodeValue
{
public:
  int maxNode, minNode, maxSize;

  NodeValue(int minNode, int maxNode, int maxSize)
  {
    this->minNode = minNode;
    this->maxNode = maxNode;
    this->maxSize = maxSize;
  }
};

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
  NodeValue LBST(TreeNode *root)
  {
    if (!root)
    {
      return NodeValue(1e9, -1e9, 0);
    }

    auto left = LBST(root->left);
    auto right = LBST(root->right);

    if (left.maxNode < root->val && root->val < right.minNode)
    {
      return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 1 + left.maxSize + right.maxSize);
    }
    return NodeValue(-1e9, 1e9, max(left.maxSize, right.maxSize));
  }

  // Return the size of the largest sub-tree which is also a BST
  int largestBst(TreeNode *root)
  {
    return LBST(root).maxSize;
  }
};
