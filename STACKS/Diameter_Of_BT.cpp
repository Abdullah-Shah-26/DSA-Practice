#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N)
//! SC = O(N)

struct Frame{
  TreeNode* node;
  int state;
  int L,R; // leftHt , rightHt
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
      if(!root) return 0;
      
      int result = INT_MIN;

      // 3 states
      
      // 0 - push its left
      // 1 - push its right
      // 2 - process current node

      stack<Frame> st;
      st.push({root, 0, 0, 0});

      while(!st.empty()){
        Frame &cur = st.top();

        if(cur.state == 0){
          cur.state = 1;
          if(cur.node->left)
            st.push({cur.node->left, 0, 0, 0});
        }
        else if(cur.state == 1){
          cur.state = 2;
          if(cur.node->right)
            st.push({cur.node->right, 0, 0, 0});
        }
        else{
          int L = cur.L;
          int R = cur.R;

          result = max(result, L + R);
          int h = 1 + max(L,R);

          st.pop();

          if(!st.empty()){
            Frame &parent = st.top();

            if(parent.state == 1){
              parent.L = h;
            }
            if(parent.state == 2){
              parent.R = h;
            }
          }
        }
      }

      return result;
    }
};