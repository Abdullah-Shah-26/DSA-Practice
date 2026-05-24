class Solution{
    public: // TC = o(N)
     // sc = O(h) or O(n) - worst case // height of stack = ht of BT 
    vector<int> preOrder(Node* root)
    {
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
            //*** pehle right dalo then left kyo ki pehle left acces karna hay 
            if(temp->right)
            s.push(temp->right);
            
            if(temp->left)
            s.push(temp->left);
        }
        return ans;
    }
};