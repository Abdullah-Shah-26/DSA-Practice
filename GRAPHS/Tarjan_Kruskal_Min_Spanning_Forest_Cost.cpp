#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected weighted graph, first identify and remove all bridge edges
(edges whose removal increases the number of connected components). After
removing all bridges, the graph may become disconnected. Compute the Minimum
Spanning Tree (MST) of each remaining connected component and output the sum of
their weights (i.e., the weight of the Minimum Spanning Forest).
*/

vector<int> tin;
vector<int> low;
vector<bool> vis;
vector<bool> isBridge;
int timer;

void dfs(int node, int parentEdge, vector<vector<pair<int, int>>> &adj) {

  vis[node] = 1;
  low[node] = tin[node] = timer++;

  for (auto [nei, edgeId] : adj[node]) {
    if (edgeId == parentEdge)
      continue;

    if (!vis[nei]) {
      dfs(nei, edgeId, adj);
      low[node] = min(low[node], low[nei]);

      if (low[nei] > tin[node]) {
        isBridge[edgeId] = 1;
      }
    } else {
      // node1 ----- node2 ----- nei
      //   |______________________|

      low[node] = min(low[node], tin[nei]);
    }
  }
}

class DSU {
public:
  vector<int> parent;
  vector<int> sz;

  DSU(int n) {
    parent.assign(n, 0);
    sz.assign(n, 1);
    iota(begin(parent), end(parent), 0);
  }

  int find(int x) { return (x == parent[x]) ? x : parent[x] = find(parent[x]); }

  bool unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
      return false;

    if (sz[u] < sz[v])
      swap(u, v);

    sz[u] += sz[v];
    parent[v] = u;

    return true;
  }
};

void solve(int n, int m) {

  vector<vector<int>> edges;             // u, v, w, edgeId
  vector<vector<pair<int, int>>> adj(n); // v, edgeId

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    edges.push_back({u, v, w, i});

    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
  }

  tin.assign(n, -1);
  low.assign(n, 0);
  vis.assign(n, false);
  isBridge.assign(m, false);
  timer = 0;

  for (int i = 0; i < n; i++)
    if (!vis[i])
      dfs(i, -1, adj);

  auto cmp = [&](auto &a, auto &b) { return a[2] < b[2]; };

  sort(begin(edges), end(edges), cmp);

  DSU dsu(n);

  int cost = 0;

  for (auto &e : edges) {
    int u = e[0], v = e[1];
    int w = e[2], edgeId = e[3];

    if (isBridge[edgeId])
      continue;

    if (dsu.unite(u, v))
      cost += w;
  }

  cout << cost << endl;
}

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0)
      break;

    solve(n, m);
  }
}