#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N Log N)
//! SC = O(N)

//! Segment Tree + Co-ordinate Compression

class segTree{
  public:

  int n;
  vector<int> seg;

  segTree(int n): n(n), seg(4*n, 0){}

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
    if(l >= ql && r <= qr) return seg[i];

    if(l > qr ||  r < ql) return 0;

    int mid = (l + r) >> 1;

    return query(ql, qr, 2*i+1, l, mid) + query(ql, qr, 2*i+2, mid+1, r); 
  }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
      int n = nums.size();

      for(auto &x : nums){
        if(x == target) x = 1;
        else x = -1;
      }

      vector<int> pref(n + 1, 0);

      for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + nums[i - 1];
      }

      // Co-ordinate Compression
      vector<int> vals = pref;
      sort(vals.begin(), vals.end());
      vals.erase(unique(vals.begin(), vals.end()), vals.end());

      int m = vals.size();

      segTree seg(m);

      // Id = compressed index of pref value
      auto getId = [&](int x){
        return lower_bound(begin(vals), end(vals), x) - vals.begin();
      };

      seg.update(getId(pref[0]), 1, 0, 0, m-1);

      long long ans = 0;

      for(int j = 1; j <= n; j++){
        int id = getId(pref[j]);

        if(id > 0){
          // Cnt guys strictly smaller than pref[j] in range [0....j-1]
          ans += seg.query(0, id-1, 0, 0, m - 1);
        }

        seg.update(id, 1, 0, 0, m-1);
      }

      return ans;
    }
};