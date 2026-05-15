#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
  public:
    struct Frame{
      TreeNode* node;
      int state;
    };

    int dfsIt(TreeNode* root, int &ans){
      if(!root) return 0;
      unordered_map<TreeNode*, int> dp;

      stack<Frame> st;
      st.push({root, 0});

      while(!st.empty()){
        auto f = st.top();
        st.pop();

        if(f.state == 0){
          st.push({f.node, 1});

          if(f.node->left)
            st.push({f.node->left, 0});
            
          if(f.node->right)
            st.push({f.node->right, 0}); 
        }
        else{
          // Post Order Processing
          int left = 0;
          int right = 0;

          if(f.node->left) left = dp[f.node->left];
          if(f.node->right) right = dp[f.node->right]; 

          int leftChain = 0;
          int rightChain = 0;

          if(f.node->left && f.node->left->val == f.node->val){
            leftChain = left + 1;
          }

          if(f.node->right && f.node->right->val == f.node->val){
            rightChain = right + 1;
          }

          ans = max(ans, leftChain + rightChain);

          dp[f.node] = max(leftChain, rightChain);
        }
      }
      return ans;
    }

    int dfs(TreeNode* root, int &ans){
      if(!root) return 0;
      
      int left = dfs(root->left, ans);
      int right = dfs(root->right, ans);

      int leftChain = 0;
      int rightChain = 0;

      if(root->left && root->left->val == root->val){
        leftChain = left + 1;
      }

      if(root->right && root->right->val == root->val){
        rightChain = right + 1;
      }

      ans = max(ans, leftChain + rightChain);
      
      return max(leftChain, rightChain);
    }

    int longestUnivaluePath(TreeNode* root) {
      int ans = 0;
      dfsIt(root, ans);
      return ans;
    }
};