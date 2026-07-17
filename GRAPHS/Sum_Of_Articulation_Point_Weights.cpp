#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int n, timer;
vector<int> cost;
vector<int> tin;
vector<int> low;
vector<bool> mark; // Is articulation point
vector<bool> vis;
vector<vector<int>> adj;

void dfs(int node, int parent) {

  vis[node] = 1;
  tin[node] = low[node] = timer++;

  int child = 0;

  for (int nei : adj[node]) {
    if (nei == parent)
      continue;

    if (!vis[nei]) {
      dfs(nei, node);

      low[node] = min(low[node], low[nei]);

      if (low[nei] >= tin[node] && parent != -1)
        mark[node] = 1;

      child++;
    } else
      low[node] = min(low[node], tin[nei]);
  }

  if (child > 1 && parent == -1)
    mark[node] = 1;
}

int main() {
  cin >> n;
  cost.assign(n, 0);
  vis.assign(n, 0);
  tin.assign(n, -1);
  low.assign(n, 0);
  mark.assign(n, 0);
  adj.assign(n, {});
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
    cin >> cost[i];

  for (int i = 0; i < n; i++)
    if (!vis[i])
      dfs(i, -1);

  int sum = 0;

  for (int i = 0; i < n; i++)
    if (mark[i])
      sum += cost[i];

  cout << sum << endl;
}