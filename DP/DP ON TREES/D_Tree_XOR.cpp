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
#define pv(a)                                   \
  do {                                          \
    for (const auto& x : (a)) cout << x << ' '; \
    cout << '\n';                               \
  } while (0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================

Rerooting DP

==========================
*/

const int N = 200005;

vi adj[N];
ll a[N];
ll sub[N];
ll dp[N];  // For root = 1, sum over sub[child] * (a[u] ^ a[v])
ll ans[N];
int n;

void dfs1(int u, int p) {
  sub[u] = 1;
  dp[u] = 0;

  for (int v : adj[u]) {
    if (v == p) continue;

    dfs1(v, u);

    sub[u] += sub[v];
    dp[u] += dp[v] + sub[v] * (a[u] ^ a[v]);
  }
}

// Re rooting
// Computing answers for all other nodes using root's answer

void dfs2(int u, int p) {
  for (int v : adj[u]) {
    if (v == p) continue;

    ll w = (a[u] ^ a[v]);
    ans[v] = ans[u] - sub[v] * w + (n - sub[v]) * w;

    dfs2(v, u);
  }
}

void solve() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    adj[i].clear();
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs1(1, 0);
  ans[1] = dp[1];
  dfs2(1, 0);

  for (int i = 1; i <= n; i++) cout << ans[i] << " ";

  cout << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}