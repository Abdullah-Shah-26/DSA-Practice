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

class SegTree {
 private:
  struct Node {
    ll mn, mx;
  };

  int n;
  vector<Node> seg;

  Node merge(const Node& a, const Node& b) {
    return {min(a.mn, b.mn), max(a.mx, b.mx)};
  }

  void build(int i, int l, int r, vll& a) {
    if (l == r) {
      seg[i] = {a[l], a[l]};
      return;
    }

    int mid = (l + r) >> 1;

    build(2 * i, l, mid, a);
    build(2 * i + 1, mid + 1, r, a);

    seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
  }

  Node query(int i, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return {LINF, -LINF};  // mn, mx

    if (l >= ql && r <= qr) return seg[i];

    int mid = (l + r) >> 1;

    Node L = query(2 * i, l, mid, ql, qr);
    Node R = query(2 * i + 1, mid + 1, r, ql, qr);

    return merge(L, R);
  }

 public:
  SegTree(vll& a) {
    n = (int)a.size();
    seg.resize(4 * n);
    build(1, 0, n - 1, a);
  }

  ll queryMin(int l, int r) {
    if (l > r) return LINF;

    return query(1, 0, n - 1, l, r).mn;
  }

  ll queryMax(int l, int r) {
    if (l > r) return -LINF;

    return query(1, 0, n - 1, l, r).mx;
  }
};

void solve() {
  int n;
  cin >> n;

  vll a(n);
  rv(a);

  // prefix sum
  vll pref(n + 1, 0);
  for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

  // Previous greater element
  // Next greater element
  vi pge(n, -1), nge(n, n);
  stack<int> st;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && a[st.top()] <= a[i]) st.pop();

    if (!st.empty()) pge[i] = st.top();

    st.push(i);
  }

  while (!st.empty()) st.pop();

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && a[st.top()] <= a[i]) st.pop();

    if (!st.empty()) nge[i] = st.top();

    st.push(i);
  }

  SegTree seg(pref);

  for (int i = 0; i < n; i++) {
    
    // Array: [i, nge[i] - 1]
    // Prefix sums: [i + 1, nge[i]]
    ll maxRight = seg.queryMax(i + 1, nge[i]);

    // Array: [pge[i] + 1, i - 1]
    // Prefix sums: [pge[i] + 1, i]
    ll minLeft = seg.queryMin(pge[i] + 1, i);

    if (maxRight - minLeft > a[i]) {
      NO;
      return;
    }
  }

  YES;
  return;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}