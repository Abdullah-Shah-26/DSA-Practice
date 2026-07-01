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
const int LOG = 20;

vi adj[N];
int up[N][LOG];
int depth[N];

void dfs(int u, int p, int d) {
  depth[u] = d;
  up[u][0] = p;

  rep(i, 1, LOG) { up[u][i] = up[up[u][i - 1]][i - 1]; }

  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u, d + 1);
    }
  }
}

int kthAncestor(int u, int k) {
  for (int j = LOG - 1; j >= 0; j--) {
    if (k & (1 << j)) {
      u = up[u][j];
    }
  }
  return u;
}

// Is u ancestor of v
bool isAncestor(int u, int v) {
  if (depth[u] > depth[v]) return false;
  return kthAncestor(v, depth[v] - depth[u]) == u;
}

int LCA(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);

  u = kthAncestor(u, depth[u] - depth[v]);

  if (u == v) return u;

  for (int j = LOG - 1; j >= 0; j--) {
    if (up[u][j] != up[v][j]) {
      u = up[u][j];
      v = up[v][j];
    }
  }

  return up[u][0];
}

/*

If vertex V is at dist 1 from a vertex X on path from (root->u)
It means its an immediate parent

Tree
1 unique parent
Multiple children

Node X can be V's parent or child

If X is child of V
V is immediate parent of X
V is dist 1 away from child on path
V is directly on path

*/

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(1, 1, 0);

  while (m--) {
    int k;
    cin >> k;

    vi nodes(k, 0);
    rep(i, 0, k) { cin >> nodes[i]; }

    int deepest = nodes[0];
    for (int v : nodes) {
      if (depth[v] > depth[deepest]) {
        deepest = v;
      }
    }

    bool can = true;
    for (int v : nodes) {
      int L = LCA(v, deepest);

      // 1 : v is ancestor of deepest
      // OR
      // 2 : v is 1 dist away from LCA

      if (L == v || (depth[v] - depth[L]) == 1)
        continue;
      else {
        can = false;
        break;
      }
    }

    if (can)
      YES;
    else
      NO;
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