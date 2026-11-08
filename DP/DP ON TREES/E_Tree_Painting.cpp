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

const int N = 200005;

int n;

vi adj[N];
ll dp[N];
ll sub[N];
ll ans = 0;

void dfs1(int u, int p = -1) {
  sub[u] = 1;
  dp[u] = 0;

  for (int v : adj[u]) {
    if (v == p)
      continue;

    dfs1(v, u);

    sub[u] += sub[v];
    dp[u] += dp[v] + sub[v];
  }
}

void dfs2(int u, int p = -1) {

  // Assuming u is the root node
  // Contribution we get before painting it black = n
  // After painting it = dp[u]
  // dp[u] = sum of subtree sizes of all descendants of u excluding u 

  // Trying every vertex u as 1st vertex to be painted black to achieve max possible
  // score
  ans = max(ans, n + dp[u]);

  for (int v : adj[u]) {
    if (v == p)
      continue;

    // Rerooting

    // Remove v's subtree from u
    dp[u] -= (dp[v] + sub[v]);
    sub[u] -= sub[v];

    // Attach u below v
    sub[v] += sub[u];
    dp[v] += (dp[u] + sub[u]);

    dfs2(v, u);

    // Rollback changes after rec returns
    dp[v] -= (dp[u] + sub[u]);
    sub[v] -= sub[u];

    dp[u] += (dp[v] + sub[v]);
    sub[u] += sub[v];
  }
}

void solve() {
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs1(0);
  dfs2(0);

  cout << ans << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}