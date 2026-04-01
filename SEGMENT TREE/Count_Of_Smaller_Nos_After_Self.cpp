#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Segment Tree + Co-ordinate Compression
class segTree{
  public: 
    int n;
    vector<int> seg;

    segTree(int n): n(n){
      seg.resize(4*n,0);
    }

    void update(int i, int val, int node, int l, int r){
      if(l == r){
        seg[node] += val;
        return;
      }

      int mid = (l + r) >> 1;

      if(i <= mid)
        update(i, val, 2*node + 1, l, mid);
      else
        update(i, val, 2*node + 2, mid+1, r);

      seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    int query(int ql, int qr, int node, int l, int r){
      if(l > qr || r < ql) return 0;

      if(l >= ql && r <= qr) return seg[node];

      int mid = (l + r) >> 1;

      return query(ql, qr, 2*node+1, l, mid) + query(ql, qr, 2*node+2, mid+1, r);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();

    // Co-ordiante Compression
    vector<int> vals = nums;
    sort(begin(vals), end(vals));
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = vals.size();

    segTree st(m);
    vector<int> ans(n);

    for(int i = n-1; i >= 0; i--){
      int id = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();

      if(id > 0){
        ans[i] = st.query(0,id-1,0,0,m-1);
      }else{
        ans[i] = 0;
      }

    st.update(id, 1, 0, 0, m-1);
    }
    
    return ans;
    }
};