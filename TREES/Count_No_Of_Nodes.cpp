#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findLeftHt(Node* root)
    {
        int ht = 0;
        while(root)
        {
            ht++;
            root = root->left;
        }
        
        return ht;
    }
    int findRightHt(Node* root)
    {
        int  ht  = 0;
        while(root)
        {
            ht++;
            root = root->right;
        }
        return ht;
    }
    
    int countNodes(Node* root) {
    if(!root) return 0;
    
    int lh = findLeftHt(root);
    int rh = findRightHt(root);
    
    if(lh == rh)
    return (1 << lh) -1;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
    }
};