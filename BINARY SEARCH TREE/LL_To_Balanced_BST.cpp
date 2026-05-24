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
  // func to create Balanced BSt from vector - jo mid hay vo node banega
  TreeNode *BuildBST(vector<int> &Tree, int start, int end)
  {

    if (start > end)
    {
      return NULL; // no need to create node there
    }

    // acc to question mid is calculated it prefers 2nd value
    int mid = start + (end - start + 1) / 2; // its written this way to avoid int overflow
    TNode *root = new TNode(Tree[mid]);

    root->left = BuildBST(Tree, start, mid - 1);
    root->right = BuildBST(Tree, mid + 1, end);

    return root;
  }

  TNode *sortedListToBST(LNode *head)
  {
    //  first convert LL _ vector
    vector<int> Tree;

    while (head)
    {
      Tree.push_back(head->val);
      head = head->next;
    }
    return BuildBST(Tree, 0, Tree.size() - 1);
  }
};