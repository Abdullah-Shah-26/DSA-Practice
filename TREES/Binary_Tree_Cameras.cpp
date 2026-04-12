#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Post Order DP + Greedy Placement
//* TC = O(N) | SC = O(H)

class Solution {
  public:
    //               0            1          2
    enum State { NOT_COVERED, HAS_CAMERA, COVERED};

    int dfs(TreeNode* root, int &cameras){
      if(!root) return COVERED;

      int left = dfs(root->left, cameras);
      int right = dfs(root->right, cameras);

      if(left == NOT_COVERED || right == NOT_COVERED){
        cameras++; // place camera to fix child
        return HAS_CAMERA;
      }

      if(left == HAS_CAMERA || right == HAS_CAMERA){
        return COVERED; // covered by child's camera
      }

      return NOT_COVERED; // both children covered, but no camera here
    }

    int minCameraCover(TreeNode* root) {
      if(!root) return 0;
    
      int cameras = 0;

      if(dfs(root, cameras) == NOT_COVERED){
        cameras++;
      }

      return cameras;
    }
};


//! Iterative Post Order DFS

struct Frame{
  TreeNode* node;
  int state; // 0 = GoLeft | 1 = GoRight | 2 = Process
  int leftState;
  int rightState; 
};

class Solution {
  public:
    enum State {NOT_COVERED, HAS_CAMERA, COVERED};

    // Treating Null as covered, since we are minimizing cameras

    int minCameraCover(TreeNode* root) {
    if(!root) return 0;

    int cameras =0;

    stack<Frame> st;    
    st.push({root, 0, COVERED, COVERED});

    int lastState = COVERED; // return value from child

    while(!st.empty()){
      auto &f = st.top();

      if(!f.node){
        lastState = COVERED;
        st.pop();
        continue;
      }

      if(f.state == 0){ // First Visit
        f.state = 1; // Go Left
        st.push({f.node->left, 0, COVERED, COVERED});
      }

      else if(f.state == 1){ // Left child Computed
        f.leftState = lastState; // Assign return value from left child
        f.state = 2; // Go Right
        st.push({f.node->right, 0, COVERED, COVERED});
      }

      else if(f.state == 2){ // Right child Computed
        f.rightState = lastState; // Assign return value from right child

        // Same as recursion logic

        if(f.leftState == NOT_COVERED || f.rightState == NOT_COVERED)
        { cameras++;
          lastState = HAS_CAMERA; // Put camera
        }
        else if(f.leftState == HAS_CAMERA || f.rightState == HAS_CAMERA){
          lastState = COVERED; // Covered by either child
        }
        else
        lastState = NOT_COVERED; // Covered by none
      
        st.pop();
      }
    }

    if(lastState == NOT_COVERED) cameras++;

    return cameras;
    }
};