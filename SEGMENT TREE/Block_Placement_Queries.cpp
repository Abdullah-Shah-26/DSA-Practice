#include <bits/stdc++.h>
using namespace std;

class SegTree{
  public:
  int n;
  vector<int> seg;

  SegTree(int n){
    this->n = n;
    seg.assign(4 * n, 0);
  }

  void build(int i, int l, int r){
    if(l == r){
      seg[i] = 0;
      return; 
    }

    int mid = (l + r) >> 1;

    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid + 1, r);

    seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
  }

  void update(int i, int l, int r, int idx, int val){
    if(l == r){
      seg[i] = val;
      return;
    }

    int mid = (l + r) >> 1;

    if(idx <= mid)
      update(2 * i + 1, l, mid, idx, val);
    else
      update(2 * i + 2, mid + 1, r, idx, val);

    seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
  }

  int query(int i, int l, int r, int ql, int qr){
    if(qr < l || r < ql)
      return 0;

    if(l >= ql && r <= qr)
      return seg[i];

    int mid = (l + r) >> 1;

    return max(query(2 * i + 1, l, mid, ql, qr), query(2 * i + 2, mid + 1, r, ql, qr));
  }
};

class Solution {
public:
  vector<bool> getResults(vector<vector<int>>& queries) {
  int n = 50000 + 5;

  set<int> st;
  SegTree seg(n);
  seg.build(0, 0, n-1);

  st.insert(0);
  st.insert(n);

  vector<bool> ans;

  for(auto &q : queries){
    if(q[0] == 1){
      int x = q[1];

      auto it = st.upper_bound(x);
      int nxt = (it != st.end()) ? *it : -1;
      int pre = *prev(it);

      seg.update(0, 0, n-1, x, x - pre);
      seg.update(0, 0, n-1, nxt, nxt - x);

      st.insert(x);
    }
    else{
      int x = q[1];
      int sz = q[2];

      auto it = st.upper_bound(x);
      int pre = *prev(it);

      int maxGap = seg.query(0, 0, n-1, 0, pre);
      int best = max(x - pre, maxGap);

      ans.push_back(best >= sz);
    }
  }

  return ans;    
  }
};