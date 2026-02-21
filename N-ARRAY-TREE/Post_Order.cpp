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

    //! RECURSIVE

    // void solve(Node* root, vector<int>&res)
    // {
    //   if(!root)
    //   return;

    //   for(auto &child : root->children)
    //     solve(child, res);  
     
    //   res.push_back(root->val);
    // }


    //! ITERATIVE
    vector<int> postorder(Node* root) {
    vector<int>res;

    if(!root)
      return res;

    // solve(root,res);  
    stack<pair<Node*,bool>>st;
    st.push({root,false});
    while(!st.empty())
    {
      Node* node = st.top().first;
      bool visited = st.top().second;
      st.pop();

      if(visited)
        res.push_back(node->val);
      else 
      {
        st.push({node, true});

        for(int i = node->children.size()-1; i>=0; i--)
        {
        st.push({node->children[i], false});
        }
      }
    }
    return res;
    }
};