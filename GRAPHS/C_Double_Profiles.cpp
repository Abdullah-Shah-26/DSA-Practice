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

Hashing 

==========================
*/

using ull = unsigned long long;

void solve() {
  int n, m;
  cin >> n >> m;

  vvi adj(n + 1);
  vi deg(n + 1);
  vpii edges;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);

    deg[u]++;
    deg[v]++;

    edges.pb({u, v});
  }

  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

  // h[u] = sum of rand[v] where v is all nei of u
  vector<ull> rand(n + 1, 0), h(n + 1, 0);

  // Every node gets assigned a random distinct value
  for (int i = 1; i <= n; i++) rand[i] = rng();

  for (int u = 1; u <= n; u++) {
    for (int v : adj[u]) {
      h[u] += rand[v];
    }
  }

  map<pair<int, ull>, ll> cnt;
  ll ans = 0;

  // 2 profiles are not friends
  for (int u = 1; u <= n; u++) {
    auto key = make_pair(deg[u], h[u]);
    ans += cnt[key];
    cnt[key]++;
  }

  // 2 profiles are friends
  for (auto [u, v] : edges) {
    if (deg[u] == deg[v] && h[u] - rand[v] == h[v] - rand[u]) {
      ans++;
    }
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