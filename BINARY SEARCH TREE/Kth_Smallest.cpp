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
  int kthSmallest(TreeNode *root, int k)
  {
    int ans = -1;
    TreeNode *cur = root;
    while (cur)
    {
      if (cur->left == NULL)
      {
        if (--k == 0)
        {
          ans = cur->val;
        }
        cur = cur->right;
      }
      else
      {
        TreeNode *prev = cur->left;

        while (prev->right && prev->right != cur)
        {
          prev = prev->right;
        }

        if (prev->right == NULL)
        {
          prev->right = cur;
          cur = cur->left;
        }
        else
        {
          prev->right = NULL;
          if (--k == 0)
          {
            ans = cur->val;
          }
          cur = cur->right;
        }
      }
    }
    return ans;
  }
};
