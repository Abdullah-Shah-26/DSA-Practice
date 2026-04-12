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