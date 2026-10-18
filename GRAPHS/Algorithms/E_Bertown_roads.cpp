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

Robbins' theorem:

An undirected graph has an orientation that makes it strongly connected if and
only if it is connected and has no bridges.


==========================
*/

const int N = 1e5 + 5;

int n, m;
vpii adj[N];
vpii ans;

int tin[N], low[N], timer = 0;
bool hasBridge = false;

void dfs(int u, int pId = -1) {
  tin[u] = low[u] = ++timer;

  for (auto [v, Id] : adj[u]) {
    if (Id == pId)
      continue;

    if (!tin[v]) {
      ans.pb({u, v});

      dfs(v, Id);

      low[u] = min(low[u], low[v]);

      if (low[v] > tin[u])
        hasBridge = true;
    }

    // v is already visited
    // u -> v is backedge
    // u = descendant
    // v = ancestor
    else {
      low[u] = min(low[u], tin[v]);

      // Ex : 1____ v
      //      |   |
      //      2   |
      //      |   |
      //      3 __| u

      if (tin[u] > tin[v])
        ans.pb({u, v});
    }
  }
}

void solve() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb({v, i});
    adj[v].pb({u, i});
  }

  dfs(1);

  if (hasBridge) {
    cout << 0 << endl;
    return;
  }

  for (auto [u, v] : ans) 
    cout << u << " " << v << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}