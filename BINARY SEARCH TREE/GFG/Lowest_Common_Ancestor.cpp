// tc = o(N) -  sc = O(n) - rec call stack wc mein tree is growing on single side
class Solution {
    public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          if(!root)   // common ancetor doesnt exist
          return NULL;
          
          if(root->data > n1->data && root->data > n2->data) // dono left mein exist karte root ke
          return LCA(root->left, n1, n2);
          
          else if(root->data < n1->data && root->data < n2->data )// dono right mein exist karte 
          return LCA(root->right, n1, n2);
          
          else // ek root exist in left and other in right so this is the common root node to both of them
          return root; // return karvado ans mein
          
      }
  };