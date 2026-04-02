#include <bits/stdc++.h>
using namespace std;

//! SegTree + Co-ordinate Compression

struct segTree{ // Here it stores freq of prev prefixes
  int n;
  vector<int> seg;

  segTree(int N){
    n = N;
    seg.resize(4*n,0);
  } 

  void update(int pos, int val, int i, int l, int r){
    if(l == r){
      seg[i] += val;
      return;
    }

    int mid = (l + r) >> 1;

    if(pos <= mid)
      update(pos, val, 2*i+1, l, mid);
    else
      update(pos, val, 2*i+2, mid+1, r);

    seg[i] = seg[2*i+1] + seg[2*i+2];
  }

  int query(int ql, int qr, int i, int l, int r){
    if(l > qr || r < ql) return 0;

    if(l >= ql && r <= qr) return seg[i];

    int mid = (l + r) >> 1;
    
    return query(ql, qr, 2*i+1, l, mid) + query(ql, qr, 2*i+2, mid+1, r);
  }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int L, int R) {
    int n = nums.size();

    vector<long long> pref(n + 1, 0);
    for(int i = 1; i <= n; i++){
      pref[i] = pref[i - 1] + nums[i - 1];
    }      

    // L <= pref[l] - pref[r - 1] <= R
    // L - pref[l] <= -pref[r - 1] <= R - pref[l]
    // pref[l] - L >= pref[r - 1] >= pref[l] - R
    // pref[l] - R <= pref[r - 1] <= pref[l] - L
    // Low <= prefSum <= High

    vector<long long> vals;
    for(int i = 0; i <= n; i++){
      vals.push_back(pref[i]);
      vals.push_back(pref[i] - L);
      vals.push_back(pref[i] - R);
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = vals.size();
    segTree st(m);

    // Co-ordinate Compressed Idx from vals
    auto getId = [&](long long x){
      return lower_bound(begin(vals), end(vals), x) - vals.begin();
    };

    // Initally insert pref[0] = 0
    st.update(getId(0),1, 0, 0, m-1);
    long long ans = 0;

    for(int j = 1; j <= n; j++){
      long long cur = pref[j];

      long long low = cur - R;
      long long high = cur - L;

      // First Idx >= low
      int l = lower_bound(vals.begin(), vals.end(), low) - vals.begin();
      // First Idx > high
      int r = upper_bound(vals.begin(), vals.end(), high) - vals.begin();

      //! Valid idx - [l,r) but segTree accepts both closed intervals      
      // so we pass range [l.. r-1] 
      if(l < r)
        ans += st.query(l,r-1,0,0,m-1);

      st.update(getId(cur), 1, 0, 0, m-1); 
    }

    return ans;
    }
};