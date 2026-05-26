#include <bits/stdc++.h>
using namespace std;

// TC = O(N Log N) | SC = O(4 * N)

class segTree{
  vector<int> seg;
  int n;

  public:
  segTree(int n){
    this->n = n;
    seg.resize(4 * n, 0);
  }

  void update(int idx, int val){
    update(0, 0, n-1, idx, val);
  }

  int query(int l, int r){
    if(l > r) return 0;
    return query(0, 0, n-1, l, r);
  }

  private:
  void update(int i, int l, int r, int pos, int val){
    if(l == r){
      seg[i] = max(seg[i], val);
      return;
    }

    int mid = (l + r) >> 1;

    if(pos <= mid)
      update(2 * i + 1, l, mid, pos, val);
    else 
      update(2 * i + 2, mid + 1, r, pos, val);

    seg[i] =  max(seg[2 * i + 1], seg[2 * i + 2]);
  }

  int query(int i, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return 0;

    if(l >= ql && r <= qr){
      return seg[i];
    }

    int mid = (l + r) >> 1;

    return max(query(2 * i + 1, l, mid, ql, qr), query(2 * i + 2, mid + 1, r, ql, qr));
  }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> vals = nums;

    sort(vals.begin(), vals.end());

    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = vals.size();

    auto getId = [&](int x){
      return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    };

    segTree seg(m);      

    int ans = 0;

    for(int x : nums){
      int id = getId(x);

      int L = lower_bound(vals.begin(), vals.end(), x - k) - vals.begin();
      int R = id - 1; // we want guys < x

      int best = seg.query(L,R);

      // dp[i] = max(dp[j] + 1)
      int cur = best + 1; // Best LIS ending at value x 

      ans = max(ans, cur);

      seg.update(id, cur);
    }

    return ans;
    }
};