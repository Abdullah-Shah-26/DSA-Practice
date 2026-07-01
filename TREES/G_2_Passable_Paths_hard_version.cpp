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

const int N = 200005;
const int LOG = 19;

vi adj[N];
int up[N][LOG];
int depth[N];
int tin[N], tout[N];
int timer = 0;

void dfs(int u, int p, int d) {
  tin[u] = ++timer;
  depth[u] = d;
  up[u][0] = p;

  for (int i = 1; i < LOG; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }

  for (int v : adj[u]) {
    if (v != p) dfs(v, u, d + 1);
  }

  tout[u] = ++timer;
}

// Is u ancestor of v
bool isAncestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

int LCA(int u, int v) {
  if (isAncestor(u, v)) return u;
  if (isAncestor(v, u)) return v;

  for (int i = LOG - 1; i >= 0; i--) {
    if (!isAncestor(up[u][i], v)) {
      u = up[u][i];
    }
  }
  return up[u][0];
}

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(1, 1, 0);

  int q;
  cin >> q;

  while (q--) {
    int k;
    cin >> k;

    vi nodes(k);
    rv(nodes);

    sort(all(nodes), [](int a, int b) { return depth[a] > depth[b]; });

    int end1 = nodes[0];
    int end2 = -1;

    rep(i, 1, k) {
      if (!isAncestor(nodes[i], end1)) {
        end2 = nodes[i];
        break;
      }
    }

    if (end2 == -1) end2 = nodes[k - 1];

    int peak = LCA(end1, end2);
    bool valid = true;

    for (int x : nodes) {
      bool slope1 = isAncestor(x, end1) && isAncestor(peak, x);
      bool slope2 = isAncestor(x, end2) && isAncestor(peak, x);

      if (!slope1 && !slope2) {
        valid = false;
        break;
      }
    }

    yno(valid);
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