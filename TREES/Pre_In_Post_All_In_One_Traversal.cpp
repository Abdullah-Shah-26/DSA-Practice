#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);

class Node
{
  public:
  int data;
  Node* left, *right;
  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
}  

vector<int>PreInPostTraversal(Node* root)
{
  stack<pair<Node*, int>>st;
  vector<int>res;
   if(!root)
    return res;

  vector<int>pre, in, post;
  st.push({root, 1});

  while(!st.empty())
  {
    auto it = st.top();
    st.pop();

    //* This is a part of Pre
    // Increment 1 -> 2 
    // Push Left child if exist
    if(it.second == 1)
    {
      pre.push_back(it.first->data);
      it.second++;
      st.push(it);
      
      if(it.first->left != NULL)
      {
        st.push({it.first->left,1});
      }
    }
    //* This is a part of Post
    // Increment 2 -> 3
    // Push Right Child if exist
    else if(it.second == 2)
    {
      in.push_back(it.first->data);
      it.second++;
      st.push(it);

      if(it.first->right != NULL)
      {
        st.push({it.first->right});
      }
    }
    //* This is a part of Post
    else if(it.second == 3)
    {
      post.push_back(it.first->data);
    }
  }
}
