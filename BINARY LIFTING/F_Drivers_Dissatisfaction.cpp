#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
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

const ll INF = 1e18;
const ll LINF = 4e18;
const ll MOD = 1e9 + 7;

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
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

struct DSU {
  vi p, sz;

  DSU(ll n) {
    p.resize(n, 0);
    sz.resize(n, 1);
    iota(all(p), 0);
  }

  ll find(ll u) {
    if (u == p[u]) return u;
    return p[u] = find(p[u]);
  }

  bool unite(ll u, ll v) {
    u = find(u);
    v = find(v);

    if (u == v) return false;

    if (sz[u] < sz[v]) swap(u, v);

    p[v] = u;
    sz[u] += sz[v];

    return true;
  }
};

struct Edge {
  ll u, v, id;
  ll wt, c;
};

vector<Edge> edges;
vvpii adj;

const ll LOG = 20;

void solve() {
  ll n, m, s;
  cin >> n >> m;

  vll w(m, 0);
  vll c(m, 0);

  rv(w);
  rv(c);

  edges.resize(m);
  adj.assign(n, {});

  for (ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;

    u--;
    v--;

    edges[i] = {u, v, i, w[i], c[i]};
  }

  cin >> s;

  // MST construction using Kruskal

  sort(all(edges), [](const Edge& a, const Edge& b) { return a.wt < b.wt; });

  DSU dsu(n);

  vb inMST(m, false);
  ll mstWt = 0;

  for (auto& e : edges) {
    if (!dsu.unite(e.u, e.v)) continue;

    inMST[e.id] = true;
    mstWt += e.wt;

    adj[e.u].pb({e.v, e.id});
    adj[e.v].pb({e.u, e.id});
  }

  // 2 edges in MST with smallest repair cost 

  pll min1 = {LINF, -1};
  pll min2 = {LINF, -1};

  for (auto& e : edges) {
    if (!inMST[e.id]) continue;

    pll cur = {e.c, e.id};

    if (cur.first < min1.first) {
      min2 = min1;
      min1 = cur;
    } else if (cur.first < min2.first) {
      min2 = cur;
    }
  }

  // Binary lifting

  vvi up(n, vi(LOG, 0));
  vvll mx(n, vll(LOG, -1));
  vvi mxId(n, vi(LOG, -1));

  vi depth(n, 0);
  vi par(n, -1);

  vi st = {0};
  par[0] = 0;

  while (!st.empty()) {
    ll u = st.back();
    st.pop_back();

    up[u][0] = par[u];

    for (auto [v, id] : adj[u]) {
      if (v == par[u]) continue;

      par[v] = u;
      depth[v] = depth[u] + 1;

      mx[v][0] = w[id];
      mxId[v][0] = id;

      st.pb(v);
    }
  }

  // up[u][j] = 2^j th ancestor of u
  // mx[u][j] = max edge wt between u and 2^j th ancestor
  // mxId[u][j] = ID of that maximum edge

  for (ll j = 1; j < LOG; j++) {
    for (ll u = 0; u < n; u++) {
      up[u][j] = up[up[u][j - 1]][j - 1];

      if (mx[u][j - 1] >= mx[up[u][j - 1]][j - 1]) {
        mx[u][j] = mx[u][j - 1];
        mxId[u][j] = mxId[u][j - 1];
      } else {
        mx[u][j] = mx[up[u][j - 1]][j - 1];
        mxId[u][j] = mxId[up[u][j - 1]][j - 1];
      }
    }
  }

  // Max edge on path u -> v
  auto maxEdge = [&](ll u, ll v) -> pll {
    ll ans = -1;
    ll id = -1;

    auto update = [&](ll u, ll j) {
      if (mx[u][j] > ans) {
        ans = mx[u][j];
        id = mxId[u][j];
      }
    };

    if (depth[u] < depth[v]) swap(u, v);

    ll diff = depth[u] - depth[v];

    for (ll j = LOG - 1; j >= 0; j--) {
      if (diff & (1LL << j)) {
        update(u, j);
        u = up[u][j];
      }
    }

    if (u == v) return {id, ans};

    for (ll j = LOG - 1; j >= 0; j--) {
      if (up[u][j] != up[v][j]) {
        update(u, j);
        update(v, j);

        u = up[u][j];
        v = up[v][j];
      }
    }

    update(u, 0);
    update(v, 0);

    return {id, ans};
  };

  // Original MST answer
  ll ans = mstWt - s / min1.first;

  ll bestAdd = -1;
  ll bestRemove = -1;
  ll bestCheap = min1.second;

  // Try every non-MST edge

  for (auto& e : edges) {
    ll u = e.u;
    ll v = e.v;
    ll id = e.id;
    ll wt = e.wt;
    ll cost = e.c;

    if (inMST[id]) continue;

    // Add new edge and remove maximum edge on path
    auto [removeId, maxWt] = maxEdge(u, v);

    ll newWt = mstWt + wt - maxWt;

    // Cheapest repair cost after removing an edge

    ll reminingMinCost = min1.first;

    // If the edge we removed from MST was the one with cheapest repair cost, then remMinCost becomes 2nd cheapest option
    if (removeId == min1.second)
      reminingMinCost = min2.first;

    ll newMinCost = min(reminingMinCost, cost);
    ll candidate = newWt - s / newMinCost;

    if (candidate < ans) {
      ans = candidate;

      bestAdd = id;
      bestRemove = removeId;

      if (cost <= reminingMinCost) {
        bestCheap = id;
      } else if (removeId == min1.second) {
        bestCheap = min2.second;
      } else {
        bestCheap = min1.second;
      }
    }
  }

  // Reconstruct selected edges

  if (bestAdd != -1) {
    inMST[bestRemove] = false;
    inMST[bestAdd] = true;
  }

  // Repair cheapest selected edge

  vll finalW = w;
  finalW[bestCheap] -= s / c[bestCheap];

  cout << ans << endl;

  for (ll i = 0; i < m; i++) {
    if (inMST[i]) {
      cout << i + 1 << " " << finalW[i] << endl;
    }
  }
}

int main() {
  ll t = 1;

  while (t--) {
    solve();
  }

  return 0;
}
