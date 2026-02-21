class Solution {
  public:
    // tc = o(n ^ 2) avg and sc = o(n)
    
    //func to find pos of nodes of post in inorder 
    int find(int in[], int target, int start, int end)
    {  
    
        for(int i = start ; i <= end ; i++)
        {
            if(in[i] == target)
            return i; // returns its position
        }
        return -1;
    }
    // func to build tree
    Node* Tree(int in[], int post[], int InStart, int InEnd, int &index)
    {
        // base case - jaise hi instart crose inend
        if(InStart > InEnd)
        return NULL;
        
        Node* root = new Node(post[index]);
        //post ke node ki pos Inorder mein find kar
        int pos = find(in, post[index], InStart, InEnd);
        
        // isme reverse jaainge 
        // pehle right part build karo
        index--;// Move index before passing it recursively
        root->right = Tree(in, post, pos + 1,InEnd,  index);
        // // then left-
        // root->left = Tree(in, post, InStart, pos -1, index - (InEnd - Pos)-1 );
        
        
        root->left = Tree(in, post, InStart, pos - 1, index);
        return root;
      }
    
    
    
    
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> in, vector<int> post) {
        // code here
        int n = in.size();
        
        int index = n-1; // post order index reverse jaare 
         // passing st and ending inorder and post ka end
       return Tree(in.data(), post.data() , 0 , n-1, index);
        
    }
};
