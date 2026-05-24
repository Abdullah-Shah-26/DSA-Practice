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
class Solution {  //! TC == SC === O(n) - worst case
    public:
        // postorder traversal -  L R N
        void post(TreeNode* root, vector<int> &ans)
        {
            // base 
            if(root == NULL)
            return;
    
            // left
            post(root->left, ans);
    
            // right
            post(root->right, ans);
    
            // Node
            ans.push_back(root->val);
            
        
        }
    
    
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int>ans;
            post(root, ans);
            return ans;
        }
    };