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
  TreeNode *build(int &i, int arr[], int upperBound, int n)
  {
    if (i == n || arr[i] > upperBound)
    {
      return NULL;
    }
    TreeNode *root = new TreeNode();
    root->val = arr[i++];
    root->left = build(i, arr, root->val, n);
    root->right = build(i, arr, upperBound, n);
    return root;
  }

  TreeNode *Bst(int pre[], int size)
  {
    int i = 0;
    return build(i, pre, INT_MAX, size);
  }
};
