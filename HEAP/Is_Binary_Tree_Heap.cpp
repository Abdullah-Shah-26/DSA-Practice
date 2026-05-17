class Solution {
    public:  // TC  O(N)
    int count(Node* root)
    {
        if(!root)
        return 0;
        
        return 1 + count(root->left) + count(root->right);
    }
    
    bool CBT(Node* root, int index, int total_nodes)
    {
        if(!root)
        return 1;
        
        if(index >= total_nodes)
        return 0;
        
       // left and right bhi check karlo - dono CBT rahna 
       return CBT(root->left, 2 * index + 1, total_nodes) && CBT(root->right, 2 * index + 2, total_nodes);
        
    }  
    
    bool MaxHeap(Node* root)
    {
    if(!root)
    return true;
    
    if(root->left)// left child exist 
    {
        if(root->data < root->left->data ) // parent >= child rahna
        return false;      
    }
    if(root->right)// right child exist 
    {
        if(root->data < root->right->data)
        return false;
    }
    
    // check recursively for left and right subtree
    return MaxHeap(root->left) && MaxHeap(root->right);
    }
    
    
    
    
    
    bool isHeap(struct Node* tree) {
      //  if total no of nodes >= index - then its not Complete Binary tree - (not heap)
      
      // count Nodes in tree
          int num = count(tree);
      // CBT hay ya nai
      if(!CBT(tree, 0, num)) // if not CBT return false
      return 0;
      // Parent should be >= child 
      return MaxHeap(tree);
     
      }
  };