#include <bits/stdc++.h>
using namespace std;

// tc = o(N) -  sc = O(n) - rec call stack wc mein tree is growing on single side

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
  TreeNode *LCA(TreeNode *root, TreeNode *n1, TreeNode *n2)
  {
    if (!root) // common ancetor doesnt exist
    {
      return NULL;
    }

    if (root->val > n1->val && root->val > n2->val) // dono left mein exist karte root ke
    {
      return LCA(root->left, n1, n2);
    }

    else if (root->val < n1->val && root->val < n2->val) // dono right mein exist karte
    {
      return LCA(root->right, n1, n2);
    }

    else // ek root exist in left and other in right so this is the common root node to both of them
    {
      return root; // return karvado ans mein
    }
  }
};