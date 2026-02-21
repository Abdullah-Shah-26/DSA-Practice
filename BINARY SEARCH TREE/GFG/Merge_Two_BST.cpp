class Solution { // TC = O(N) // SC = O(N)
    public:
      void inorder(Node* root, vector<int>& ans)
      {
          if(!root)
          return;
          
          /// L N R 
          inorder(root->left, ans);
          ans.push_back(root->data);
          inorder(root->right, ans);
          
      }
      // Function to return a list of integers denoting the node
      // values of both the BST in a sorted order.
      vector<int> merge(Node *root1, Node *root2) {
     
          vector<int>ans1;
          vector<int>ans2;
       // traverse using inorder in both BST and store in ans 1 and 2
          inorder(root1, ans1);
          inorder(root2, ans2);
          
          // we will merge both of these arrays in sorted order using 2 pointers 
          vector<int>ans;
          
          int i =0;
          int j =0;
          
          while(i < ans1.size() && j < ans2.size())
          {
              if(ans1[i] < ans2[j])
              ans.push_back(ans1[i++]);
              
              else
              ans.push_back(ans2[j++]);
          }
          
          // now abhi ek array pehle complete hogaya dusra bachgaya
          
          while(i < ans1.size())
          {
              ans.push_back(ans1[i]);
              i++;
          }
          
          while(j < ans2.size())
          {
              ans.push_back(ans2[j]);
              j++;
          }
          return ans;
      }
  };
  //! approach 2

  class Solution {
    public:
      // Function to return a list of integers denoting the node
      // values of both the BST in a sorted order.
      vector<int> merge(Node *root1, Node *root2) {
          // Your code here
          //! Iterative approach 
          // Using 2 stacks - inorder traversal
          vector<int>ans;
          
          stack<Node*>s1;
          stack<Node*>s2;
          
          // helper func to push all left nodes of subtree in stack
          auto pushleft = [](Node* root, stack<Node*> &s){
              while(root)
              {
                  s.push(root);
                  root = root->left;
              }
          };
          
          // first push all left nodes in stack from root
          pushleft(root1, s1);
          pushleft(root2, s2);
          
          while(!s1.empty() || !s2.empty()){
              
              // handling edge case where one BST gets exhausted before another
              if(s1.empty())
              {
                  ans.push_back(s2.top()->data);
                  Node* temp = s2.top();
                  s2.pop();
                  pushleft(temp->right, s2);
                  continue; // avoids unnecessary checks
              }
              else if(s2.empty()){
                  ans.push_back(s1.top()->data);
                  Node* temp = s1.top();
                  s1.pop();
                  pushleft(temp->right, s1);
                  continue; 
              }
              
              
              Node* node1 = s1.top();
              Node* node2 = s2.top();
              
              if(node1->data < node2->data){
             
                // push smaller in ans
                // and pop from s1 and 
                // right jao root ke and uske saare left s1 mein dalo
                
                  ans.push_back(node1->data);
                  s1.pop();
                  pushleft(node1->right, s1);
                  
              }
              else if(node1->data == node2->data)
              { // dono stacks ke top elements equal hay
                  ans.push_back(node1->data);
                  ans.push_back(node2->data);
                  s1.pop();
                  s2.pop();
                  pushleft(node1->right, s1);
                  pushleft(node2->right, s2);
              }
              else{
                  // s1.top>s2.top
                  ans.push_back(node2->data);
                  s2.pop();
                  pushleft(node2->right, s2);
                  
                 }
                 
          
              
            }
            
  
          return ans;
      }
  };