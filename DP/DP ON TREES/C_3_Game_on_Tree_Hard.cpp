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

void solve() {
  int n, q;
  cin >> n >> q;

  vvi adj(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    u--;
    v--;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  vi parent(n, -1), cnt(n, 0);
  vb win(n, false), ans(n);

  // DP for root 0
  function<void(int, int)> dfs1 = [&](int u, int p) {
    parent[u] = p;

    for (int v : adj[u]) {
      if (v == p) continue;

      dfs1(v, u);

      if (!win[v]) cnt[u]++;
    }

    // If any of the child loses, I win
    win[u] = (cnt[u] > 0);
  };

  // Rerooting
  function<void(int, int)> dfs2 = [&](int u, int p) {
    ans[u] = win[u];

    for (int v : adj[u]) {
      if(v == p)
        continue;

      int oldCntU = cnt[u];
      int oldCntV = cnt[v];
      bool oldWinU = win[u];
      bool oldWinV = win[v];

      // Remove v from children of u
      cnt[u] -= (!win[v]);
      win[u] = (cnt[u] > 0);

      // Add u as child of v
      cnt[v] += (!win[u]);
      win[v] = (cnt[v] > 0);

      dfs2(v, u);

      // Rollback changes
      cnt[u] = oldCntU;
      cnt[v] = oldCntV;
      win[u] = oldWinU;
      win[v] = oldWinV;
    }
  };

  dfs1(0, -1);
  dfs2(0, -1);

  while (q--) {
    int u;
    cin >> u;

    u--;

    if (ans[u])
      cout << "Ron" << endl;
    else
      cout << "Hermione" << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}