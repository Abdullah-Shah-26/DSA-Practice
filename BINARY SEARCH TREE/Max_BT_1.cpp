#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    TreeNode* build(vector<int> &arr, int l,int r){
      if(l > r) return NULL;

      // Need maxElem's Idx in this range [l..r]
      int idx = l;
      for(int i = l; i <= r; i++){
        if(arr[i] > arr[idx]){
          idx = i;
        }
      }

      TreeNode* root = new TreeNode(arr[idx]);

      root->left = build(arr, l, idx-1);
      root->right = build(arr, idx+1, r);

      return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& arr) {
    int n = arr.size();

    return build(arr, 0, n-1);
    }
};