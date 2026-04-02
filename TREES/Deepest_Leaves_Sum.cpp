#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS Level Order - Overwrite Sum
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
    int deepestLeavesSum(TreeNode* root) {
    if(!root) return 0;    
   
    queue<TreeNode*> q;
    q.push(root);
    int ans = 0;

    while(!q.empty()){
      int sz = q.size();
      int levelSum = 0;

      while(sz--){
        TreeNode* node = q.front();
        q.pop();

        levelSum += node->val;

        if(node->left){
          q.push(node->left);
        }
        if(node->right){
          q.push(node->right);
        }
      }

      ans = levelSum;
    }

    return ans;
    }
};