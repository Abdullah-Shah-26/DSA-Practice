class Solution {
    public:
        vector<int> inOrder(Node* root)
        {   if (!root) return {}; // Handle edge case
    
            
            /// we will use 2 stacks 
            // s1 - to put RNL so that we get LNR when it comes out
            // s2(visited) - to print the node only when its being visited 2nd time(yaani dusri baar stack se nikalne jaarre)
            stack<Node*> s;
            stack<bool> visited;
            s.push(root); // push root in s initially
            visited.push(0); // abhi tak root ko 0 baar visit kiya
            vector<int>ans;
            while(!s.empty())
            {
                Node* temp = s.top();
                s.pop();
                bool flag = visited.top();
                visited.pop();
                
                // first time visiting the node (nikalne jaare they)
                if(flag == 0)
                {
                  // if node ka left right exist put in stack in R N L order since stack is lIFO it will get out as L N R ( inorder )  
                  
                    //Right
                    if(temp->right)
                    {
                        s.push(temp->right);
                        visited.push(0); // node ke right ko 0 times abhi tak visit kiya hai
                    }
                    // Node
                    s.push(temp);
                    visited.push(1); //yaani node ko ab tak ek baar stack se bahaar nikala 
                    
                    // left
                    if(temp->left)
                    {
                        s.push(temp->left);
                        visited.push(0); // Node ke right ko 0 times abhi tak visit kiya (yaani nikala)
                    }
                    
                   
                }
                
                else{ // visiting node second time (dusri baar nikalre stack se ) flag == 1
                        ans.push_back(temp->data); // print it by storing in ans
                    }
            }
             return ans;
        }
    };
       