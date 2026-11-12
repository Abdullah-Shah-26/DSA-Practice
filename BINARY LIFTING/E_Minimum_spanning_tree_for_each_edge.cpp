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

const int LOG = 20;

struct DSU {
  vi p, sz;

  DSU(int n) {
    p.resize(n + 1);
    sz.resize(n + 1, 1);
    iota(all(p), 0);
  }

  int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
  }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;

    if (sz[u] < sz[v]) swap(u, v);

    sz[u] += sz[v];
    p[v] = u;

    return true;
  }
};

struct Edge {
  int u, v, w, id;
};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<Edge> edges(m);

  for (int i = 0; i < m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
    edges[i].id = i;
  }

  sort(all(edges), [&](const Edge& a, const Edge& b) { return a.w < b.w; });

  vvpii adj(n + 1);
  vb inMST(m, false);

  DSU dsu(n);

  ll mst = 0;  // mincost

  for (auto [u, v, w, id] : edges) {
    if (!dsu.unite(u, v)) continue;

    mst += w;
    inMST[id] = true;

    adj[u].pb({v, w});
    adj[v].pb({u, w});
  }

  vvi up(n + 1, vi(LOG));
  vvi mx(n + 1, vi(LOG));
  vi depth(n + 1, 0);

  function<void(int, int, int)> dfs = [&](int u, int p, int w) {
    up[u][0] = p;
    mx[u][0] = w;

    for (auto [v, wt] : adj[u]) {
      if (v == p) continue;

      depth[v] = depth[u] + 1;
      dfs(v, u, wt);
    }
  };

  dfs(1, 1, 0);
  
  // up[u][j] = 2^j th ancestor of u
  // mx[u][j] = max edge wt b/w u and 2^j th ancestor of u

  for (int j = 1; j < LOG; j++) {
    for (int u = 1; u <= n; u++) {
      up[u][j] = up[up[u][j - 1]][j - 1];
      mx[u][j] = max(mx[u][j - 1], mx[up[u][j - 1]][j - 1]);
    }
  }

  // Max edge wt : u->v
  auto maxEdge = [&](int u, int v) {
    int ans = 0;

    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];

    for (int j = LOG - 1; j >= 0; j--) {
      if (diff & (1 << j)) {

        // While jumping we maintain max edge wt encountered
        ans = max(ans, mx[u][j]);
        u = up[u][j];
      }
    }

    // u, v already met at LCA 
    if (u == v) return ans;

    for (int j = LOG - 1; j >= 0; j--) {
      if (up[u][j] != up[v][j]) {
        ans = max(ans, mx[u][j]);
        ans = max(ans, mx[v][j]);

        u = up[u][j];
        v = up[v][j];
      }
    }

    ans = max(ans, mx[u][0]);
    ans = max(ans, mx[v][0]);

    return ans;
  };

  vll ans(m);

  for (auto [u, v, w, id] : edges) {
    if (inMST[id]) {
      ans[id] = mst;
    } else {

      // Edge not in mst
      // Add this forced edge b/w (u, v) 
      // It forms a cycle
      // Remove the max wt edge from path b/w (u, v) to remove cycle & get min cost spanning tree
      ans[id] = mst + w - maxEdge(u, v);
    }
  }

  for (auto x : ans) cout << x << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}