#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);

class TreeNode
{

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
  TreeNode *first;
  TreeNode *prev;
  TreeNode *middle;
  TreeNode *last;

  void inorder(TreeNode *root)
  {
    if (!root)
      return;

    inorder(root->left);

    if (prev && prev->val > root->val)
    {

      // If it's a first violation mark them as first & middle
      if (first == NULL)
      {
        first = prev;
        middle = root;
      }
      else // Second Violation
      {
        last = root;
      }
    }
    prev = root;
    inorder(root->right);
  }

  void recoverTree(TreeNode *root)
  {
    first = middle = last = NULL;
    prev = new TreeNode(INT_MIN);
    inorder(root);

    if (first && last)
      swap(first->val, last->val);
    else if (first && middle)
      swap(first->val, middle->val);
    return;
  }
};