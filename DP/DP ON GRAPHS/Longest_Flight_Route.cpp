#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;
const int INF = 1e9;

inline void fastio() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// DP on DAG

int main() {
  fastio();

  int n, m;
  cin >> n >> m;

  vi adj[n + 1];
  vi indeg(n + 1, 0);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    indeg[v]++;
    adj[u].push_back(v);
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (indeg[i] == 0) {
      q.push(i);
    }
  }

  vi topo;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    topo.push_back(u);
    for (int v : adj[u]) {
      indeg[v]--;

      if (indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  // dp[u] = max no of cities on any path from 1 to u
  vi dp(n + 1, -INF);
  vi parent(n + 1, -1);
  dp[1] = 1;

  for (int u : topo) {
    if (dp[u] == -INF)
      continue;

    for (int v : adj[u]) {
      if (dp[u] + 1 > dp[v]) {
        dp[v] = dp[u] + 1;
        parent[v] = u; // For path reconstruction
      }
    }
  }

  if (dp[n] == -INF) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  vi path;

  int cur = n;
  while (cur != -1) {
    path.push_back(cur);
    cur = parent[cur];
  }

  reverse(path.begin(), path.end());

  cout << dp[n] << endl;
  for (int x : path) {
    cout << x << " ";
  }

  return 0;
}