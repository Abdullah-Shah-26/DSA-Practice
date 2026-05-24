#include <bits/stdc++.h>
using namespace std;

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
  TreeNode *deleteNode(TreeNode *root, int target) {
    if (!root)
      return NULL;

    // Search left subtree
    if (root->val > target) {
      root->left = deleteNode(root->left, target);
      return root;
    }
    // Search right subtree
    else if (root->val < target) {
      root->right = deleteNode(root->right, target);
      return root;
    }
    // Target found
    else {
      // Case 1: Leaf node
      if (!root->left && !root->right) {
        delete root;
        return NULL;
      }
      // Case 2: Only left child
      else if (!root->right) {
        TreeNode *temp = root->left;
        delete root;
        return temp;
      }
      // Case 2: Only right child
      else if (!root->left) {
        TreeNode *temp = root->right;
        delete root;
        return temp;
      }
      // Case 3: Two children
      else {
        // Find in-order predecessor (greatest element in left subtree)
        TreeNode *child = root->left;
        TreeNode *parent = root;

        while (child->right) {
          parent = child;
          child = child->right;
        }

        if (root != parent) {
          parent->right = child->left;
          child->left = root->left;
          child->right = root->right;
          delete root;
          return child;
        } else {
          child->right = root->right;
          delete root;
          return child;
        }
      }
    }
  }
};