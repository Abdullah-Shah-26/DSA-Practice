//! BINARY TREE - method 2 
#include<iostream>
#include<queue>
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
//! N L R - printing order
void PreOrder(Node* root)
{
    // base case
    if(root == NULL)
    return;

    //node 
    cout<<root->data<<" ";
    //left
    PreOrder(root->left);
    //right
    PreOrder(root->right);

}
//! L R N - printing order
void PostOrder(Node* root)
{

    //base case
    if(root == NULL)
    return; 

    // left 
    PostOrder(root->left);
    // right
    PostOrder(root->right);
    // Node
    cout<<root->data<<" ";
    
}
//!  L N R - printing order 
void InOrder(Node* root)
{
    //base case
    if(root == NULL)
    return;
    
    //left
    InOrder(root->left);
    //Node
    cout<<root->data<<" ";
    //right
    InOrder(root->right);

}

// recursive function to create binary tree 
Node* BinaryTree(){

    int x;
    cin >>x;

    if(x == -1)
    return NULL;

    Node* temp = new Node(x);

    //! first recursively call fun to create left side  
    cout<< "Enter the left child of "<<x<<" : ";
    temp ->left = BinaryTree();   // returns address to prev calls 
   

    //! then call for right side
    cout<< "Enter the right child of "<<x<<" : ";
    temp->right = BinaryTree();   // returns address to prev calls 

    return temp;

}
int main()
{
    cout<<"Enter the root Node : ";
    Node* root;
    root = BinaryTree(); // at last fun will return address of root node 


    // PreOrder print

    cout<<"Pre Order : ";
    PreOrder(root);

    // InOrder Print

    cout<<"\nIn order : ";
    InOrder(root);

    // PostOrder Print
    cout<<"\nPostorder : ";
    PostOrder(root);
}