#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define pb push_back
#define endl '\n'
#define all(x) begin(x), end(x)

int timer = 0;
vi seen;

struct DSU {
  vi parent, sz, diameter;

  DSU(int n) {
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    diameter.assign(n + 1, 0);
    iota(all(parent), 0);
  }

  int find(int x) {
    if (x == parent[x])
      return x;

    return parent[x] = find(parent[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y)
      return;

    int d1 = diameter[x];
    int d2 = diameter[y];

    // Since we want to minimize path len b/w x and y we connect the center's of
    // each path. We dont connect by end pts else the diameter would become too
    // large (d1 + d2 + 1)
    int newD = max({d1, d2, (d1 + 1) / 2 + 1 + (d2 + 1) / 2});

    if (sz[x] < sz[y])
      swap(x, y);

    parent[y] = x;
    sz[x] += sz[y];
    diameter[x] = newD;
  }
};

int farthest(int src, vvi &adj, vi &dist) {
  ++timer;

  queue<int> q;

  q.push(src);
  dist[src] = 0;
  seen[src] = timer; // Visited in this bfs

  int best = src;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (dist[u] > dist[best]) {
      best = u;
    }

    for (auto v : adj[u]) {
      if (seen[v] == timer)
        continue;

      seen[v] = timer;
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }

  // Farthest city from src
  return best;
}

void solve() {
  int n, m, q;
  cin >> n >> m >> q;

  seen.assign(n + 1, 0);
  vvi adj(n + 1);

  DSU dsu(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    dsu.unite(u, v);

    adj[u].pb(v);
    adj[v].pb(u);
  }

  vi dist(n + 1);

  for (int i = 1; i <= n; i++) {
    // We only process ultimate parents
    if (dsu.find(i) != i)
      continue;

    // Optimization: Skip BFS entirely if it's a single isolated node.
    if (dsu.sz[i] == 1) {
      dsu.diameter[i] = 0;
      continue;
    }

    int a = farthest(i, adj, dist);
    int b = farthest(a, adj, dist);

    // Here i is ultimate parent of the component and it stores diameter length
    dsu.diameter[i] = dist[b];
  }

  while (q--) {
    int type;
    int x, y;

    cin >> type;

    if (type == 1) {
      cin >> x;
      cout << dsu.diameter[dsu.find(x)] << endl;
    } else {
      cin >> x >> y;
      dsu.unite(x, y);
    }
  }
}

int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}