// TC = O(N) // SC = O(N)
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

class Solution
{
public:
  void inorder(TreeNode *root, vector<int> &ans)
  {
    if (!root)
    {
      return;
    }

    /// L N R
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
  }
  // Function to return a list of integers denoting the node
  // values of both the BST in a sorted order.
  vector<int> merge(TreeNode *root1, TreeNode *root2)
  {

    vector<int> ans1;
    vector<int> ans2;
    // traverse using inorder in both BST and store in ans 1 and 2
    inorder(root1, ans1);
    inorder(root2, ans2);

    // we will merge both of these arrays in sorted order using 2 pointers
    vector<int> ans;

    int i = 0;
    int j = 0;

    while (i < ans1.size() && j < ans2.size())
    {
      if (ans1[i] < ans2[j])
      {
        ans.push_back(ans1[i++]);
      }

      else
      {
        ans.push_back(ans2[j++]);
      }
    }

    // now abhi ek array pehle complete hogaya dusra bachgaya

    while (i < ans1.size())
    {
      ans.push_back(ans1[i]);
      i++;
    }

    while (j < ans2.size())
    {
      ans.push_back(ans2[j]);
      j++;
    }
    return ans;
  }
};
//! approach 2

class Solution
{
public:
  // Function to return a list of integers denoting the node
  // values of both the BST in a sorted order.
  vector<int> merge(TreeNode *root1, TreeNode *root2)
  {
    // Your code here
    //! Iterative approach
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