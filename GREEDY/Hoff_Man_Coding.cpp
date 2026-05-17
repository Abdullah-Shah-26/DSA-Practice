class Solution {
  public:
  // Node class 
    class Node{
            
            public:
            
            int freq;
            char c;
            Node *left, *right;
            
            Node(int frequency, char name)
            {
                freq = frequency;
                c = name;
                left = right = NULL;
            }
        };
        
        // Customized comparision 
        class comp{
            public:
            bool operator()(Node *a , Node *b){
                //Kya a and b ka order sahi hay a before b if a < b
                return a->freq > b->freq; // in heap reverse this logic
            }
        };
        
        
          // Traverse and store code for each character in map
    void preorder(Node* root, string temp, unordered_map<char, string> &codeMap) {
        if (!root)
            return;

        // If it's a leaf node, store the code for character
        if (!root->left && !root->right) {
            codeMap[root->c] = temp;
            return;
        }

        preorder(root->left, temp + '0', codeMap);
        preorder(root->right, temp + '1', codeMap);
    }

  
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        
    // Build The Huff man Tree
    
    // Build the min heap (frequency ke basis pe)
    priority_queue<Node *, vector<Node * >,comp>pq;
    for(int i = 0; i < N; i++)
    {// Dynamic memory allocation
        Node *root = new Node(f[i], S[i]);
        pq.push(root);
    }
    
    while(pq.size() > 1)
    {
        // take the 2 smallest out and add their freq 
        Node *first = pq.top();
        pq.pop();
        
        Node *second = pq.top();
        pq.pop();
        
        Node *root = new Node(first -> freq , '$');
        root->left = first;
        root->right = second;
        pq.push(root);
    }
    
    Node* root = pq.top(); // saving the root node (top) of tree
    pq.pop();
    
    // preorder Find karna 
    vector<string>ans;
    string temp;
    preorder(root, temp , ans);
    
    return ans;
    }
}