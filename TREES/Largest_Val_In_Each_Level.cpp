class Solution
{
    public:
    vector<int> largestValues(Node* root)
    {
        //WE WILL USE TREE TRAVERSAL METHOD
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    
    
    while(!q.empty())
    {
        // until q becomes empty we will calculate the max node and only push it in ans
        int n = q.size();
        int maxi = INT_MIN;
        
        for(int i =0; i<n; i++)
        {
            Node* temp = q.front();
            q.pop();
            maxi  = max(temp->data, maxi);
            
            // if left node exists - push in q
            if(temp->left != NULL)
            q.push(temp->left);
            
            // if right node exists - push in q
            if(temp->right != NULL)
            q.push(temp->right);
        }
        
        ans.push_back(maxi);
    }
    
    return ans;
    }
};
