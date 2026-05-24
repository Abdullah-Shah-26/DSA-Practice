class Solution {
    public:
      vector<vector<int>> levelOrder(Node *root) {
          // Your code here
          // edge case - if tree is empty
          if(root == NULL)
          return {}; 
          
          queue<Node*>q;
          q.push(root); // initally pushing root address in q 
          vector<vector<int>> ans;
          Node* temp; // stores the address of a particular Node and helps to check if left right child nodes exists for that particular node
          
      while(!q.empty())
          {   
              // nodes at current level
              int levelSize = q.size(); // no of nodes at each level = size of q
              vector<int>level; // stores values of nodes at current level
              
          for(int i = 0; i<levelSize; i++){
               temp = q.front(); 
               q.pop();
              
              
               level.push_back(temp->data); // push node ki value in level wala vector 
               // which stores values of a particular level
  
              // if left side exists then q mein daldo
               if(temp->left)
               q.push(temp->left);
  
                //also if right side exists then q mein daldo
               if(temp->right)
               q.push(temp->right);
  
          }
          
          ans.push_back(level);
          }
          return ans;
      }
  
  };