class Solution { // TC = O(N)  // SC = O(N)
    public:
    
    void find(Node* root, int pos , int &l)
    {
        if(!root)
        return;
        l = max(pos, l); // if we are moving left then pos + 1 , right is const 
        // since we are moving along same diagonal
        
        find(root->left, pos + 1, l);
        find(root->right, pos , l);
        
    }
    // func adds the node's value to ans[pos], which represents the current diagonal.
    void findDig(Node *root , int pos , vector<vector<int>> &ans){
        if(root == NULL)
        return;
        
        ans[pos].push_back(root->data); 
        findDig(root->left, pos + 1, ans);
        findDig(root->right, pos , ans);
        
        
    }
      vector<int> diagonal(Node *root) {
          // code here
          // we will use recursion here and 2 d array to store elements of same diagonal 
          int l = 0; 
          // func to find left most diagonal - l
          find(root, 0, l);
          
          vector<vector<int>>ans(l+1); // adding 1 since we are starting form 0
          
          findDig(root, 0, ans);
          
          vector<int>temp;
          // need ans in 1 d array
          for(int i = 0; i< ans.size(); i++)
              for(int j = 0; j< ans[i].size(); j++)
                  temp.push_back(ans[i][j]);
                  
                  
          return temp;
      }
  };