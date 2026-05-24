
class Solution {
    public:
  //   //!  method 1 using pre order traversal 
  //     void Total(Node *root, int &count)
  //     {
  //         if(root == NULL)
  //         return;
          
  //         count++;
  //         Total(root->left,count);
  //         Total(root->right,count);
          
  //     }
      int getSize(Node* root) {
          // METHOD 2     USING RECURSION
          // base case
          if(root == NULL)
          return 0;
          
          return (1+ getSize(root->left) + getSize(root->right));
          // 1 + muje left wale part ka size batade + right wale part ka size batade
          
          
      }
  };