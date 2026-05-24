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

class Solution
{
public:
  void correctBST(TreeNode *root)
  {
    // we we'll use morris traversal - inorder TC = O(N)  SC = O(1)

    TreeNode *curr = NULL;
    TreeNode *first = NULL, *second = NULL;
    TreeNode *last = NULL, *present = NULL;

    while (root)
    {
      // left doesn't exist
      if (!root->left)
      { // right jane se pehle check koi gadbad to nai hay
        last = present;
        present = root;
        // check for gadbad  - initially last is null  we cant compare null and element
        // so ensure last exist
        if (last && last->val > present->val)
        {
          if (!first) // first NULL hay yani 1st gadbad update both
          {
            first = last;
          }

          second = present; // second gadbad hay update only second
        }

        root = root->right;
      }
      // left exist
      else
      {
        curr = root->left;
        while (curr->right && curr->right != root)
        {
          curr = curr->right;
        }

        // Left subtree not Traversed
        if (!curr->right)
        {
          curr->right = root;
          root = root->left;
        }
        else
        { // Left subtree already traversed

          curr->right = NULL;
          last = present;
          present = root;
          // check for gadbad  - initially last is null  we cant compare null and element
          // so ensure last exist
          if (last && last->val > present->val)
          {
            if (!first) // first NULL hay yani 1st gadbad update both
            {
              first = last;
            }

            second = present; // second gadbad hay update only second
          }

          root = root->right;
        }
      }
    }
    // swap first and second
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
  }
};