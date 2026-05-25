#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxFreq = 0;
  unordered_map<int, int> freq;

  int dfs(TreeNode* root){
    if(!root) return NULL;

    int left = dfs(root->left);
    int right = dfs(root->right);

    int sum = root->val + left + right;
  
    freq[sum]++;
    maxFreq = max(maxFreq, freq[sum]);

    return sum;
  }

  vector<int> findFrequentTreeSum(TreeNode* root) {
    dfs(root);

    vector<int> ans;

    for(auto &it : freq){
      if(it.second == maxFreq){
        ans.push_back(it.first);
      }
    }

    return ans;
  }
};