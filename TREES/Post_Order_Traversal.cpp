#include <bits/stdc++.h>
using namespace std;

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