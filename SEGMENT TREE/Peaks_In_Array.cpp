#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O((N + Q) Log N)
//! SC = O(N + Q)

class segTree{
  public:
    int n;
    vector<int> seg;

    segTree(int n) : n(n){
      seg.assign(4*n,0);
    }

    void build(int i, int l, int r, vector<int> &arr){
      if(l == r){
        seg[i] = arr[l];
        return;
      }
      int mid = (l + r) >> 1;

      build(2*i + 1, l, mid, arr);
      build(2*i + 2, mid+1, r, arr);

      seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    void update(int i, int l, int r, int pos, int val){
      if(l == r){
        seg[i] = val;
        return;
      }
      int mid = (l + r) >> 1;

      if(pos <= mid)
        update(2*i+1, l, mid, pos, val);
      else
        update(2*i+2, mid+1, r, pos, val);

      seg[i] = seg[2*i+1] + seg[2*i+2];
    }

    int query(int i, int l, int r, int ql, int qr){
      if(l >= ql && r <= qr)
        return seg[i];
      
      if(l > qr || r < ql) 
        return 0;

      int mid = (l + r) >> 1;

      return query(2*i+1, l, mid, ql, qr) + query(2*i+2, mid+1, r, ql, qr);
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
      int n = nums.size();
      int m = queries.size();

      vector<int> peak(n, 0);

      for(int i = 1; i < n-1; i++){
        if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
          peak[i] = 1;
        }
      }

      segTree st(n);
      st.build(0,0,n-1,peak);

      vector<int> ans;

      for(auto &q : queries){
        if(q[0] == 1){
          int l = q[1], r = q[2];

          if(l+1 <= r-1){ // Cause extreme guys in arr/subarr can't be peaks
            ans.push_back(st.query(0, 0, n-1, l+1, r-1));
          }
          else{
            ans.push_back(0);
          }
        }
        else{
          int pos = q[1], val = q[2];

          nums[pos] = val;

          for(int i = pos-1; i <= pos+1; i++){
            if(i > 0 && i < n-1){
              int newVal = (nums[i] > nums[i-1] && nums[i] > nums[i+1]);
              
              if(peak[i] != newVal){
                peak[i] = newVal;
                st.update(0, 0, n-1, i, newVal);  
              }
            }
          }
        }
      }

      return ans;
    }
};