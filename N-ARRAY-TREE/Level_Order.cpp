#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>>res;
    if(!root) return res;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
      vector<int>temp;
      int size = q.size();
      while(size--)
      {
        Node* node = q.front();
        q.pop();
        temp.push_back(node->val);
        for(auto &child : node->children)
          q.push(child);
      }
      res.push_back(temp);
    }
    return res;    
    }
};