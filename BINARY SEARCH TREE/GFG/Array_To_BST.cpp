class Solution {
    public: // preorder - Node left right
      void ArrayToBST(vector<int>&arr, int start, int end, vector<int> &ans)
      {
          if(start > end) // to kuch create nai hoga return
          return;
          
          int mid = start + (end - start)/2;
          ans.push_back(arr[mid]);
          
          // phir left jao 
          ArrayToBST(arr, start, mid -1, ans);
          // then right 
          ArrayToBST(arr, mid + 1, end, ans);
      }
    
      vector<int> sortedArrayToBST(vector<int>& nums) {
          // no need to create BST we know jo mid hay vo node ban raha hay pehle so just push in ans 
      vector<int>ans; // preorder store hoga
      ArrayToBST(nums, 0, nums.size() - 1, ans);
      return ans;
      }
  };
  //!---------------------------------------------  q updated
  class Solution {
    public:
    // just create a bst and return its root - ans vector ka mid nikalo and node create karo
    Node* ArrayToBST(vector<int>& ans, int start ,int end)
    {
        if(start > end)
        return NULL; // no need to create node there
        
        int mid = start + (end - start)/2;
        Node* root = new Node(ans[mid]); // creating a new BST node
        
        // address return kardena create hone ke baad
        root->left = ArrayToBST(ans, start , mid - 1);
        root->right = ArrayToBST(ans, mid+1 , end);
        
        return root;
        
    }
      Node* sortedArrayToBST(vector<int>& nums) {
          // Code here
          return ArrayToBST(nums, 0, nums.size() - 1);
      }