#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

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

//! Recursion
class Solution {
public:
    int dfs(TreeNode* root, int mask){
      if(!root){
        return 0;
      }

      mask ^= (1 << (root->val - 1)); // converting to 0-based

      if(!root->left && !root->right){
        // If palindrome - Odd Cnt <= 1
        // Checks if atmost 1 bit is set or not
        return ((mask & (mask - 1))) == 0;  
      }

      return dfs(root->left, mask) + dfs(root->right, mask);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
      return dfs(root,0);
    }
};

//! Iterative
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
    if(!root){
      return 0;
    }        
    stack<pair<TreeNode*, int>>st;
    st.push({root, 0});

    int ans = 0;

    while(!st.empty()){
      auto it = st.top();
      st.pop();
      TreeNode* node = it.first;
      int mask = it.second;

      mask ^= (1 << (node->val - 1));

      if(!node->left && !node->right){
        if((mask & (mask - 1)) == 0)
          ans++;
      }
      else {
        if(node->left){
          st.push({node->left, mask});
        }
        if(node->right){
          st.push({node->right, mask});
        }
      }
    }

    return ans;
    }
};