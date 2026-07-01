#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
    if(root == NULL)
    {
      return;
    }
    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;    
    }
}; 

// Iterative : 

class Solution {
public:
  void flatten(TreeNode* root) {
    if(!root) return;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()){
      TreeNode* cur = st.top();
      st.pop();

      if(cur->right)
        st.push(cur->right);

      if(cur->left)
        st.push(cur->left);

      if(!st.empty())
        cur->right = st.top();

      cur->left = NULL;
    }
  }
};