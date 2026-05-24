class Solution {
    public:
    //since ht and burn both are int we will denote burn as -ve nos 
    // burn function - will either return ht or kitne sec mein burn hoga 
    int Burn(Node *root, int &timer, int target)
    {
        // node doesnt exist
        if(!root)
        return 0;
        
        // node exist
        // if its a target node
        if(root ->data == target)
        return -1;
        
        // if its a normal node 
        // then we ask 2 questions
        // 1 agar aapki side se fire aa raha hai to muje batado ki muje kitne sec mein jala doge 
        // 2 else muje ht  batado uss side ki
        
        int left = Burn(root->left , timer, target);
        int right = Burn(root->right, timer , target);
        
        // burn ek hi side se return ho sakta hai beause tree doesnt have loops
        
        // agar left se burn aaya - right will be ht
        if(left < 0)
        {
            timer = max(timer,abs(left) + right);
            return left-1; // since we are taking burn as -ve so we will add -ve 
            // it will add 1 sec and return to prev calls
        }
        
        // if burn right se aaya & left se ht aayi - add 1 sec and return burn to prev call
        if(right < 0)
        {
            timer = max(timer,left + abs(right));
            return right-1;
        }
        // dono side se ht aayi
       return 1 + max(left , right);  // return ht
       
    }
    // func to find burn - target node
    void find(Node* root, int target, Node* &BurnNode)
  {
      if(!root)
      return;
      // burn node found 
      if(root -> data == target)
      {
          BurnNode = root;
          return;
      }
      // else search in left & right part
      find(root->left , target , BurnNode);
      find(root->right, target , BurnNode);
  }  
      // find height of bottom tree
      int Height(Node* root){
          
          if(!root)
          return 0;
          // ht = apni node ki ht + max of left se jo ht aayi and right se jo ht aayi
          return 1 + max(Height(root->left), Height(root->right));
      }
    
      
      int minTime(Node* root, int target) {
          
    
  };      int timer = 0;
          // calculates the time for burning rest of tree except nodes which are below target - bottom part
          Burn(root,timer,target);
  
          // need to find target node's position to calculate ht of bottom part
          Node* BurnNode = NULL;
          find(root, target, BurnNode); // func to find burn node - target
          
          int high = Height(BurnNode) - 1; // kyu ki agar 6 hay to vo 9 10 ko 2sec mein burn karega
          
          return max(timer, high); // max of jpure tree ko burn karne mein laga or ht of bottom part
          // will be our final time 
          
      }