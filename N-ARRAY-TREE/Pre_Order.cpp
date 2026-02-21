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
    void solve(Node* root,vector<int>&res)
    {
      if(!root)
      return;
      res.push_back(root->val);
      for(auto &child : root->children)
        solve(child, res);
    }

    vector<int> preorder(Node* root) {
    vector<int>res;
    
    if(!root)
      return res;
    // solve(root, res);  
    
    stack<Node*>st;
    st.push(root);
    
    while(!st.empty())
    {
      Node* node = st.top();
      st.pop();
      res.push_back(node->val);

      for(int i = node->children.size() - 1; i>=0;i--)
        st.push(node->children[i]);
    }
    
    return res;
    }
};