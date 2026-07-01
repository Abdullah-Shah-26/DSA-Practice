#include <bits/stdc++.h>
using namespace std;

//! BINARY TREE - method 2  --  PURA LEFT THEN RIGHT
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
}
/*? 
        1 
      2        7   
    3       6       8
  4       5        9     10




*/