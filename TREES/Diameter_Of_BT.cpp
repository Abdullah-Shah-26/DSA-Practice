#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

  
// TC = O(N)
// SC = O(N)

class Solution{
public:
  int height(TreeNode *root, int &maxi)
  {
    if (!root)
      return 0;
    int lh = height(root->left, maxi);
    int rh = height(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
  }

  int diameterOfBinaryTree(TreeNode *root)
  {
    int diameter = 0;
    height(root, diameter);
    return diameter;
  }
};

// Iterative Post Order DFS

struct Frame{
  TreeNode* node;
  int state; 
  int L, R; // leftHt, rightHt
};

class Solution {
public:
  int diameterOfBinaryTree(TreeNode* root) {
  if(!root) return 0;

  int res = INT_MIN;

  // 3 States
  // 0 = push its left
  // 1 = push its right
  // 2 = process curr node

  stack<Frame> st;
  st.push({root, 0, 0, 0});

  while(!st.empty()){
    auto &cur = st.top();

    if(cur.state == 0){
      cur.state = 1;

      if(cur.node->left)
        st.push({cur.node->left, 0, 0, 0});
    }

    else if(cur.state == 1){
      cur.state = 2;

      if(cur.node->right)
        st.push({cur.node->right, 0, 0, 0});
    }

    else{
      int L = cur.L;
      int R = cur.R;

      res = max(res, L + R);
      int h = 1 + max(L, R);

      st.pop();

      if(!st.empty()){
        Frame &parent = st.top();

        if(parent.state == 1)
          parent.L = h;
        if(parent.state == 2)
          parent.R = h;
      }
    }
  }

  return res;    
  }
};