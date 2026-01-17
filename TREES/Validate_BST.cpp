class Solution {
public:

    bool isValid(TreeNode* root, long long mini, long long maxi)
    {
      if(!root)
      return 1;

      if(root->val >= maxi || root->val <= mini)
      return 0;

      return isValid(root->left, mini, root->val) && isValid(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};