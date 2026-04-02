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

//* TC = O(N)
//* SC = O(N)

class Solution {
public:
    vector<int> arr;

    void inorder(TreeNode* root){
      if(!root) return;

      inorder(root->left);
      arr.push_back(root->val);
      inorder(root->right);
    }

    TreeNode* build(int l, int r){

      if(l > r) return NULL;

      int mid = (l + r) >> 1;

      TreeNode* root = new TreeNode(arr[mid]);

      root->left = build(l, mid-1);
      root->right = build(mid+1, r);

      return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
      inorder(root);
      return build(0,arr.size()-1);     
    }
};