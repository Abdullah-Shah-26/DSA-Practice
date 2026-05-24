class Solution {
    public:
    // func to find max path sum
    int PathSum(Node *root, int &sum){
        // node doesnt exist
        if(!root)
        return 0;
        
        // if its leaf node return its val
        if(!root->left && !root->right)
        return root->data;
        
        // find path sum of l and R recursively
        int left = PathSum(root->left, sum);
        int right = PathSum(root->right, sum);
        
        // node ke left and right both exist
        if(root ->left && root ->right){
            // since its path sum we will add nodes between 2 special nodes
        
            sum = max (sum, root -> data + left + right );
            // and return only sum of max path 
            return root->data + max(left, right);
        }
        
        // node ka only left exist
        if(root -> left)
        return root -> data + left;
        
        // node ka only right exist
        if(root -> right)
        return root -> data + right;
        
        
    }
    
    
        int maxPathSum(Node* root)
        {
            int sum = INT_MIN;
            PathSum(root,sum);
            // to handle edge case
            // edge case - if our specail root node has either only left or right it becomes a special node
        // so we'll store the final val of path sum returned by our func and check if root is special
        
            int val = PathSum(root, sum);
            if(root -> left && root->right)
            return sum;
            // else 
            return max(sum, val);
            
        }
    };