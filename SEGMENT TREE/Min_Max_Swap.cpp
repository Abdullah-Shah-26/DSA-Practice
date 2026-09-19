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

#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define pv(a)                 \
  do {                        \
    for (const auto &x : (a)) \
      cout << x << ' ';       \
    cout << '\n';             \
  } while (0)
#define rm(mat)         \
  for (auto &r : (mat)) \
    for (auto &x : (r)) \
  cin >> x
#define pm(mat)                   \
  do {                            \
    for (const auto &r : (mat)) { \
      for (const auto &x : (r))   \
        cout << x << ' ';         \
      cout << '\n';               \
    }                             \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define yno(a) cout << ((a) ? "Yes\n" : "No\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

struct Node {
  int mn;
  int mx;
  int mnI;
  int mxI;
};

class SegTree {
  int n;
  vector<Node> seg;

public:
  SegTree(vi &a) {
    n = a.size();
    seg.resize(4 * n);
    build(1, 0, n - 1, a);
  }

  Node merge(Node a, Node b) {
    Node res;

    if (a.mn < b.mn) {
      res.mn = a.mn;
      res.mnI = a.mnI;
    } else {
      res.mn = b.mn;
      res.mnI = b.mnI;
    }

    if (a.mx > b.mx) {
      res.mx = a.mx;
      res.mxI = a.mxI;
    } else {
      res.mx = b.mx;
      res.mxI = b.mxI;
    }

    return res;
  }

  void build(int node, int l, int r, vi &a) {
    if (l == r) {
      seg[node] = {a[l], a[l], l, l};
      return;
    }

    int mid = (l + r) >> 1;

    build(2 * node, l, mid, a);
    build(2 * node + 1, mid + 1, r, a);

    seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
  }

  void update(int node, int l, int r, int pos, int value) {
    if (l == r) {
      seg[node] = {value, value, l, l};
      return;
    }

    int mid = (l + r) >> 1;

    if (pos <= mid)
      update(2 * node, l, mid, pos, value);
    else
      update(2 * node + 1, mid + 1, r, pos, value);

    seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
  }

  void update(int pos, int value) { update(1, 0, n - 1, pos, value); }

  Node query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
      return {INT_MAX, INT_MIN, -1, -1};

    if (ql <= l && r <= qr)
      return seg[node];

    int mid = (l + r) / 2;

    Node left = query(node * 2, l, mid, ql, qr);
    Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

    return merge(left, right);
  }

  Node query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve() {
  int n, m;
  cin >> n >> m;

  vi p(n);

  for (int &x : p)
    cin >> x;

  SegTree seg(p);

  while (m--) {
    int l, r;
    cin >> l >> r;

    l--;
    r--;

    Node cur = seg.query(l, r);

    int mnI = cur.mnI;
    int mxI = cur.mxI;

    swap(p[mnI], p[mxI]);

    seg.update(mnI, p[mnI]);
    seg.update(mxI, p[mxI]);
  }

  for (int x : p)
    cout << x << " ";

  cout << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}