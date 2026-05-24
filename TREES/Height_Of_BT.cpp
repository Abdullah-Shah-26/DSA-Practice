class Solution {
    public:
      // Function to find the height of a binary tree.
      int height(Node* root) {
          // RECURSION
          
          // according to this question ht = nodes from root to bottom most node
          if(root == NULL)
          return 0;
          
          // 1 + left ya right mein se jo max ht hay wo add kardo 
          return 1 + max(height(root->left) , height(root->right));
          
      }
      
  };

  //!--------------------------Question got updated --------- ht = no of edges between root node and bottom most node 

  class Solution {
    public:
        // Function to find the height of a binary tree.
        int height(Node* root) {
            // Base case: if the tree is empty, return -1 (since an empty tree has no edges)
            if(root == NULL)
                return -1;
            
            // Directly return 1 + max(left subtree height, right subtree height)
            return 1 + max(height(root->left), height(root->right));
        }
    };
    