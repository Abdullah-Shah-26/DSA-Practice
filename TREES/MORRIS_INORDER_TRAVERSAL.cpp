#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Node
{
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
    vector<int> Inorder(Node* root) 
    // left 
    // Node
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
            // left part exist
            else{
                Node* curr = root->left;

                while(curr->right && curr->right != root)
                curr = curr->right;

                // link doesnt exist - means left part isnt traversed 
                // - create it and move to left 
                if(curr->right == NULL)
                {
                    curr->right = root;
                    root = root->left;
                }
                else{ // link exist - left part already traversed 
                    // link hatado 
                    curr->right = NULL;
                    // value lelo 
                    ans.push_back(root->data);
                    // right chalo
                    root = root->right;

                }
            }
        }
        return ans;
    }
};


