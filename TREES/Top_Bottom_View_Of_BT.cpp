class Solution {
    public:
      void find(Node* root, int pos, int &l , int &r)
      {
          // func to find pos of Nodes
          if(root == NULL)
          return;
          
          l = min(pos, l);
          r = max(pos, r);
          
          //recursively call for L and R part
          find(root->left, pos-1, l, r);
          find(root->right, pos +1, l, r);
          
      }
      
      void Tview(Node *root, int pos, vector<int> &ans, vector<int> &level, int l)// passed root ka level l = 0
      {
          //base case 
          if(root == NULL)
          return;
      
      if(level[pos] > l)
      { // ans ke ander lv update tabhi hoga when curr lv chota ayega jo waha par already stored hay
          ans[pos] = root->data;
          level[pos] = l;
      }
      //recursively call for left & right
      Tview(root->left, pos-1, ans, level, l+1);
      Tview(root->right, pos+1, ans, level, l+1);
          
          
      }
      
      
       // Function to return a list of nodes visible from the top view
      // from left to right in Binary Tree.
      vector<int> topView(Node *root) {
  // we'll use recursion 
    int l =0; 
    int r = 0;
    find(root, 0, l, r);
      
      
      vector<int> ans(r-l+1);
      // LOGIC
      // ans vector mein value vo hi fill karinge jiska level kam hoga 
      //same idx hone ke baad bhi
      vector<int> level(r-l+1,INT_MAX);
      // 
      Tview(root, -1*l, ans, level, 0); // Normalized ya shifted postion -1*(left most node ki pos)
      return ans;
      
      
      }
  };
  
  
  
  
 //! error at random test case - top view method - level order traversal 
          // if(root == NULL)
          // return {};
          // // we will use level order traversal
          // // initializing left & right most node ki pos with 0 before finding them
          // int l = 0 , r = 0;
          // find(root, 0, l ,r );
          
          // vector<int> ans(r-l+1);// size of arr == right most node - left most node pos + 1
          // vector<bool>filled(r-l+1, 0); // to know that we have visited that node once and pos is filled in ans arr
          
          // // 2 queues 
          
          // queue<Node*>q; // normal used for level order traversal
          // queue<int>index; // to store index of Nodes  since we are checking if the pos is filled
          
          // q.push(root);
          // index.push(-l*1); // since we are shifing postions to match them with idx values
          
          // while(!q.empty())
          // {
          //     Node* temp = q.front();
          //     q.pop();
              
              
          //     int pos = index.front();
          //     index.pop();
              
          //     if(!filled[pos])
          //     { // pos khali hay to mark visited and node in ans arr in that pos 
          
          //         filled[pos] = 1;
          //         ans[pos] = temp->data;
                  
                  
          //         // if left / right exist push in q along with pos in idx q
          //         if(temp->left)
          //         {
          //             q.push(temp->left);
          //             index.push(pos - 1);
                      
                      
          //         }
          //         if(temp->right)
          //         {
          //             q.push(temp->right);
          //             index.push(pos + 1);
          //         }
                  
          //     }
          // }
          // return ans;
    //! error at random test case - bottom view      
          class Solution {
            public:
              void find(Node* root, int pos, int &l , int &r)
              {
                  // func to find pos of Nodes
                  if(root == NULL)
                  return;
                  
                  l = min(pos, l);
                  r = max(pos, r);
                  
                  //recursively call for L and R part
                  find(root->left, pos-1, l, r);
                  find(root->right, pos +1, l, r);
                  
              }
              
              void Bview(Node *root, int pos, vector<int> &ans, vector<int> &level, int l)// passed root ka level l = 0
              {
                  //base case 
                  if(root == NULL)
                  return;
              
              if(level[pos] < l)
              { // ans ke ander lv update tabhi hoga when curr lv bada ayega jo waha par already stored hay
              // since its bottom view neeche ke level wale dhak dete upar walo ko same pos raha to 
                  ans[pos] = root->data;
                  level[pos] = l;
              }
              //recursively call for left & right
              Bview(root->left, pos-1, ans, level, l+1);
              Bview(root->right, pos+1, ans, level, l+1);
                  
                  
              }
              
              
               // Function to return a list of nodes visible from the bottom view
              // from left to right in Binary Tree.
              vector<int> bottomView(Node *root) {
          // we'll use recursion 
            int l =0; 
            int r = 0;
            find(root, 0, l, r);
              
              
              vector<int> ans(r-l+1);
              // LOGIC
              // ans vector mein value vo hi fill karinge jiska level zyada hoga 
              //same idx hone ke baad bhi
              vector<int> level(r-l+1,INT_MIN);
              // 
              Bview(root, -1*l, ans, level, 0); // Normalized ya shifted postion -1*(left most node ki pos)
              return ans;
              
              
              }
          };
          