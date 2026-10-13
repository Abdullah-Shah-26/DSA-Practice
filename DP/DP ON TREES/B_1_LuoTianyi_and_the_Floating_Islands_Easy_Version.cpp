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



==========================
*/

ll n, k;
vvll adj;
vll parent, sub;
ll totalDist = 0;  // Sum of distances from root to all nodes
vll dist;

ll power(ll a, ll b) {
  ll ans = 1;

  while (b > 0) {
    if (b & 1) ans = (ans * a) % MOD;

    a = (a * a) % MOD;
    b >>= 1;
  }

  return ans;
}

ll modInv(ll p, ll q) {
  // p * inv(q)
  return p % MOD * power(q % MOD, MOD - 2) % MOD;
}

void dfs(int u, int p, ll d = 0) {
  sub[u] = 1;
  parent[u] = p;
  totalDist += d;

  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u, d + 1);
      sub[u] += sub[v];
    }
  }
}

// Rerooting
void computeDist(int u, int p) {
  for (int v : adj[u]) {
    if (v != p) {
      dist[v] = dist[u] - sub[v] + (n - sub[v]);
      computeDist(v, u);
    }
  }
}

void solve() {
  cin >> n >> k;

  adj.assign(n + 1, {});
  parent.assign(n + 1, 0);
  sub.assign(n + 1, 0);
  dist.assign(n + 1, 0);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  if (k & 1) {
    cout << 1 << endl;
    return;
  }

  dfs(1, 0);
  dist[1] = totalDist;
  computeDist(1, 0);

  // For k = 2, no of good islands = dist(a,b) + 1

  // Expected dist b/w 2 randomly chosen distinct nodes :

  ll sumAll = accumulate(begin(dist) + 1, end(dist), 0LL);

  /*
  Divison doest work well with mod

  // Every pair (u, v) is counted twice, once for u & once for v
  // Dividing /2 to get sum over un-ordered pairs
  ll sumPairDistances = sumAll / 2;

  // Un-ordered pairs of distinct nodes
  ll totalPairs = n * (n - 1) / 2;

  */

  ll expectedDist = modInv(sumAll, n * (n - 1));

  // For 2 nodes, good islands are nodes on path in b/w them
  // A path with dist = d has (d + 1) nodes

  ll expectedGoodIslands = (expectedDist + 1) % MOD;

  cout << expectedGoodIslands << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}