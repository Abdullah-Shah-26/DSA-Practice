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
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

void dfs(int u, int parent, vvi &adj, vll &L, vll &R,
         vector<array<ll, 2>> &dp) {
  dp[u][0] = dp[u][1] = 0;

  for (int v : adj[u]) {
    if (v == parent)
      continue;

    dfs(v, u, adj, L, R, dp);

    ll takeL =
        max(dp[v][0] + llabs(L[u] - L[v]), dp[v][1] + llabs(L[u] - R[v]));
    ll takeR =
        max(dp[v][0] + llabs(R[u] - L[v]), dp[v][1] + llabs(R[u] - R[v]));

    // Add contributions to parent
    dp[u][0] += takeL;
    dp[u][1] += takeR;
  }
}

void solve() {
  int n;
  cin >> n;

  vvi adj(n + 1);
  vll L(n + 1), R(n + 1);
  vector<array<ll, 2>> dp(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> L[i] >> R[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0, adj, L, R, dp);

  cout << max(dp[1][0], dp[1][1]) << endl;
  return;
}

// ---------- Main ----------
int main() {
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}