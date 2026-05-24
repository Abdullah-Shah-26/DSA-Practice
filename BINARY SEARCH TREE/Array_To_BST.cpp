#include <bits/stdc++.h>
using namespace std;

// TC = O(N) | SC = O(1)

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
  // Create a BST from a sorted array and return its root
  TreeNode *ArrayToBST(vector<int> &ans, int start, int end)
  {
    if (start > end)
    {
      return NULL;
    }

    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(ans[mid]);

    // Build left and right subtrees
    root->left = ArrayToBST(ans, start, mid - 1);
    root->right = ArrayToBST(ans, mid + 1, end);

    return root;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    return ArrayToBST(nums, 0, nums.size() - 1);
  }
};