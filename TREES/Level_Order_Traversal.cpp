#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> ans;

  if(!root) 
    return ans;

  queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()){
    int sz = q.size();
    vector<int> temp;

    while(sz--){
      TreeNode* node = q.front();
      q.pop();

      temp.push_back(node->val);

      if(node->left)
        q.push(node->left);

      if(node->right)
        q.push(node->right);
    }

    ans.push_back(temp);
  }

  return ans;
  }
};