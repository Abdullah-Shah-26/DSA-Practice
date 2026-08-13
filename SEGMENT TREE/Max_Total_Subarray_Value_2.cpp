#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using T = tuple<ll, int, int>;
using pii = pair<int, int>;

class SegTree {
public:
  int n;
  vector<pii> seg;

  pii merge(pii a, pii b) {
    return {min(a.first, b.first), max(a.second, b.second)};
  }

  void build(int i, int l, int r, vector<int> &a) {
    if (l == r) {
      seg[i] = {a[l], a[l]};
      return;
    }

    int mid = (l + r) >> 1;

    build(2 * i, l, mid, a);
    build(2 * i + 1, mid + 1, r, a);

    seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
  }

  pii query(int i, int l, int r, int ql, int qr) {
    if (l > qr || r < ql)
      return {1e9, -1e9};

    if (l >= ql && r <= qr)
      return seg[i];

    int mid = (l + r) >> 1;

    pii left = query(2 * i, l, mid, ql, qr);
    pii right = query(2 * i + 1, mid + 1, r, ql, qr);

    return merge(left, right);
  }

  SegTree(vector<int> &a) {
    n = a.size();
    seg.resize(4 * n);
    build(1, 0, n - 1, a);
  }

  pii query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

class Solution {
public:
  long long maxTotalValue(vector<int> &nums, int k) {
    int n = nums.size();

    priority_queue<T> pq;

    SegTree seg(nums);

    // Heap initialization
    for (int l = 0; l < n; l++) {
      auto [mini, maxi] = seg.query(l, n - 1);
      ll value = maxi - mini;
      pq.push({value, l, n - 1});
    }

    ll ans = 0;

    // Find Top K
    while (k--) {
      auto [value, l, r] = pq.top();
      pq.pop();

      ans += value;

      if (r > l) {
        auto [mini, maxi] = seg.query(l, r - 1);
        ll next = maxi - mini;
        pq.push({next, l, r - 1});
      }
    }

    return ans;
  }
};