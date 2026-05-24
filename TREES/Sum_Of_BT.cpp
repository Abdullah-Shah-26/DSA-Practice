//           // method 1 = preorder approach
// void Total(Node *root, int &sum)
// {
//     if(root == NULL)
//     return;
    
//     sum += root->data;
//     //recursive calls to find sum of left and right part 
//     Total(root->left, sum);
//     Total(root->right, sum);
// }
class Solution {
    public:
      int sumBT(Node* root) {
          // code here
          // method - 2 -     recursion
              
              //base case 
              if(root == NULL)
              return 0;
              
              
              // node ki value + muje left part ki value dedo + right part ka total lakar dedo
              
              return (root->data + sumBT(root->left) + sumBT(root->right));
      }
  };