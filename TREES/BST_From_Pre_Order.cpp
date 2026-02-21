#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);


class Node
{

public:
  int data;
  Node *left;
  Node *right;

  Node() : data(0), left(nullptr), right(nullptr) {}
  Node(int x) : data(x), left(nullptr), right(nullptr) {}
  Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}

};

class Solution
{
public:
  Node *build(int &i, int arr[], int upperBound, int n)
  {
    if (i == n || arr[i] > upperBound)
      return NULL;
    Node *root = new Node();
    root->data = arr[i++];
    root->left = build(i, arr, root->data, n);
    root->right = build(i, arr, upperBound, n);
    return root;
  }

  Node *Bst(int pre[], int size)
  {
    int i = 0;
    return build(i, pre, INT_MAX, size);
  }
};
