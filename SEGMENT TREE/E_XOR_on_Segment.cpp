#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;
using vpll = vector<pll>;
using vvpll = vector<vector<pll>>;
using T = tuple<ll, ll, ll>;

const int INF = 1e9;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

class SegTree {

private:
  struct Node {
    int cnt[20] = {};
    int lazy = 0;
  };

  int n;
  vector<Node> seg;

public:
  SegTree(vi &a) {
    n = a.size();
    seg.resize(4 * n);
    build(1, 0, n - 1, a);
  }

  void build(int i, int l, int r, vi &a) {
    if (l == r) {
      for (int b = 0; b < 20; b++) {
        seg[i].cnt[b] = ((a[l] >> b) & 1);
      }

      return;
    }

    int mid = l + (r - l) / 2;

    build(2 * i, l, mid, a);
    build(2 * i + 1, mid + 1, r, a);

    for (int b = 0; b < 20; b++) {
      seg[i].cnt[b] = seg[2 * i].cnt[b] + seg[2 * i + 1].cnt[b];
    }
  }

  // Modifies 1 segment tree node
  void apply(int i, int l, int r, int x) {
    int len = r - l + 1;

    for (int b = 0; b < 20; b++) {
      if ((x >> b) & 1) {

        // Since xor flips the bits
        seg[i].cnt[b] = len - seg[i].cnt[b];
      }
    }

    seg[i].lazy ^= x;
  }

  void push(int i, int l, int r) {
    if (seg[i].lazy == 0 || l == r)
      return;

    int mid = l + (r - l) / 2;
    int x = seg[i].lazy;

    apply(2 * i, l, mid, x);
    apply(2 * i + 1, mid + 1, r, x);

    seg[i].lazy = 0;
  }

  // Return sum of segment
  ll query(int i, int l, int r, int ql, int qr) {
    if (l > qr || r < ql)
      return 0;

    if (l >= ql && r <= qr) {
      ll sum = 0;

      for (int b = 0; b < 20; b++) {
        sum += 1LL * seg[i].cnt[b] * (1 << b);
      }

      return sum;
    }

    // Before querying nodes should be updated
    push(i, l, r);

    int mid = l + (r - l) / 2;

    return query(2 * i, l, mid, ql, qr) + query(2 * i + 1, mid + 1, r, ql, qr);
  }

  // Applies xor x to entire segment and updates values
  void update(int i, int l, int r, int ql, int qr, int x) {
    if (l > qr || r < ql)
      return;

    if (l >= ql && r <= qr) {
      apply(i, l, r, x);
      return;
    }

    push(i, l, r);

    int mid = (l + r) >> 1;

    update(2 * i, l, mid, ql, qr, x);
    update(2 * i + 1, mid + 1, r, ql, qr, x);

    for (int b = 0; b < 20; b++) {
      seg[i].cnt[b] = seg[2 * i].cnt[b] + seg[2 * i + 1].cnt[b];
    }
  }

  ll query(int l, int r) { return query(1, 0, n - 1, l, r); }

  void update(int l, int r, int x) { update(1, 0, n - 1, l, r, x); }
};

void solve() {
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  SegTree seg(a);

  int q;
  cin >> q;

  while (q--) {
    int t, l, r, x;
    cin >> t;

    if (t == 1) {
      cin >> l >> r;
      l--, r--;
      cout << seg.query(l, r) << endl;
    } else {
      cin >> l >> r >> x;
      l--, r--;
      seg.update(l, r, x);
    }
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}