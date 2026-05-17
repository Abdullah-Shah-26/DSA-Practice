class Solution{
    public:
    
    void inorder(Node* root,vector<int> &ans)
  {
      if(!root)
      return;
      // left 
      inorder(root->left, ans);
      // node 
      ans.push_back(root->data);
      // Right
      inorder(root->right, ans);
  }
  
  void postorder(Node* root, vector<int> &ans, int &index)
  {
      if(!root)
      return;
      
      // left 
      postorder(root->left, ans,index);
      // right
      postorder(root->right, ans, index);
      // Node
      root->data = ans[index];
      index++;
  }
     
      void convertToMaxHeapUtil(Node* root)
      {
          // Inorder traversal nikalo
          vector<int> ans;
          inorder(root,ans);
          // postorder traversal se tree fill karo
      
          int index = 0; // as referance ki kise pehle fill karna hay
          postorder(root, ans, index);
      }    
  };