#include<bits/stdc++.h>
#include<vector>
using namespace std;
x // logic - 
/*
        1
    2       3
4

if we have already traversed left subtree that means we have already  included 1 in ans - so dont push ans if left is alraeady traversed

else if we didnt traverse left subtree that means we are visiting 1 first time
so include in ans 
--- since in pre order its NODE _ LEFT _ RIGHT




*/

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){

        left = right = NULL;
        data = val;
    }
};
class Solution{
public:
    vector<int> Preorder(Node* root) 
    // Node
    // Left
    // Right 
    {
        vector<int> ans;

        while(root)
        {
            // left part doesnt exist
            if(!root->left)
            { // ans mein daldo and right chalo
                ans.push_back(root->data);
                root = root->right;

            }
            // left part exists
            else{
                Node* curr = root->left;

                while(curr->right && curr->right != root)
                curr = curr->right;

                // link doesnt exist - means left part isnt traversed 
                //  data store karlo - Node ka 
                //  create Link and move to left 
                if(curr->right == NULL)
                {       // value lelo 
                    ans.push_back(root->data);
                    curr->right = root;
                    root = root->left;
                }
                else{ // link exist - left part already traversed 
                    // link hatado 
                    curr->right = NULL;
                    // right chalo
                    root = root->right;

                }
            }
        }
        return ans;
    }
};