class Solution {
    public:
      vector<int> leftView(Node *root) {
          // code here
          vector<int>ans;
          // edge case 
          if(root == NULL)
          return ans;
          
          //! Level Order Traversal 
          queue<Node*>q;
          q.push(root);
          
          
          while(!q.empty())
          {
              
              // push first element of each level in ans 
              ans.push_back(q.front()->data);
              int n = q.size();
              
              while(n--) // pop all the elements of that level
              {
                  Node* temp = q.front();
                  q.pop();
                  
                  //if left or  right exist push in q 
                  if(temp->left)
                  q.push(temp->left);
                  
                  if(temp->right)
                  q.push(temp->right);
              }
          }
          return ans;
      }
  };
  //!_______________________________________________________________________________________________________________
  //! can be solved by recursion tooooo


void Lview(Node* root, int level, vector<int> &ans)
{
 if(root == NULL)
 return;
 
 if(level == ans.size()) // yaani we are visiting that level first time and that node push in ans 
 ans.push_back(root->data);
 
 // left jao phir right jao null mile return hojao
 // har recursive call pe next level jaaate yani level++
 Lview(root->left, level + 1, ans);
 Lview(root->right, level + 1, ans);
}

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        // edge case 
        if(root == NULL)
        return ans;
        // using recursion
        Lview(root, 0 , ans);
        return ans;
    }    
       