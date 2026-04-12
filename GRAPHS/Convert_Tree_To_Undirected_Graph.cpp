#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

struct TreeNode{
  int data;
  TreeNode* left, *right;

  TreeNode(int value){
    data = value;
    left = NULL;
    right = NULL;
  }
};

unordered_map<TreeNode* , vector<TreeNode*>> adj;

void build(TreeNode* node, TreeNode* parent){
  if(!node) return;

  if(parent){
    adj[node].push_back(parent);
    adj[parent].push_back(node);
  }

  if(node->left){
    adj[node].push_back(node->left);
    adj[node->left].push_back(node);
    build(node->left, node);
  }

  if(node->right){
    adj[node].push_back(node->right);
    adj[node->right].push_back(node);
    build(node->right, node);
  }
}

//* Or just store parent info & Find stNode for bfs
unordered_map<TreeNode* , TreeNode*> parent;
TreeNode* stNode = NULL;

void build2(TreeNode* node, TreeNode* p, int st){
  if(!node) return;

  parent[node] = p;

  if(node->data == st){
    stNode = node;
    return;
  }

  build2(node->left, node, st);
  build2(node->right, node, st);
}

//* Doing BFS on Tree 

int main(){
  if(!stNode) return 0;

  queue<TreeNode*> q;
  unordered_set<TreeNode*> vis;

  q.push(stNode);
  vis.insert(stNode);

  int time = -1;

  while(!q.empty()){
    int size = q.size();

    while(size--){
      TreeNode* node = q.front();
      q.pop();

      if(node->left && !vis.count(node->left)){
        vis.insert(node->left);
        q.push(node->left);
      }

      if(node->right && !vis.count(node->right)){
        vis.insert(node->right);
        q.push(node->right);
      }

      if(parent[node] && !vis.count(parent[node])){
        vis.insert(parent[node]);
        q.push(parent[node]);
      }
    }

    time++;
  }

  return 0;
}
