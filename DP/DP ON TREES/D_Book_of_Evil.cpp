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

int n, m, d;
vvi adj;
vi marked, down, up;

// Postorder dfs
// down[u] = max dist of u from marked node in its subtree
void dfs1(int u, int p) {
  if (marked[u]) down[u] = 0;

  for (int v : adj[u]) {
    if (v == p) continue;

    dfs1(v, u);

    down[u] = max(1 + down[v], down[u]);
  }
}

// Preorder dfs
// up[v] = max dist of a v from marked node outside its subtree
void dfs2(int u, int p) {
  int mx1 = -INF, mx2 = -INF;
  int bestChild = -1;

  for (int v : adj[u]) {
    if (v == p) continue;

    int x = down[v];

    if (x > mx1) {
      bestChild = v;
      mx2 = mx1;
      mx1 = x;
    } else if (x > mx2) {
      mx2 = x;
    }
  }

  for (int v : adj[u]) {
    if (v == p) continue;

    int bestSibling = (v == bestChild ? mx2 : mx1);

    // Marked node is outside u's subtree
    // Can go from v to u & follow up[u]
    up[v] = up[u] + 1;

    // Parent u itself is marked
    // Dist from v to u = 1
    if (marked[u]) up[v] = max(up[v], 1);

    // Marked node is inside another child's subtree
    // Can go from v --> u --> sibling
    if (bestSibling != -INF) up[v] = max(up[v], bestSibling + 2);

    dfs2(v, u);
  }
}

void solve() {
  cin >> n >> m >> d;

  adj.resize(n + 1);
  marked.assign(n + 1, 0);
  down.assign(n + 1, -INF);
  up.assign(n + 1, -INF);

  for (int i = 0; i < m; i++) {
    int u;
    cin >> u;
    marked[u] = 1;
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs1(1, 0);
  dfs2(1, 0);

  int ans = 0;

  // From node u
  // If the farthest node that is marked is in range
  // Then all marked nodes are guarenteed to be <= d
  // Hence u can be a possible center

  for (int u = 1; u <= n; u++)
    if (max(down[u], up[u]) <= d) ans++;

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}