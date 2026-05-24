#include <bits/stdc++.h>
using namespace std;

// TC = O(H) | SC = O(1)

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == NULL) {
      return new TreeNode(val);
    }

    TreeNode *cur = root;

    while (true) {
      // Insert in right subtree
      if (cur->val <= val) {
        if (cur->right != NULL) {
          cur = cur->right;
        } else {
          cur->right = new TreeNode(val);
          break;
        }
      }
      // Insert in left subtree
      else {
        if (cur->left != NULL) {
          cur = cur->left;
        } else {
          cur->left = new TreeNode(val);
          break;
        }
      }
    }
    return root;
  }
};
