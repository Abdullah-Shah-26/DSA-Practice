class Solution {
    public:
        void minDist(TreeNode* root, int &prev, int &ans)
        {
            if(!root)
            return;
            // pehle left side jao
            minDist(root->left, prev , ans);
    
            // if condition to avoid overflow - EDGE CASE
            if(prev != INT_MIN) 
            {// prev will only be updated if curr diffrence is minimum
            ans = min(ans, root ->val - prev);
            }
            //right jane se pehle update prev
            prev = root->val;
            minDist(root->right, prev, ans);
        }
    
        int minDiffInBST(TreeNode* root) {
            // we'll just calulate the min dist between prev and curr node istead of
            // calculating all distances
            int prev = INT_MIN;
            int ans = INT_MAX;
    
            minDist(root, prev, ans);
            return ans;
        }
    };