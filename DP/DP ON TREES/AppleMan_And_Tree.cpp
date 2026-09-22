#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

int n;
vector<vector<int>> adj;
vector<int> color;

// dp[v][0] = ways where the component containing v
//            currently has 0 black vertices
//
// dp[v][1] = ways where the component containing v
//            currently has 1 black vertex

ll dp[100005][2];

void dfs(int v, int parent) {
  // Initially, only v exists.
  //
  // If v is white:
  //     component has 0 black
  //
  // If v is black:
  //     component has 1 black

  if (color[v] == 0) {
    dp[v][0] = 1;
    dp[v][1] = 0;
  } else {
    dp[v][0] = 0;
    dp[v][1] = 1;
  }

  for (int u : adj[v]) {
    if (u == parent)
      continue;

    dfs(u, v);

    ll old0 = dp[v][0];
    ll old1 = dp[v][1];

    ll child0 = dp[u][0];
    ll child1 = dp[u][1];

    ll new0 = 0;
    ll new1 = 0;

    // ------------------------------------------------
    // We want v's component to have 0 black.
    // ------------------------------------------------

    // v = 0, u = 0, KEEP edge
    //
    // 0 + 0 = 0
    new0 += old0 * child0;

    // v = 0, u = 1, CUT edge
    //
    // u becomes a finished component containing 1 black.
    // v remains at 0.
    new0 += old0 * child1;

    // ------------------------------------------------
    // We want v's component to have 1 black.
    // ------------------------------------------------

    // v = 0, u = 1, KEEP edge
    //
    // 0 + 1 = 1
    new1 += old0 * child1;

    // v = 1, u = 0, KEEP edge
    //
    // 1 + 0 = 1
    new1 += old1 * child0;

    // v = 1, u = 1, CUT edge
    //
    // v remains a component with 1 black.
    // u becomes another component with 1 black.
    new1 += old1 * child1;

    dp[v][0] = new0 % MOD;
    dp[v][1] = new1 % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  adj.resize(n);
  vector<int> parent(n);

  for (int v = 1; v < n; v++) {
    cin >> parent[v];

    adj[v].push_back(parent[v]);
    adj[parent[v]].push_back(v);
  }

  color.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> color[i];
  }

  dfs(0, -1);

  // Root has no parent.
  // Therefore its component must finally contain
  // exactly one black vertex.
  cout << dp[0][1] << '\n';
}