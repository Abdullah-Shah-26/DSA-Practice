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
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================
Observation / Thinking
--------------------------

If depth[node] and depth[x] have the same parity → +val
Otherwise → -val

subtree(x)  →  [tin[x], tout[x]]

==========================
*/

int n, m;
vvi adj;
vi depth;
vi tin, tout;
int timer = 0;

class Fenwick {
public:
  int n;
  vector<ll> bit;

  Fenwick(int n) {
    this->n = n;
    bit.assign(n + 1, 0);
  }

  void update(int idx, ll val) {

    while (idx <= n) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }

  ll query(int idx) {

    ll sum = 0;

    while (idx > 0) {
      sum += bit[idx];
      idx -= idx & -idx;
    }

    return sum;
  }

  ll rangeQuery(int left, int right) {
    if (left > right)
      return 0;

    return query(right) - (left ? query(left - 1) : 0);
  }

  void rangeUpdate(int l, int r, ll val) {
    update(l, val);
    update(r + 1, -val);
  }
};

void dfs(int u, int p) {
  tin[u] = ++timer;
  for (int v : adj[u]) {
    if (v == p)
      continue;
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
  tout[u] = timer;
}

void solve() {
  cin >> n >> m;

  adj.assign(n + 1, {});
  depth.assign(n + 1, 0);
  tin.assign(n + 1, 0);
  tout.assign(n + 1, 0);

  vi a(n + 1);

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  depth[1] = 0;
  dfs(1, 0);

  Fenwick evenft(n);
  Fenwick oddft(n);

  while (m--) {
    int type;
    cin >> type;

    if (type == 1) {
      int x, val;
      cin >> x >> val;

      // Nodes with same depth parity as depth[x] get +val
      // Diff parity of depth -val

      if (depth[x] % 2 == 0) {
        evenft.rangeUpdate(tin[x], tout[x], +val);
        oddft.rangeUpdate(tin[x], tout[x], -val);
      } else {
        oddft.rangeUpdate(tin[x], tout[x], +val);
        evenft.rangeUpdate(tin[x], tout[x], -val);
      }
    } else {
      int x;
      cin >> x;

      if (depth[x] % 2 == 0)
        cout << a[x] + evenft.query(tin[x]) << endl;
      else
        cout << a[x] + oddft.query(tin[x]) << endl;
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