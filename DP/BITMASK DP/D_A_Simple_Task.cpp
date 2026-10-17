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

void solve() {
  int n, m;
  cin >> n >> m;

  vi adj(n, 0);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    u--;
    v--;

    adj[u] |= (1 << v);
    adj[v] |= (1 << u);
  }

  ll ans = 0;
  ll total = 1 << n;

  for (int s = 0; s < n; s++) {
    vvll dp(total, vll(n, 0));
    dp[1 << s][s] = 1;

    for (int mask = 0; mask < total; mask++) {
      if (!(mask & (1 << s)))
        continue;
      if (mask & ((1 << s) - 1))
        continue;

      for (int u = 0; u < n; u++) {
        if (!(mask & (1 << u)))
          continue;
        if (dp[mask][u] == 0)
          continue;

        int candidates = adj[u] & ~mask;

        for (int v = s + 1; v < n; v++) {
          if (!(candidates & (1 << v)))
            continue;

          dp[mask | (1 << v)][v] += dp[mask][u];
        }

        int len = __builtin_popcount((unsigned)mask);

        if (len >= 3 && (adj[u] & (1 << s)))
          ans += dp[mask][u];
      }
    }
  }

  cout << ans / 2 << endl;
  return;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}