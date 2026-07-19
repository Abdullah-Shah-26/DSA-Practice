#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countDominantNodes(TreeNode *root) {
    if (!root)
      return 0;

    int ans = countDominantNodes(root->left) + countDominantNodes(root->right);
    int maxL = root->left ? root->left->val : 0;
    int maxR = root->right ? root->right->val : 0;

    if (root->val >= max(maxL, maxR))
      ans++;
    else
      root->val = max(maxL, maxR);

    return ans;
  }
};