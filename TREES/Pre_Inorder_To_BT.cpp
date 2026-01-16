class Solution {
  public:
    Node* buildTreee(vector<int>&preorder, int preSt, int preEnd, vector<int>&inorder, int inSt, int inEnd, map<int,int>&m)
    {
        if(preSt > preEnd || inSt > inEnd)
        return NULL;
        
        Node* root = new Node(preorder[preSt]);
        
        int inRoot = m[root->data];
        int numsOnLeft = inRoot - inSt;
        
        root->left = buildTreee(preorder, preSt + 1, preSt + numsOnLeft, inorder, inSt, inRoot - 1,m);
         
        root->right = buildTreee(preorder, preSt + numsOnLeft + 1, preEnd, inorder, inRoot + 1,inEnd, m);
        
        return root;
    }
  
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
    map<int,int>m;
    
    for(int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;    
    }
    Node* root = buildTreee(preorder, 0, preorder.size()-1,inorder, 0, inorder.size()-1, m); 
    return root;
    }
};