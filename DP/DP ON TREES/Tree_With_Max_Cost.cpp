#include <bits/stdc++.h>
using namespace std;

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

#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define pv(a)                 \
  do {                        \
    for (const auto &x : (a)) \
      cout << x << ' ';       \
    cout << '\n';             \
  } while (0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

const int N = 2e5 + 5;
vi values(N);
vi adj[N];
vll subSum(N), dist(N);
ll maxCost = 0;

// // Precomputation of subtree sum and dist of each node from root
// void dfs(int u, int p) {
//   subSum[u] = values[u];
//   dist[u] = 0;

//   for (auto& v : adj[u]) {
//     if (v != p) {
//       dfs(v, u);
//       subSum[u] += subSum[v];
//       dist[u] += (subSum[v] + dist[v]);
//     }
//   }
// }

// void reroot(int u, int p) {
//   maxCost = max(maxCost, dist[u]);

//   for (int v : adj[u]) {
//     if (v == p) continue;

//     // Do
//     // We remove v's entire side from its parent (u)
//     // And remove its contribution from u
//     subSum[u] -= subSum[v];
//     dist[u] -= (dist[v] + subSum[v]);

//     // Earlier u was parent of v
//     // Now u becomes child of v

//     // Now v gets the remaining u's side
//     subSum[v] += subSum[u];
//     dist[v] += (dist[u] + subSum[u]);

//     // Explore
//     reroot(v, u);

//     // Undo
//     subSum[v] -= subSum[u];
//     dist[v] -= (dist[u] + subSum[u]);

//     subSum[u] += subSum[v];
//     dist[u] += (dist[v] + subSum[v]);
//   }
// }

// void solve() {
//   int n;
//   cin >> n;

//   for (int i = 1; i <= n; i++) cin >> values[i];

//   for (int i = 0; i < n - 1; i++) {
//     int u, v;
//     cin >> u >> v;

//     adj[u].pb(v);
//     adj[v].pb(u);
//   }

//   dfs(1, -1);

//   maxCost = 0;
//   reroot(1, -1);

//   cout << maxCost << endl;

//   // Clear globals before returning to main
//   for (int i = 1; i <= n; i++) {
//     adj[i].clear();
//     values[i] = 0;
//     subSum[i] = 0;
//     dist[i] = 0;
//   }

//   return;
// }

void solve() {
  int n;
  cin >> n;

  ll total = 0;

  for (int i = 1; i <= n; i++) {
    cin >> values[i];
    total += values[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  // Building Traversal order & parent
  vi parent(n + 1, 0);
  vi depth(n + 1, 0);
  vi order;
  order.reserve(n);

  parent[1] = -1;
  order.pb(1);

  for (int i = 0; i < (int)order.size(); i++) {
    int u = order[i];

    for (int v : adj[u]) {
      if (v == parent[u])
        continue;

      parent[v] = u;
      depth[v] = depth[u] + 1;
      order.pb(v);
    }
  }

  // Subtree sums
  for (int i = 1; i <= n; i++)
    subSum[i] = values[i];

  for (int i = n - 1; i > 0; i--) {
    int u = order[i];
    subSum[parent[u]] += subSum[u];
  }

  // Cost when root = 1
  dist[1] = 0;

  for (int i = 1; i <= n; i++) {
    dist[1] += 1LL * depth[i] * values[i];
  }

  // Reroot
  for (int u : order) {
    for (int v : adj[u]) {
      if (parent[v] != u)
        continue;

      dist[v] = dist[u] + total - 2 * subSum[v];
    }
  }

  ll ans = 0;

  for (int i = 1; i <= n; i++)
    ans = max(ans, dist[i]);

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
