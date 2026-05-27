#include <bits/stdc++.h>
using namespace std;

class Solution {
public:  // TC = O(n) traversing each Node
// SC = O(n)  -- recursive call stack 
// Inorder - L N R 
    void Inorder(TreeNode* root, vector<int> &ans)
    {
        //base case
        if(root == NULL)
        return;

        // left
        Inorder(root->left, ans);

        // Node
        ans.push_back(root->val);

        // right
        Inorder(root->right , ans);

    }


    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        Inorder(root , ans);
        return ans;
    }
};