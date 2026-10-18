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

const int N = 1000005;

ll n, m;
ll timer;
ll tin[N], low[N];
ll sub[N];
vvi adj(N);
ll ans;

void dfs(int u, int p) {
  tin[u] = low[u] = ++timer;
  sub[u] = 1;

  for (int v : adj[u]) {
    if (v == p)
      continue;

    if (tin[v]) {
      low[u] = min(low[u], tin[v]);
    } else {
      dfs(v, u);
      sub[u] += sub[v];
      low[u] = min(low[u], low[v]);

      if (low[v] > tin[u]) {
        ll s = sub[v];
        ll pairs = s * (s - 1) / 2 + (n - s) * (n - s - 1) / 2;

        ans = min(ans, pairs);
      }
    }
  }
}

void solve() {
  cin >> n >> m;

  ans = n * (n - 1) / 2;
  timer = 0;
  adj.assign(n + 1, {});

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  fill(tin, tin + n + 1, 0LL);
  dfs(1, 0);

  cout << ans << endl;
}

int main() {

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}