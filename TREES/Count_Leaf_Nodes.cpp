//! method 1 - preorder traversal
// void CountLeaf(Node* root, int &count)
// {   //base case
//     if(root == NULL) //root hi null hay to we cant go left or right
//     return;
    
     // leaf Node 
//     if(root->left == NULL && root->right == NULL)
//     {
//         count++;
//         return;
//     }
    
    // Non leaf 
//     CountLeaf(root->left, count);
//     CountLeaf(root->right, count);
    
// }
class Solution {
    public:
      // Function to count the number of leaf nodes in a binary tree.
      int countLeaves(Node* root) {
          // int count = 0;
          // return count;
          
          //! method 2 - recursion
          
          //base case
          if(root == NULL)
          return 0;
          
          // leaf node hay 
          if(!root->left && !root->right)
          return 1;
          // agar non leaf node hay count start kardo ki left & right mein kitne leaf nodes hay 
          return(countLeaves(root->leaf) + countLeaves(root->right));
      }
  };