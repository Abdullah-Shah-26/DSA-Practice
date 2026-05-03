#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};
// Recursive

class Solution{
  public: 
  void serialize(Node* root, vector<int>& stream)
  {
    if(!root) return;

    stream.push_back(root->val);

    for(Node* child : root->children)
      serialize(child, stream);

    stream.push_back(-1); // End Marker for This Node's Children
  }
  Node* deserialize(vector<int>& stream, int& idx)
  {
    if(idx >= stream.size()) return NULL;

    Node* node = new Node(stream[idx++]);

    while(idx < stream.size() && stream[idx] != -1)
    {
      node->children.push_back(deserialize(stream,idx));
    }
    idx++; // consumes -1;
    return node;
  }
};

// Iterative 

