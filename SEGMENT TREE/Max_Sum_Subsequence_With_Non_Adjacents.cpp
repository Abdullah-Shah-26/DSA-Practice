#include <bits/stdc++.h>
using namespace std;

// TC = O(N + QLogN) | SC = O(N)

/*

dp[0][0] -> First not taken, last not taken
dp[0][1] -> First not taken, last taken
dp[1][0] -> First taken, last not taken
dp[1][1] -> First taken, last taken

*/

using ll = long long;
const ll NLINF = -1e18;
const int MOD = 1e9 + 7;

class SegTree{
public:

  struct Node{
    ll dp[2][2]; // dp[firstTaken][lastTaken]

    Node(){
      for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
          dp[i][j] = NLINF;
        }
      }
    }
  };

  int n;
  vector<Node> seg;

  SegTree(vector<int> &nums){
    n = nums.size();

    seg.resize(4 * n);

    build(0, 0, n-1, nums);
  }

  Node merge(Node left, Node right){
    Node parent;

    for(int lf = 0; lf < 2; lf++){
      for(int ll = 0; ll < 2; ll++){
        for(int rf = 0; rf < 2; rf++){
          for(int rl = 0; rl < 2; rl++){

            // Adjacent selected - Invalid case - skip
            if(ll == 1 && rf == 1){
              continue;
            }

            parent.dp[lf][rl] = max(parent.dp[lf][rl], left.dp[lf][ll] + right.dp[rf][rl]);
          }
        }
      }
    }

    return parent;
  }

  void build(int i, int l, int r, vector<int> &nums){
    if(l == r){
      
      // Take nothing
      seg[i].dp[0][0] = 0;

      // For single element, first == last 
      seg[i].dp[1][1] = max(0LL, (ll)nums[l]);

      return;
    }

    int mid = (l + r) >> 1;

    build(2 * i + 1, l, mid, nums);
    build(2 * i + 2, mid + 1, r, nums);

    seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
  }

  void update(int i, int l, int r, int pos, int val){
    if(l == r){
      Node leaf;

      // Take nothing
      leaf.dp[0][0] = 0;
      
      // For single element, first == last
      leaf.dp[1][1] = max(0LL, (ll)val);

      seg[i] = leaf;

      return;
    }

    int mid = (l + r) >> 1;

    if(pos <= mid){
      update(2 * i + 1, l, mid, pos, val);
    }
    else{
      update(2 * i + 2, mid + 1, r, pos, val);
    }

    seg[i] = merge(seg[2 * i + 1], seg[2 * i + 2]);
  }

  void update(int idx, int val){
    update(0, 0, n-1, idx, val);
  }

  ll getMax(){
    ll best = 0;

    for(int first = 0; first < 2; first++){
      for(int last = 0; last < 2; last++){
        best = max(best, seg[0].dp[first][last]);
      }
    }

    return best;
  }
};

class Solution {
public:  
  int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
  int n = nums.size();

  SegTree seg(nums);

  ll ans = 0;

  for(auto &q : queries){
    int idx = q[0];
    int val = q[1];

    seg.update(idx, val);

    ans = (ans + seg.getMax()) % MOD;
  }

  return ans;    
  }
};