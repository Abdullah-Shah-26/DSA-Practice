#include <bits/stdc++.h>
using namespace std;

class CountIntervals {
public:
  
  struct Node{
  int cnt = 0; // stores how many points are covered in range
  Node* left = NULL;
  Node* right = NULL;
  };

  Node* root = new Node();

  void update(Node* node, int l, int r, int ql, int qr){
    
    // Whole segment already covered - stop recursion
    if(node->cnt == (r - l + 1)){
      return;
    }

    if(r < ql || l > qr){
      return;
    }

    if(l >= ql && r <= qr){
      node->cnt = r - l + 1;
      return;
    }

    int mid = (l + r) >> 1;

    if(!node->left)
      node->left = new Node();

    if(!node->right)
      node->right = new Node();

    update(node->left, l, mid, ql, qr);
    update(node->right, mid + 1, r, ql, qr);

    node->cnt = node->left->cnt + node->right->cnt; 
  }

  CountIntervals() {

  }
  
  void add(int left, int right) {
    update(root, 1, 1e9, left, right); 
  }
  
  int count() {
    return root->cnt; 
  }
};