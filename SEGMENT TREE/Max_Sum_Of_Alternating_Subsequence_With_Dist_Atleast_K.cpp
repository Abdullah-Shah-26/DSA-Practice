#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LINF = 1e18;

class SegTree{
public:
  int n;
  vector<ll> seg;

  SegTree(int sz){
    n = sz;
    seg.assign(4 * n, -LINF);
  }

  void update(int i, int l, int r, int pos, ll val){
    if(l == r){
      seg[i] = max(seg[i], val);
      return;
    }

    int mid = (l + r) >> 1;
    if(pos <= mid)
      update(2 * i + 1, l, mid, pos, val);
    else 
      update(2 * i + 2, mid + 1, r, pos, val);

    seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
  }

  void update(int idx, ll val){
    update(0, 0, n-1, idx, val);
  }

  ll query(int i, int l, int r, int ql, int qr){
    if(ql > r || qr < l)
      return -LINF;

    if(l >= ql && r <= qr) 
      return seg[i];

    int mid = (l + r) >> 1;

    return max(query(2 * i + 1, l, mid, ql, qr), query(2 * i + 2, mid + 1, r, ql, qr));
  }

  ll query(int l, int r){
    if(l > r) 
      return -LINF;
      
    return query(0, 0, n-1, l, r);
  }
};

class Solution {
public:
  long long maxAlternatingSum(vector<int>& nums, int k) {
    int n = nums.size();    
    
    vector<int> vals = nums;

    sort(begin(vals), end(vals));
    vals.erase(unique(begin(vals), end(vals)), end(vals));

    auto getId = [&](int x){
      return lower_bound(begin(vals), end(vals), x) - begin(vals);
    };

    int m = vals.size();

    SegTree upTree(m);
    SegTree downTree(m);

    vector<ll> up(n);
    vector<ll> down(n);
     
    ll ans = 0;
    
    for(int i = 0; i < n; i++){
      if(i >= k){
        int idx = getId(nums[i - k]); // Compressed pos of nums[i - k] 
        upTree.update(idx, up[i - k]);
        downTree.update(idx, down[i - k]);
      }

      int id = getId(nums[i]);
      up[i] = nums[i];
      down[i] = nums[i];

      // state = what happened last 
      // up[i] = best score ending at i where last comparision was .... < nums[i]
      // down[i] = best score ending at i where last comparision was .... > nums[i]

      // prev > cur
      ll best = upTree.query(id + 1, m - 1);
      if(best != -LINF)
        down[i] = max(down[i], best + nums[i]);
      
      // prev < cur
      best = downTree.query(0, id - 1);
      if(best != -LINF)
        up[i] = max(up[i], best + nums[i]);

      ans = max({ans, up[i], down[i]});
    }

    return ans;
  }
};