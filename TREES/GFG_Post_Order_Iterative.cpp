class Solution{
    public:
    vector<int> postOrder(Node* root){// lRN - we will put NRL in stack and then reverse it to get LRN
         // we will use stack
        stack<Node*> s;
        s.push(root); // root ko initially stack mein dalo
        
        vector<int> ans;
        
        while(!s.empty()) 
        {
            Node* temp = s.top();
            s.pop();
            ans.push_back(temp->data);
            // if left or right exist exist push in stack 
            //*** pehle left dalo then right kyo ki pehle right acces karna hay 
          
            if(temp->left)
            s.push(temp->left);
            
              if(temp->right)
            s.push(temp->right);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
