//gfg
class Solution { // tc = o(n ^ 2) // sc = o(n)
    public:
    
    //func to find pos of nodes of pre in inorder 
    int find(int in[], int target, int start, int end)
    {
        for(int i = start; i <= end; i++)
        {
            if(in[i] == target)
              return i; // returns its postion 
        }
        return -1;
    }
    
     // func to build tree
    Node* Tree(int in[], int pre[], int InStart, int InEnd, int &index)
    {
        // base case - jaise hi inst will cross inend 
        if(InStart > InEnd)
        return NULL;
        
        Node* root = new Node(pre[index]);
        int pos = find(in, pre[index], InStart, InEnd);// pre ke Node ki pos INorder mein dhoondo
        
        index++; // Preorder index ko badhao
        
        // first left part ko build karo and return its address
        root->left = Tree(in, pre, InStart, pos-1, index); // kuch elements root ke left gai 
       
       // then right part ko
       root->right = Tree(in, pre , pos+1, InEnd , index); // kuch right
        
        return root; // of BT
    }
    
    
      // Function to build the tree from given inorder and preorder traversals
      Node *buildTree(vector<int> &in, vector<int> &pre) {
        // code here
          int n = in.size();
          int index = 0; // Preorder index
          
         // passing st and ending inorder and pre ka 
         return Tree(in.data(), pre.data(), 0, n-1, index);
      }
  };
  //vector<int> stores elements dynamically, but your function expects int[], which is a raw C-style array.
  //.data() provides a pointer to the first element of the vector, so it works like an array.
  

  