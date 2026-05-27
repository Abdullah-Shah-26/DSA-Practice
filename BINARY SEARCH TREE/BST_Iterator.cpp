#include <bits/stdc++.h>
using namespace std;

class BSTIterator {
private:
  stack<TreeNode*> st;

  // Takes all the left & push into stack
  void pushAll(TreeNode* node){
    while(node != NULL){
      st.push(node);
      node = node->left;
    }
  }

public:
  BSTIterator(TreeNode* root) {
    pushAll(root);
  }
  
  // Returns next smallest no
  int next() {
    TreeNode* temp = st.top();
    st.pop();

    pushAll(temp->right);
    
    return temp->val;
  }
  
  // Return whether we have a next smallest no
  bool hasNext() {
    return !st.empty();
  }
};