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
  ll n, m;
  cin >> n >> m;

  vector<T> edges;

  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;

    edges.pb({u, v, w});
  }

  sort(all(edges), [](auto &a, auto &b) { return get<2>(a) < get<2>(b); });

  vll dp(n + 1, 0);

  ll ans = 0;

  for (int i = 0; i < m;) {
    int j = i;

    // Equal wt edges must be processed together 
    // If dp is updated immediately, an edge can accidentally use another edge of same wt which is invalid
    while (j < m && get<2>(edges[j]) == get<2>(edges[i]))
      j++;

    // [destination node, path len]
    vpll updates;

    // Computing dp values without updating dp
    for (int k = i; k < j; k++) {
      auto [u, v, w] = edges[k];
      updates.pb({v, dp[u] + 1});
    }

    for (auto [v, val] : updates) {
      dp[v] = max(dp[v], val);
      ans = max(ans, dp[v]);
    }

    i = j;
  }

  cout << ans << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}