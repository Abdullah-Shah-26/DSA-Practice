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

//! - segmentation fault aara
vector<int> ans;
// inorder using stack
stack<TreeNode *> s1; // 2 stacks for 2 BST
stack<TreeNode *> s2;

// L  N  R - pehle stack mein saare left daalo
while (root1)
{
  s1.push(root1);
  root1 = root1->left;
}
while (root2)
{
  s2.push(root2);
  root2 = root2->left;
}
// jab tak ek stack khali na ho jaye
while (!s1.empty() && !s2.empty())
{
  // top element of both stack are equal
  if (s1.top()->val == s2.top()->val)
  {
    // pehle ans mein dalo
    ans.push_back(s1.top()->val);
    // right par jao and uske saare left nodes ko s1  mein dalo
    root1 = s1.top()->right;
    s1.pop();
    // same for s2
    root2 = s2.top()->right;
    s2.pop();

  } // jo chota hay wo stack se pop

  // s1 ka top element > s2 ka top
  else if (s1.top()->val > s2.top()->val)
  { // right mein jao ,  s2 mein se pop karo and  and uske (right ke) saare left s2 mein dalo
    root2 = root2->right;
    s2.pop();
  }

  // s2 ka top element > s1 ka top
  else
  { // right mein jao ,  s1 mein se pop karo and  and uske (right ke) saare left s2 mein dalo
    root1 = root1->right;
    s1.pop();
  }
  while (root1)
  {

    s1.push(root1);
    root1 = root1->left;
  }
  while (root2)
  {
    s2.push(root2);
    root2 = root2->left;
  }
}
return ans;
}
//!_______________________________________________________________
//? BETTER APPROACH

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
  // Function to find the nodes that are common in both BST.
  vector<int> findCommon(TreeNode *root1, TreeNode *root2)
  {

    vector<int> ans;
    stack<TreeNode *> s1, s2;

    // helper func to push all left nodes of subtree in stack
    auto pushleft = [](TreeNode *root, stack<TreeNode *> &s)
    {
      while (root)
      {
        s.push(root);
        root = root->left;
      }
    };

    // first push all left nodes in stack
    pushleft(root1, s1);
    pushleft(root2, s2);

    while (!s1.empty() && !s2.empty())
    {
      TreeNode *node1 = s1.top();
      TreeNode *node2 = s2.top();

      if (node1->val == node2->val)
      {
        // dono stacks ke top elements equal hay
        // push s1.top in ans
        // and pop and
        // root ke right jao and uske saare left s1 mein dalo
        // repeat same for s2
        ans.push_back(node1->val);
        s1.pop();
        s2.pop();
        pushleft(node1->right, s1);
        pushleft(node2->right, s2);
      }
      else if (node1->val < node2->val)
      { // jo chota hay wo pop karo and repeat the above steps
        s1.pop();
        pushleft(node1->right, s1);
      }
      else
      { // s1.top > s2.top
        s2.pop();
        pushleft(node2->right, s2);
      }
    }
    return ans;
  }
};

//!@ approach 2
class Solution
{
public:
  // Function to return a list of integers denoting the node
  // values of both the BST in a sorted order.
  vector<int> merge(TreeNode *root1, TreeNode *root2)
  {
    // Your code here
    // Iterative approach
    // Using 2 stacks - inorder traversal
    vector<int> ans;

    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

    // helper func to push all left nodes of subtree in stack
    auto pushleft = [](TreeNode *root, stack<TreeNode *> &s)
    {
      while (root)
      {
        s.push(root);
        root = root->left;
      }
    };

    // first push all left nodes in stack from root
    pushleft(root1, s1);
    pushleft(root2, s2);

    while (!s1.empty() || !s2.empty())
    {

      // handling edge case where one BST gets exhausted before another
      if (s1.empty())
      {
        ans.push_back(s2.top()->val);
        TreeNode *temp = s2.top();
        s2.pop();
        pushleft(temp->right, s2);
        continue; // avoids unnecessary checks
      }
      else if (s2.empty())
      {
        ans.push_back(s1.top()->val);
        TreeNode *temp = s1.top();
        s1.pop();
        pushleft(temp->right, s1);
        continue;
      }

      TreeNode *node1 = s1.top();
      TreeNode *node2 = s2.top();

      if (node1->val < node2->val)
      {

        // push smaller in ans
        // and pop from s1 and
        // right jao root ke and uske saare left s1 mein dalo

        ans.push_back(node1->val);
        s1.pop();
        pushleft(node1->right, s1);
      }
      else if (node1->val == node2->val)
      { // dono stacks ke top elements equal hay
        ans.push_back(node1->val);
        ans.push_back(node2->val);
        s1.pop();
        s2.pop();
        pushleft(node1->right, s1);
        pushleft(node2->right, s2);
      }
      else
      {
        // s1.top>s2.top
        ans.push_back(node2->val);
        s2.pop();
        pushleft(node2->right, s2);
      }
    }

    return ans;
  }
};