// TC = O(N) | SC = O(N)
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Box
{
public:
  bool BST;
  int size;
  int min;
  int max;

  // structure of a single node
  Box(int data)
  {
    BST = 1; // a single node is a BST
    size = 1;
    min = data;
    max = data;
  }
};

Box *find(TreeNode *root, int &Totalsize)
{

  // node is leaf node
  if (!root->left && !root->right)
  {                                // just pass its info(box) above
    Totalsize = max(Totalsize, 1); // size of single node is 1
    return new Box(root->val);
  }
  // node ka only right side exist
  else if (!root->left && root->right)
  {
    // uske liye call lagao and store its info in head
    Box *head = find(root->right, Totalsize);

    // if BST hay
    if (head->BST && head->min > root->val)
    {
      head->size++;
      head->min = root->val;
      Totalsize = max(Totalsize, head->size);
      return head; // upar info return kardo
    }
    // BST nai hay
    else
    {
      head->BST = 0; // just update BST information no need to update all
      return head;
    }
  }

  // node ka only left side exist

  else if (!root->right && root->left)
  {
    // uske liye call lagao and store its info in head
    Box *head = find(root->left, Totalsize);

    // if BST hay
    if (head->BST && head->max < root->val)
    {
      head->size++;
      head->max = root->val;
      Totalsize = max(Totalsize, head->size);
      return head;
    }

    // BST nai hay
    else
    {
      head->BST = 0; // just update its not head and pass above
      return head;
    }
  }
  // node ke both sides exist
  else
  {
    // call for left and right
    Box *lefthead = find(root->left, Totalsize);
    Box *righthead = find(root->right, Totalsize);

    // check if its BST
    if (lefthead->BST && righthead->BST && lefthead->max < root->val && righthead->min > root->val)
    {
      // create a new box update info and pass info above
      Box *head = new Box(root->val);
      head->size = lefthead->size + righthead->size + 1; // + apni size
      head->min = lefthead->min;                         // cause left side has min
      head->max = righthead->max;                        // and right side have max
      Totalsize = max(Totalsize, head->size);
      return head; // ye info upar pass kardo
    }
    else
    {
      // not a BST - return the subtree with the maximum BST size
      lefthead->BST = 0; // or righthead->BST = 0;
      return lefthead;
    }
  }
}

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  /*You are required to complete this method */
  // Re+turn the size of the largest sub-tree which is also a BST
  int largestBst(TreeNode *root)
  {
    // Your code here
    int Totalsize = 0;
    find(root, Totalsize);
    return Totalsize; // size of the largest sub-tree which is also a BST
  }
};

//! we will solve this in less steps
class Box
{
public:
  bool BST;
  int size;
  int min;
  int max;

  Box()
  { // structure of null node
    BST = 1;
    size = 0;
    min = INT_MAX;
    max = INT_MIN;
  }
};
// method 2
Box *find(TreeNode *root, int &Totalsize)
{

  // root doesn't exists
  if (!root)
  {
    return new Box();
  }
  // root exist
  else
  {
    Box *lefthead = find(root->left, Totalsize);
    Box *righthead = find(root->right, Totalsize);

    // if BST hay
    if (lefthead->BST && righthead->BST && lefthead->max < root->val && righthead->min > root->val)
    {

      Box *head = new Box();
      head->size = 1 + lefthead->size + righthead->size;
      // we are handling the case where either root doesnt exist
      head->min = min(root->val, lefthead->min);
      head->max = max(root->val, righthead->max);
      Totalsize = max(Totalsize, head->size);
      return head;
    }
    else
    { // Not A BST
      lefthead->BST = 0;
      return lefthead;
    }
  }
}

class Solution
{
public:
  /*You are required to complete this method */
  // Return the size of the largest sub-tree which is also a BST
  int largestBst(TreeNode *root)
  {
    // Your code here
    int Totalsize = 0;
    find(root, Totalsize);
    return Totalsize; // size of the largest sub-tree which is also a BST
  }
};