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

#define rv(a) \
  for (auto& x : (a)) cin >> x
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

struct SegTree {
  int n;
  vll seg;
  vll lazy;

  SegTree(int n, vll& a) {
    this->n = n;

    seg.resize(4 * n);
    lazy.resize(4 * n);

    build(1, 0, n - 1, a);
  }

  void build(int i, int l, int r, vll& a) {
    if (l == r) {
      seg[i] = a[l];
      return;
    }

    int mid = (l + r) >> 1;

    build(2 * i, l, mid, a);
    build(2 * i + 1, mid + 1, r, a);

    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
  }

  // Apply update & remember pending update
  void apply(int i, ll val) {
    seg[i] += val;
    lazy[i] += val;
  }

  // Propogate pending updates to children
  void push(int i, int l, int r) {
    if (lazy[i] == 0 || l == r) return;

    apply(2 * i, lazy[i]);
    apply(2 * i + 1, lazy[i]);

    lazy[i] = 0;
  }

  // Range update
  void update(int i, int l, int r, int ql, int qr, ll val) {
    if (l > qr || r < ql) return;

    if (l >= ql && r <= qr) {
      apply(i, val);
      return;
    }

    push(i, l, r);

    int mid = (l + r) >> 1;

    update(2 * i, l, mid, ql, qr, val);
    update(2 * i + 1, mid + 1, r, ql, qr, val);

    seg[i] = min(seg[2 * i], seg[2 * i + 1]);
  }

  // Range min query
  ll query(int i, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return LINF;

    if (l >= ql && r <= qr) return seg[i];

    int mid = (l + r) >> 1;

    push(i, l, r);

    ll L = query(2 * i, l, mid, ql, qr);
    ll R = query(2 * i + 1, mid + 1, r, ql, qr);

    return min(L, R);
  }

  void update(int l, int r, ll val) {
    if (l <= r) {
      update(1, 0, n - 1, l, r, val);
    } else {
      // Circular query : l > r
      // Convert to normal query : [l, n - 1] union [0, r]
      update(1, 0, n - 1, l, n - 1, val);
      update(1, 0, n - 1, 0, r, val);
    }
  }

  ll query(int l, int r) {
    if (l <= r) return query(1, 0, n - 1, l, r);

    // Circular query : l > r
    // Convert to normal query : [l, n - 1] union [0, r]
    ll L = query(1, 0, n - 1, l, n - 1);
    ll R = query(1, 0, n - 1, 0, r);

    return min(L, R);
  }
};

void solve() {
  int n;
  cin >> n;

  vll a(n);
  rv(a);

  SegTree seg(n, a);

  int q;
  cin >> q;

  string line;
  getline(cin, line);

  while (q--) {
    getline(cin, line);
    stringstream ss(line);

    // Given l, r are 0 based idx
    int l, r;
    ll v;

    ss >> l >> r;

    if (ss >> v) {
      // integer update
      seg.update(l, r, v);
    } else {
      // range min query
      cout << seg.query(l, r) << endl;
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