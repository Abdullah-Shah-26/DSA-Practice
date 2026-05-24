// TC = O(N) | SC = O(N)
#include <bits/stdc++.h>
using namespace std;

int n1, n2; // global values banado

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
  void find(TreeNode *root, vector<int> &ans)
  {
    if (!root)
    {
      return;
    }

    // root range mein hay kya check karo
    if (root->val > n1 && root->val > n2) // root ka data range se bada hay go to left
    {
      find(root->left, ans);
    }

    else if (root->val < n1 && root->val < n2) // root ka data range se chota hay go to right
    {
      find(root->right, ans);
    }

    else
    { // root range mein hay then uske left and right subtree mein dekho and L N R (sorted )order mein ans mein dalo

      find(root->left, ans);    // l
      ans.push_back(root->val); // N
      find(root->right, ans);   // R
    }
  }
};