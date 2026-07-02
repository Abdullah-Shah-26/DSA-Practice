#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

struct Node {
  int sum;
  Node *left, *right;

  Node(int val = 0) {
    sum = val;
    left = right = NULL;
  }
};

Node *build(int l, int r, vi &arr) {

  // Leaf
  if (l == r)
    return new Node(arr[l]);

  int mid = (l + r) >> 1;

  Node *leftChild = build(l, mid, arr);
  Node *rightChild = build(mid + 1, r, arr);

  Node *root = new Node();

  root->left = leftChild;
  root->right = rightChild;

  root->sum = leftChild->sum + rightChild->sum;

  return root;
}

int query(Node *root, int l, int r, int ql, int qr) {
  if (l > qr || r < ql)
    return 0;

  if (l >= ql && r <= qr)
    return root->sum;

  int mid = (l + r) >> 1;

  return query(root->left, l, mid, ql, qr) +
         query(root->right, mid + 1, r, ql, qr);
}

Node *update(Node *root, int l, int r, int idx, int val) {

  // Create copy of current node
  Node *newRoot = new Node();
  *newRoot = *root; // shallow copy

  if (l == r) {
    newRoot->sum = val;
    return newRoot;
  }

  int mid = (l + r) >> 1;

  if (idx <= mid)
    newRoot->left = update(root->left, l, mid, idx, val);
  else
    newRoot->right = update(root->right, mid + 1, r, idx, val);

  newRoot->sum = newRoot->left->sum + newRoot->right->sum;

  return newRoot;
}

int main(){
  vi arr = {1, 2, 3, 4};

  int n = arr.size();

  vector<Node*> roots;

  // Version 0
  roots.push_back(build(0, n-1, arr));

  // Version 1 : arr[2] = 10;
  roots.push_back(update(roots[0], 0, n-1, 2, 10));

  // Version 2 : based on version 1, arr[0] = 100;
  roots.push_back(update(roots[1], 0, n-1, 0, 100));

  // 1,2,3,4 = 10
  cout << query(roots[0], 0, n-1, 0, n-1) << endl;
  
  // 1,2,10,4 = 17
  cout << query(roots[1], 0, n-1, 0, n-1) << endl;
  
  // 100,2,10,4 = 116
  cout << query(roots[2], 0, n-1, 0, n-1) << endl;
}