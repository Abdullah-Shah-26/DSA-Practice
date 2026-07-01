#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);

struct info {
  int open, close, full;
  info() {
    open = 0;
    close = 0;
    full = 0;
  }
  info(int o, int c, int f) {
    open = o;
    close = c;
    full = f;
  }
};

info merge(info left, info right) {
  info ans = info();
  ans.full = left.full + right.full + min(left.open, right.close);
  ans.open = left.open + right.open - min(left.open, right.close);
  ans.close = left.close + right.close - min(left.open, right.close);
  return ans;
}

void build(int idx, int low, int high, const string &s, vector<info> &seg) {
  if (low == high) {
    seg[idx] = info(s[low] == '(', s[low] == ')', 0);
    return;
  }
  int mid = (low + high) >> 1;
  build(2 * idx + 1, low, mid, s, seg);
  build(2 * idx + 2, mid + 1, high, s, seg);
  seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
}

info query(int idx, int low, int high, int l, int r, vector<info> &seg) {
  if (r < low || high < l)
    return info();
  if (low >= l && high <= r) {
    return seg[idx];
  }
  int mid = (low + high) >> 1;
  info left = query(2 * idx + 1, low, mid, l, r, seg);
  info right = query(2 * idx + 2, mid + 1, high, l, r, seg);
  return merge(left, right);
}

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<info> seg(4 * n);
  build(0, 0, n - 1, s, seg);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    if (l < 0 || r >= n || l > r) {
      cout << 0 << "\n"; // Handle invalid range safety break
      continue;
    }
    info ans = query(0, 0, n - 1, l, r, seg);
    cout << 2 * ans.full << endl;
  }
}
int main() {
  fastio;
  solve();
  return 0;
}