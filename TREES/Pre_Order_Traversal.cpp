#include <bits/stdc++.h>
using namespace std;

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

