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

#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
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

class DSU {
public:
  vector<int> parent, sz;

  DSU(int n) {
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int u) {
    if (parent[u] == u)
      return u;
    return parent[u] = find(parent[u]);
  }

  void unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
      return;

    if (sz[u] < sz[v])
      swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
  }
};

const int N = 3e5 + 5;

int n, m;
vvpii adj; // [u,v,id]
vpii edges;
vb isBridge;
int tin[N], low[N];
int timer = 0;

vvi tree; // bridge tree

void dfs(int u, int pId) {
  tin[u] = low[u] = ++timer;

  for (auto [v, id] : adj[u]) {
    if (id == pId)
      continue;

    if (tin[v]) {
      low[u] = min(low[u], tin[v]);

    } else {
      dfs(v, id);

      low[u] = min(low[u], low[v]);

      if (low[v] > tin[u]) {
        isBridge[id] = true;
      }
    }
  }
}

pii bfs(int src) {
  vi dist(n + 1, -1);
  queue<int> q;

  q.push(src);
  dist[src] = 0;

  int farthest = src;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (dist[u] > dist[farthest]) {
      farthest = u;
    }

    for (int v : tree[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  return {farthest, dist[farthest]};
}

void solve() {

  cin >> n >> m;

  adj.resize(n + 1);
  isBridge.assign(m, false);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    edges.pb({u, v});

    adj[u].pb({v, i});
    adj[v].pb({u, i});
  }

  for (int i = 1; i <= n; i++) {
    if (!tin[i]) {
      dfs(i, -1);
    }
  }

  DSU dsu(n);

  // Bridge tree :
  // Merging all vertices that are connected without crossing any bridge into a
  // single component (2-edge-connected component) Connecting these comp using
  // original bridges

  for (int id = 0; id < m; id++) {
    if (!isBridge[id]) {
      auto [u, v] = edges[id];
      dsu.unite(u, v);
    }
  }

  tree.resize(n + 1);

  for (int id = 0; id < m; id++) {
    if (isBridge[id]) {
      auto [u, v] = edges[id];

      // Each component is represented as node 
      // u = diff comp
      // v = diff comp
      // u-v = bridge edge wrt given graph
      // In bridge tree, u - v normal edge
      // Then we find max bridge edges on simple path 
      // That is diameter of this bridge tree
      u = dsu.find(u);
      v = dsu.find(v);

      tree[u].pb(v);
      tree[v].pb(u);
    }
  }

  // Finding diameter of bridge tree
  auto [A, d1] = bfs(dsu.find(1));
  auto [B, diam] = bfs(A);

  cout << diam << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}