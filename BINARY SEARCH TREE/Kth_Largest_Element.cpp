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
  // we will reverse inorder trqversal _ LNR _ RNL to visit nodes
  // in descending order
  void Klargest(TreeNode *root, int &k, int &ans)
  {
    if (!root)
    {
      return;
    }

    // pehle right jao
    Klargest(root->right, k, ans);
    k--; // k decrease kardiya kyu ki mein uss node ko access karne wala hoon

    if (k == 0) // ans mil chuka hay
    {
      ans = root->val;
    }

    if (k <= 0) // then left check karne ki zarurat nai hay
    {
      return;
    }

    // else left jao agao k 0 nai hua to
    Klargest(root->left, k, ans);
  }

  int kthLargest(TreeNode *root, int k)
  {
    int ans;
    Klargest(root, k, ans);
    return ans;
  }
};