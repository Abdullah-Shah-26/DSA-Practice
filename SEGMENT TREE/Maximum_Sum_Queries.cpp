#include <bits/stdc++.h>
using namespace std;

// Offline Processing
// Sort points + queries descending by x

// While processing query(x, y):
// Insert all points with nums1[i] >= x

// Segment Tree on compressed nums2 axis
// Stores max(nums1[i] + nums2[i])

// Query suffix range:
// nums2[i] >= y

class SegTree {
public:
  int n;
  vector<int> seg;

  SegTree(int n) {
    this->n = n;
    seg.assign(4 * n, -1);
  }

  void update(int i, int l, int r, int pos, int val) {

    if(l == r) {
      seg[i] = max(seg[i], val);
      return;
    }

    int mid = (l + r) >> 1;

    if(pos <= mid) {
      update(2 * i + 1, l, mid, pos, val);
    }
    else {
      update(2 * i + 2, mid + 1, r, pos, val);
    }

    seg[i] = max(seg[2 * i + 1],
                 seg[2 * i + 2]);
  }

  int query(int i, int l, int r, int ql, int qr) {

    if(r < ql || l > qr) {
      return -1;
    }

    if(ql <= l && r <= qr) {
      return seg[i];
    }

    int mid = (l + r) >> 1;

    return max(
      query(2 * i + 1, l, mid, ql, qr),
      query(2 * i + 2, mid + 1, r, ql, qr)
    );
  }
};

class Solution {
public:

  vector<int> maximumSumQueries(vector<int>& nums1,
                                vector<int>& nums2,
                                vector<vector<int>>& queries) {

    int n = nums1.size();
    int q = queries.size();

    vector<array<int,3>> points;

    for(int i = 0; i < n; i++) {
      points.push_back({
        nums1[i],
        nums2[i],
        nums1[i] + nums2[i]
      });
    }

    // Bigger nums1 first
    sort(points.begin(), points.end(),
      [&](auto &a, auto &b){
        return a[0] > b[0];
      });

    vector<int> vals;

    for(int x : nums2) {
      vals.push_back(x);
    }

    // {x, y, originalIdx}
    vector<array<int,3>> qs;

    for(int i = 0; i < q; i++) {

      int x = queries[i][0];
      int y = queries[i][1];

      qs.push_back({x, y, i});

      vals.push_back(y);
    }

    // Coordinate Compression on nums2
    sort(vals.begin(), vals.end());

    vals.erase(unique(vals.begin(), vals.end()),
               vals.end());

    auto getIdx = [&](int x) {
      return lower_bound(vals.begin(),
                         vals.end(),
                         x) - vals.begin();
    };

    // Bigger x first
    sort(qs.begin(), qs.end(),
      [&](auto &a, auto &b){
        return a[0] > b[0];
      });

    int m = vals.size();

    SegTree st(m);

    vector<int> ans(q);

    int j = 0;

    for(auto &qq : qs) {

      int x = qq[0];
      int y = qq[1];
      int idx = qq[2];

      // Insert all valid nums1
      while(j < n && points[j][0] >= x) {

        int pos = getIdx(points[j][1]);

        st.update(0, 0, m - 1,
                  pos,
                  points[j][2]);

        j++;
      }

      int yPos = getIdx(y);

      // Query nums2 >= y
      ans[idx] = st.query(0, 0, m - 1,
                          yPos,
                          m - 1);
    }

    return ans;
  }
};