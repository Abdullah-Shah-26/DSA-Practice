
class Solution { // balance cond ht(l) - ht(r) = 1 , 0 , or -1
    public:
    
    int height(Node* root, bool &valid)
    {
        if(root == NULL) // ht will be 0
        return 0;
        
        int L = height(root->left, valid);
        // if left part mein all nodes are satisfyng balancing cond 
        // then only check right part
        if(valid)
        {
          int R = height(root->right, valid);
          // absolute fun converts -ve to +ve
          if(abs(L-R)>1) // balance cond not satasfied
          valid = 0;
        
          return 1 + max(L,R); 
        }
    // else 
    return -1;
    }
    
      bool isBalanced(Node* root) {
          // Code here
          
          bool valid = 1; // assuming its balance tree initially
          
          height(root , valid);
          return valid;
      }
  };