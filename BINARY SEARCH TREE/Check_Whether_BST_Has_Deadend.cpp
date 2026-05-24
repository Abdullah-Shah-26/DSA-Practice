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
  bool Dead(TreeNode *root, int lower, int upper)
  {
    if (!root) // if its a null - its not a leaf - to dead end kaise hoga
    {
      return 0;
    }

    // leaf node hay
    if (!root->left && !root->right)
    {
      // check if its a dead end
      // range of elements that u cant insert in l or R = 1-1 = 0
      if (root->val == lower + 1 && root->val == upper - 1)
      {
        return 1;
      }
      else
      {
        return 0; // not a dead end
      }
    }
    // check karo ki left and right side mein dead node hay kya

    return Dead(root->left, lower, root->val) ||
           Dead(root->right, root->val, upper);
  }

  bool isDeadEnd(TreeNode *root)
  {
    // Your code here
    return Dead(root, 0, INT_MAX);
  }
};