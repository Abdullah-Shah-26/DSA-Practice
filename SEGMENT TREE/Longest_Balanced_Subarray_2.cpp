#include <bits/stdc++.h>
using namespace std;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N Log N)
//! SC = O(N)

class Solution {  
  public:
  
    struct Node{
      int mini = 0;
      int maxi = 0;
    };

    int n;
    vector<Node> seg;
    vector<int> lazy;

    Node merge(Node a, Node b){
      return {min(a.mini, b.mini), max(a.maxi, b.maxi)};
    }

    // Applying lazy value to node
    void apply(int i, int value){
      seg[i].mini += value;
      seg[i].maxi += value;
      lazy[i] += value;
    }

    // Propogating lazy to children 
    void push(int i){
      if(lazy[i] != 0){
        apply(2*i+1, lazy[i]);
        apply(2*i+2, lazy[i]);
        lazy[i] = 0;
      }
    }

    void update(int ql, int qr, int i, int l,int r, int val){
      if(l > qr || r < ql) return;

      if(l >= ql && r <= qr){
        apply(i, val);
        return;
      }

      push(i); // Ensure values are updated before exploring deeper

      int mid = (l + r) >> 1;
      update(ql, qr, 2*i+1, l, mid, val);
      update(ql, qr, 2*i+2, mid+1, r, val);

      seg[i] = merge(seg[2*i+1], seg[2*i+2]);
    }

    int findLeftMostZero(int i, int l, int r){
      if(seg[i].mini > 0 || seg[i].maxi < 0) return -1;

      if(l == r) return l;

      push(i);

      int mid = (l + r) >> 1;

      int leftRes = findLeftMostZero(2*i+1, l, mid);

      if(leftRes != -1) return leftRes;

      return findLeftMostZero(2*i+2, mid + 1, r); 
    }

    int longestBalanced(vector<int>& nums) {
    n = nums.size();
    seg.assign(4*n, Node());
    lazy.assign(4*n, 0);

    int maxLen = 0;
    unordered_map<int,int> m;

    for(int r = 0; r < n; r++){
      int value = (nums[r] & 1) ? -1 : 1;

      int prev = -1;

      if(m.count(nums[r])){
        prev = m[nums[r]];
      }

      if(prev != -1){
        update(0, prev, 0, 0, n-1, -value);
      }

      update(0, r, 0, 0, n-1, value);

      int l = findLeftMostZero(0, 0, n-1);
      if(l != -1)
        maxLen = max(maxLen, r - l + 1);

      m[nums[r]] = r;
    }

    return maxLen;
    }
};