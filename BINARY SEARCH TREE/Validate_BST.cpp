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
  bool isValid(TreeNode *root, long long mini, long long maxi)
  {
    if (!root)
    {
      return 1;
    }

    if (root->val >= maxi || root->val <= mini)
    {
      return 0;
    }

    return isValid(root->left, mini, root->val) && isValid(root->right, root->val, maxi);
  }

  bool isValidBST(TreeNode *root)
  {
    return isValid(root, LLONG_MIN, LLONG_MAX);
  }
};