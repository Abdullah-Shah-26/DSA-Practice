#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
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
const ll LINF = 1e18;
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
#define rm(mat)         \
  for (auto& r : (mat)) \
    for (auto& x : (r)) cin >> x
#define pm(mat)                                   \
  do {                                            \
    for (const auto& r : (mat)) {                 \
      for (const auto& x : (r)) cout << x << ' '; \
      cout << '\n';                               \
    }                                             \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define endl '\n'

const int N = 400005;

vi adj[N];
ll color[N];
ll euler[N];

ll in[N], out[N];
ll timer = 0;

ll seg[4 * N];
ll lazy[4 * N];

void dfs(int u, int p) {
  in[u] = ++timer;

  euler[timer] = (1LL << color[u]);

  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }

  out[u] = timer;
}

void push(int i, int l, int r) {
  if (lazy[i] != 0) {
    seg[i] = lazy[i];

    if (l != r) {
      lazy[2 * i] = lazy[i];
      lazy[2 * i + 1] = lazy[i];
    }

    lazy[i] = 0;
  }
}

void build(int i, int l, int r) {
  lazy[i] = 0;
  if (l == r) {
    seg[i] = euler[l];
    return;
  }

  int mid = (l + r) >> 1;
  build(2 * i, l, mid);
  build(2 * i + 1, mid + 1, r);

  seg[i] = seg[2 * i] | seg[2 * i + 1];
}

void update(int i, int l, int r, int ql, int qr, ll newMask) {
  push(i, l, r);

  if (l > qr || r < ql) return;

  if (l >= ql && r <= qr) {
    lazy[i] = newMask;
    push(i, l, r);
    return;
  }

  int mid = (l + r) >> 1;
  update(2 * i, l, mid, ql, qr, newMask);
  update(2 * i + 1, mid + 1, r, ql, qr, newMask);

  seg[i] = seg[2 * i] | seg[2 * i + 1];
}

ll query(int i, int l, int r, int ql, int qr) {
  push(i, l, r);

  if (l > qr || r < ql) return 0;

  if (l >= ql && r <= qr) return seg[i];

  int mid = (l + r) >> 1;
  return query(2 * i, l, mid, ql, qr) | query(2 * i + 1, mid + 1, r, ql, qr);
}

void solve() {
  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; i++) cin >> color[i];

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(1, 0);

  build(1, 1, n);

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int v, c;
      cin >> v >> c;
      update(1, 1, n, in[v], out[v], (1LL << c));
    } else {
      int v;
      cin >> v;
      ll mask = query(1, 1, n, in[v], out[v]);
      cout << __builtin_popcountll(mask) << endl;
    }
  }
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}