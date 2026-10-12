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
#define rm(mat)         \
  for (auto& r : (mat)) \
    for (auto& x : (r)) cin >> x
#define pm(mat)                                   \
  do {                                            \
    for (const auto& r : (mat)) {                 \
      for (const auto& x : (r)) cout << x << ' '; \
      cout << '\n';                               \
    }                                             \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define yno(a) cout << ((a) ? "Yes\n" : "No\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================

Diff Array on Tree 

==========================
*/

const int N = 2e5 + 5;
vi adj[N];
int sub[N];
int parent[N];
ll add[N];

void dfs1(int u, int p) {
  sub[u] = 1;

  for (int v : adj[u]) {
    if (v != p) {
      parent[v] = u;
      dfs1(v, u);
      sub[u] += sub[v];
    }
  }
}

// Propogating contribution downward
void dfs2(int u) {
  for (int v : adj[u]) {
    if (v != parent[u]) {
      add[v] += add[u];
      dfs2(v);
    }
  }
}

void solve() {
  int n;
  cin >> n;

  vpii allEdges(n - 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);

    allEdges[i] = {u, v};
  }

  dfs1(1, 0);

  for (int i = 0; i < (int)allEdges.size(); i++) {
    auto [a, b] = allEdges[i];

    // Keep a as parent of b, if not swap them
    if (a != parent[b]) swap(a, b);

    int below = sub[b];
    int above = n - sub[b];

    // Larger component gets +i (edge idx) to every vertex in that component
    if (below > above) {
      add[b] += (i + 1);
    } else {
      add[1] += (i + 1);
      add[b] -= (i + 1);
    }
  }

  dfs2(1);

  for (int i = 1; i <= n; i++) cout << add[i] << " ";

  cout << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}