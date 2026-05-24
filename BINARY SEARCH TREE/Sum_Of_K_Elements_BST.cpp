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

void Ksum(TreeNode *root, int &sum, int &k) // Tc = O(n)  SC = O(n)
{
  if (!root)
  {
    return;
  }

  // inorder traversal karinge until k = 0 --
  // till we find sum of k smallest elements

  // pehle left jao
  Ksum(root->left, sum, k);
  k--; // k left se vapas aaya decrease
  if (k >= 0)
  {
    sum += root->val; // sum mein element add kardena
  }

  if (k <= 0) // ab check karne ki zarurat nai hay
  {
    return;
  }

  // fir right jao
  Ksum(root->right, sum, k);
}

int sum(TreeNode *root, int k)
{
  int sum = 0;
  Ksum(root, sum, k);
  return sum;
  // Your code here
}