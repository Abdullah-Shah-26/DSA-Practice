#include <bits/stdc++.h>
using namespace std;

// defining a node
class Node
{
public:
    int data;
    int height;
    Node *left;
    Node *right;

    // structure of a single node
    Node(int value)
    {
        data = value;
        height = 1;
        left = right = NULL;
    }
};

// function to get height 
int getheight(Node* root)
{
    if(!root) // root doest exist ht = 0
    return 0;
    
    return root->height;
}
// right rotation - LL
Node* rightrotation(Node* root){
    Node* child = root->left;
    Node* childRight = child->right;
    
    child->right = root;
    root->left = childRight;
    
    // update ht of root and child
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    
    // return address above 
    return child;
}
// left rotation - RR
Node* leftrotation(Node* root){
    Node* child = root->right;
    Node* childLeft = child->left;
    
    child->left = root;
    root->right = childLeft;
    
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    child->height = 1 + max(getheight(child->left), getheight(child->right));
    
    return child;
}


// function to get balance 
int getbalance(Node* root)
{
    return getheight(root->left) - getheight(root->right);
}

Node* deleteNode(Node* root, int key)
{
    // root doen't exist
    if(!root)
    return NULL;
    
    // root exist
    
    if(key < root->data) // left jao
    root->left = deleteNode(root->left , key);
    
    else if(key > root->data) // right side jao 
    root->right = deleteNode(root->right, key);

    else // key == root->data - delete node
    {
        // 3 cases 
        
        // key is leef Node
        if(!root->left && !root->right)
        {
            delete root; 
            return NULL;
        }
        // key has only one child
        // store childs address 
        // delete root (key)
        // return child's address
        
        // only left child exists
        else if(root->left && !root->right){
            Node* temp = root->left;
            delete root;
            return temp; 
            
        }
        // only right child exists
        else if(root->right && !root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        // Both child exists - 
        
        else {
            // find right side se smallest elemnet  
            Node* curr = root->right;
            while(curr->left)
            {
                curr = curr->left;
            }
            root->data = curr->data;// and replace it with node u are deleting
            root->right = deleteNode(root->right, curr->data); // delete the smallest elemnt from right
        }
    }
    // update height
    root->height = 1 + max(getheight(root->left), getheight(root->right));
    
    // check balance
    int balance = getbalance(root);
    
    // if balance > 1 left side imbalanced hua
    if(balance > 1){
        // LL 
        if(getbalance(root->left) >= 0)
        return rightrotation(root);
    
        // LR
        else{
            root->left = leftrotation(root->left);
            return rightrotation(root);
        }
        
    }
    else if(balance < -1) // right side imbalance hua
    {
        // RR
        if(getbalance(root->right) <= 0)
        return leftrotation(root);
        
        // RL
        else
        {
            root->right = rightrotation(root->right);
            return leftrotation(root);
        }
    }
    else // balanced hay 
    return root;
}