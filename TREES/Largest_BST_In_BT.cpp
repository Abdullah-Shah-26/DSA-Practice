#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);


class NodeValue{
    public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
  public:
  
    NodeValue LBST(Node* root){
        if(!root)
        return NodeValue(1e9, -1e9, 0);
        
        auto left = LBST(root->left);
        auto right = LBST(root->right);
        
        if(left.maxNode < root->data && root->data < right.minNode)
        {
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), 1 + left.maxSize + right.maxSize);
        }
        return NodeValue(-1e9, 1e9, max(left.maxSize, right.maxSize));
    }
  
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
    return LBST(root).maxSize;      
    }
};

