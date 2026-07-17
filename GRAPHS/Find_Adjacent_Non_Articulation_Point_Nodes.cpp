#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, timer;
vector<int> tin, low;
vector<bool> vis, isAP; // Is articulation point (Type A node)
vector<vector<int>> adj;

void dfs(int node, int parent) {
  vis[node] = 1;
  low[node] = tin[node] = timer++;

  int child = 0;
  for (int nei : adj[node]) {
    if (nei == parent)
      continue;

    if (!vis[nei]) {
      dfs(nei, node);

      low[node] = min(low[node], low[nei]);

      if (low[nei] >= tin[node] && parent != -1) {
        isAP[node] = 1;
      }

      child++;
    } else {
      low[node] = min(low[node], tin[nei]);
    }
  }

  if (parent == -1 && child > 1)
    isAP[node] = 1;
}

int main() {
  cin >> n;

  adj.assign(n, {});
  tin.assign(n, -1);
  low.assign(n, 0);
  vis.assign(n, false);
  isAP.assign(n, false);
  timer = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;

      if (x == 1)
        adj[i].push_back(j);
    }
  }

  for (int i = 0; i < n; i++)
    if (!vis[i])
      dfs(i, -1);

  // Nei of articulation point which are not ap's are knows as (Type B nodes)
  vector<bool> typeB(n, false);

  for (int u = 0; u < n; u++) {
    if (isAP[u]) {
      for (int v : adj[u]) {
        if (!isAP[v])
          typeB[v] = true;
      }
    }
  }

  bool found = false;

  for (int i = 0; i < n; i++) {
    if (typeB[i]) {
      found = true;
      cout << i << " ";
    }
  }

  if (!found) {
    cout << -1 << endl;
  }

  return 0;
}