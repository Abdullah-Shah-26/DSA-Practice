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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution { // method 1 - TC = O(n) SC = O(n)
public:
  void inorder(TreeNode *root, vector<int> &ans) {
    // inorder traversal
    if (!root) {
      return;
    }

    inorder(root->left, ans);  // L
    ans.push_back(root->val);  // N
    inorder(root->right, ans); // R
  }
  // Function to check whether a Binary Tree is BST or not.
  bool isBST(TreeNode *root) {
    vector<int> ans;
    inorder(root,
            ans); // if inorder is in strictly ascending order then its BST

    for (int i = 1; i < ans.size(); i++) {
      if (ans[i] <= ans[i - 1]) // prev should be >= curr
      {
        return 0;
      }
    }

    return 1;
  }
};

//!------------------------------------------------------------------------
class Solution2 {
// method  2 - TC = O(n) SC = O(1)
public:
  bool BST(TreeNode *root, int &prev) {

    if (!root) {
      return 1;
    }

    // left se jo val ayi wo store karo and check if its true then aage bado
    //   bool l = BST(root->left , prev);
    //   if(l == 0)

    if (!BST(root->left, prev)) {
      return 0;
    }

    if (root->val <= prev) {
      return 0;
    }

    // agar left and node pe check hogayi prop prev <= curr and its true
    // update prev before going to right
    prev = root->val;
    return BST(root->right, prev);
  }

  // Function to check whether a Binary Tree is BST or not.
  bool isBST(TreeNode *root) {
    int prev = INT_MIN;
    return BST(root, prev); // func tells if its BST
  }
};