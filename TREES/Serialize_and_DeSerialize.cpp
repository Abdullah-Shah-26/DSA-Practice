class Solution {
  public:
    vector<int> serialize(Node *root) {
    if(!root) return {};
    vector<int>arr;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* curNode = q.front();
        q.pop();
        
        if(!curNode)
           arr.push_back(-1); 
        else
           arr.push_back(curNode->data);
            
        if(curNode)
        {
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }
    return arr;
    } 

    int idx = 0;
    Node *deSerialize(vector<int> &arr) {
    if(arr.size() == 0) return NULL;
    
    int i = 0;
    Node* root = new Node(arr[i++]);
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty() && i < arr.size())
    {
        Node* cur = q.front();
        q.pop();
        
        if(arr[i] != -1)
        {
            cur->left = new Node(arr[i]);
            q.push(cur->left);
        }
        i++;
        if(arr[i] != -1)
        {
            cur->right = new Node(arr[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
    }
};