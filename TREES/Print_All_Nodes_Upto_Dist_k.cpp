#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void markParent(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parentTrack,TreeNode* target) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (node->left) {
        parentTrack[node->left] = node;
        q.push(node->left);
      }
      if (node->right) {
        parentTrack[node->right] = node;
        q.push(node->right);
      }
    }
  }
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parentTrack;
    unordered_map<TreeNode*, bool> vis;
    markParent(root, parentTrack, target);
    queue<TreeNode*> q;
    q.push(target);
    vis[target] = 1;
    int dist = 0;
    while (!q.empty()) {
      int size = q.size();
      if (dist++ == k)
        break;
      for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();

        if (node->left && !vis[node->left]) {
          q.push(node->left);
          vis[node->left] = 1;
        }
        if (node->right && !vis[node->right]) {
          q.push(node->right);
          vis[node->right] = 1;
        }
        if (parentTrack.count(node) && !vis[parentTrack[node]]) {
          q.push(parentTrack[node]);
          vis[parentTrack[node]] = 1;
        }
      }
    }
    vector<int> res;
    while (!q.empty()) {
      res.push_back(q.front()->val);
      q.pop();
    }
    return res;
  }
};
