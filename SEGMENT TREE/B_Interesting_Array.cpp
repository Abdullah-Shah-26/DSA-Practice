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
#define pv(a)                                   \
  do {                                          \
    for (const auto& x : (a)) cout << x << ' '; \
    cout << '\n';                               \
  } while (0)
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

// Segtree to get AND of range [l...r]
class SegTree {
 public:
  int n;
  vi seg;

  SegTree(vi& a) {
    n = (int)a.size();
    seg.resize(4 * n);
    build(1, 0, n - 1, a);
  }

  void build(int i, int l, int r, vi& a) {
    if (l == r) {
      seg[i] = a[l];
      return;
    }

    int mid = (l + r) >> 1;

    build(2 * i, l, mid, a);
    build(2 * i + 1, mid + 1, r, a);

    seg[i] = (seg[2 * i] & seg[2 * i + 1]);
  }

  int query(int i, int l, int r, int ql, int qr) {
    // No Overlap, return max possible value cause bitwise and only preserves a
    // bit if both no's have those bit set
    if (l > qr || r < ql) return (1 << 30) - 1;

    // Full Overlap
    if (l >= ql && r <= qr) return seg[i];

    int mid = (l + r) >> 1;

    int L = query(2 * i, l, mid, ql, qr);
    int R = query(2 * i + 1, mid + 1, r, ql, qr);

    return L & R;
  }

  int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<vector<int>> queries;

  for (int i = 0; i < m; i++) {
    int l, r, q;
    cin >> l >> r >> q;

    l--;
    r--;

    queries.push_back({l, r, q});
  }

  vvi diff(30, vi(n + 1, 0));

  for (auto& q : queries) {
    int l = q[0];
    int r = q[1];
    int Q = q[2];

    // Each bit set in Q must also be set in all the elements in the range
    // [L...R] so that AND of all range = Q
    for (int b = 0; b < 30; b++) {
      if (Q & (1 << b)) {
        diff[b][l]++;
        diff[b][r + 1]--;
      }
    }
  }

  vi a(n, 0);

  for (int b = 0; b < 30; b++) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
      cnt += diff[b][i];

      // This active range, requires this bit to be set
      if (cnt > 0) a[i] |= (1 << b);
    }
  }

  SegTree seg(a);

  for (auto& q : queries) {
    int l = q[0];
    int r = q[1];
    int Q = q[2];

    if (seg.query(l, r) != Q) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
  for (auto x : a) cout << x << " ";

  cout << endl;

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}