#include <bits/stdc++.h>
using namespace std;

class NumArray {
  public:
    int n;
    vector<int> seg;
    vector<int> arr;

    void build(int i, int l, int r){
      if(l == r){
        seg[i] = arr[l];
        return;
      }

      int mid = (l + r) >> 1;

      build(2 * i + 1, l, mid);
      build(2 * i + 2, mid + 1, r);

      seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    void update(int i, int l, int r, int pos, int val){
      if(l == r){
        seg[i] = val;
        return;
      }

      int mid = (l + r) >> 1;

      if(pos <= mid)
        update(2 * i + 1, l, mid, pos, val);
      else 
        update(2 * i + 2, mid + 1, r, pos, val);

      seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    int query(int i, int l, int r, int ql, int qr){
      if(r < ql || l > qr) return 0;

      if(l >= ql && r <= qr) return seg[i];

      int mid = (l + r) >> 1;

      return query(2 * i + 1, l, mid, ql, qr) + query(2 * i + 2, mid + 1, r, ql, qr); 
    }

    NumArray(vector<int>& nums) {
      arr = nums;
      n = nums.size();
      seg.resize(4 * n);
      build(0, 0, n-1);
    }
    
    void update(int index, int val) {
      update(0, 0, n-1, index, val);
    }
    
    int sumRange(int left, int right) {
      return query(0, 0, n-1, left, right);
    }
};