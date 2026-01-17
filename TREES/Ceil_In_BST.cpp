

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

class Solution
{
public:
  int findCeil(Node *root, int key)
  {
    int ceil = -1;
    while (root)
    {
      if (root->data == key)
      {
        ceil = root->data;
        return ceil;
      }
      if (key > root->data)
      {
        root = root->right;
      }
      else
      {
        ceil = root->data;
        root = root->left;
      }
    }
    return ceil;
  }
};