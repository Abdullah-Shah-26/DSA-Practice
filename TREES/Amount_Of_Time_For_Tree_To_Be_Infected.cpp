#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS - Level Wise
//* TC = O(N) | SC = O(N)

class Solution {
public:
  unordered_map<TreeNode*, TreeNode*> parent;
  TreeNode* stNode = NULL;

  void build(TreeNode* node, TreeNode* p, int start){
    if(!node) return;

    parent[node] = p;

    if(node->val == start){
      stNode = node;
    }

    build(node->left, node, start);
    build(node->right, node, start);
  }

  int amountOfTime(TreeNode* root, int start) {
    build(root, NULL, start);

    unordered_set<TreeNode*> vis;
    queue<TreeNode*> q;
    
    q.push(stNode);
    vis.insert(stNode);

    int time = -1;

    while(!q.empty()){
      int size = q.size();

      while(size--){
        TreeNode* cur = q.front();
        q.pop();

        if(cur->left && !vis.count(cur->left)){
          vis.insert(cur->left);
          q.push(cur->left);
        }

        if(cur->right && !vis.count(cur->right)){
          vis.insert(cur->right);
          q.push(cur->right);
        }

        // if(parent[cur] && !vis.count(parent[cur])){
        //   vis.insert(parent[cur]);
        //   q.push(parent[cur]);
        // }

        // 1 Hash LookUp
        TreeNode* p = parent[cur];
        if(p && !vis.count(p)){
          vis.insert(p);
          q.push(p);
        }
      }
     time++;
    }

  return time;
  }
};