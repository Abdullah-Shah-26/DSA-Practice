#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DFS - Recursive

class Solution {
  public:
  //TODO : Post Order Traversal
  int moves;
  int solve(TreeNode* node){
    if(!node) return 0;

    int L = solve(node->left);
    int R = solve(node->right);
    moves += abs(L) + abs(R);

    return (node->val - 1) + L + R;
  }  
  
  int distributeCoins(TreeNode* root) {
  moves = 0;class Solution {
  public:
  // Post Order Traversal
  int moves;
  int solve(TreeNode* node){
    if(!node) return 0;

    int L = solve(node->left);
    int R = solve(node->right);
    moves += abs(L) + abs(R);

    return (node->val - 1) + L + R;
  }  
  
  int distributeCoins(TreeNode* root) {
  moves = 0;
  solve(root);
  return moves; 
  }
};
  solve(root);
  return moves; 
  }
};

//! DFS Iterative - Stack + HashMap

class Solution {
  public:
    int distributeCoins(TreeNode* root) {
    int moves = 0;

    unordered_map<TreeNode*,int> flow;
    stack<pair<TreeNode*,bool>> st;

    st.push({root, 0});

    while(!st.empty()){
      auto [node, visited] = st.top();
      st.pop();

      if(!node) continue;

      if(!visited){
        //* Post Order
        st.push({node, 1});
        st.push({node->right, 0});
        st.push({node->left, 0});
      }
      else{
        int L = flow[node->left];
        int R = flow[node->right];

        moves += abs(L) + abs(R);

        flow[node] = (node->val - 1) + L + R;
      }
    }

    return moves;
    }
};

//! DFS Iterative - Without HashMap - (Similar to Diameter of BT)

struct Frame{
  TreeNode* node;
  int state; // 0 = GoLeft | 1 = GoRight | 2 = ProcessNode
  int leftFlow;
  int rightFlow;
};

class Solution{
  public:

  int distributeCoins(TreeNode *root){
    int moves = 0;

    stack<Frame> st;
    st.push({root, 0, 0, 0});

    int lastFlow = 0; // Return Value When Child is Processed / Past return value 

    while(!st.empty()){
      auto f = st.top();

      if(!f.node){
        lastFlow = 0;
        st.pop();
        continue;
      }

      if(f.state == 0){ // First visit
        f.state = 1; // Go Left
        st.push({f.node->left, 0, 0, 0});        
      }

      else if(f.state == 1){ // Means Left Node is processed
        f.state = 2; 
        f.leftFlow = lastFlow; // Assign return value from left
        st.push({f.node->right, 0, 0, 0}); // Go Right
      }

      else if(f.state == 2){ // Means Right Node is processed
        f.rightFlow = lastFlow; // Assign return value from right

        moves += abs(f.leftFlow) + abs(f.rightFlow);
        
        lastFlow = (f.node->val - 1) + f.leftFlow + f.rightFlow;

        st.pop();
      }
    }

    return moves;
  }

};
