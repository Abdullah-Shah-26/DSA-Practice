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

class DSU {
public:
  vector<int> parent, sz;

  DSU(int n) {
    parent.resize(n);
    sz.assign(n, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int u) {
    if (parent[u] == u)
      return u;

    return parent[u] = find(parent[u]);
  }

  ll unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
      return 0;

    if (sz[u] < sz[v])
      swap(u, v);

    ll added = 1LL * sz[u] * sz[v];

    parent[v] = u;
    sz[u] += sz[v];

    return added;
  }
};

struct Edge {
  int u, v, w;
};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<Edge> edges(n - 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    u--;
    v--;

    edges[i] = {u, v, w};
  }

  sort(all(edges), [](auto &a, auto &b) { return a.w < b.w; });

  vector<pair<int, int>> queries(m);

  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    queries[i] = {k, i};
  }

  sort(all(queries));

  DSU dsu(n);

  ll res = 0;
  int pos = 0;

  vll ans(m);

  for (auto [k, idx] : queries) {

    while (pos < n - 1 && edges[pos].w <= k) {
      auto &e = edges[pos];

      res += dsu.unite(e.u, e.v);

      pos++;
    }

    ans[idx] = res;
  }

  for (auto x : ans)
    cout << x << " ";

  cout << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}