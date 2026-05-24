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
  vector<TreeNode *> findPreSuc(TreeNode *root, int key) {
    TreeNode *succ = NULL;
    TreeNode *pred = NULL;

    TreeNode *cur = root;

    // Find successor: smallest strictly greater than key
    while (cur) {
      if (key >= cur->val) {
        cur = cur->right;
      } else {
        succ = cur;
        cur = cur->left;
      }
    }

    cur = root;

    // Find predecessor: largest strictly smaller than key
    while (cur) {
      if (key <= cur->val) {
        cur = cur->left;
      } else {
        pred = cur;
        cur = cur->right;
      }
    }

    return {pred, succ};
  }
};