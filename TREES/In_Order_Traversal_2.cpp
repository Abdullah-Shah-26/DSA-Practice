/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:  // worst case TC = O(n) traversing each Node
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