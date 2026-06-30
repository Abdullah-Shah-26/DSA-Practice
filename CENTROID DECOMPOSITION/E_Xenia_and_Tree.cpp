#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
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
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define endl '\n'

const int N = 200005;
const int LOG = 20;

vi adj[N];

// Centroid decomposition
int sz[N];
bool removed[N];
int centroidParent[N];

// Binary Lifting
int up[N][LOG + 1];
int depth[N];

int best[N];
// best[c] = min dist from centroid c to any red node
// query needs min dist from node X to any red node
// so return best[c] + dist(x,c)
// x ----> c -----> nearest red node known by c

// Computes subtree size of current component
void dfsSize(int node, int p) {
  sz[node] = 1;

  for (int child : adj[node]) {
    if (child == p) continue;

    if (removed[child]) continue;

    dfsSize(child, node);

    sz[node] += sz[child];
  }
}

// Centroid = node which when removed, makes every comp size <= totalsize/2
// Starting from any node, if some child has > half the nodes, centroid must lie
// inside that child

int findCentroid(int node, int p, int totalSize) {
  for (int child : adj[node]) {
    if (child == p) continue;

    if (removed[child]) continue;

    if (sz[child] > totalSize / 2) return findCentroid(child, node, totalSize);
  }

  // else this node itself is centroid
  return node;
}

// Builds the centroid tree recursively.
// parent = parent in the CENTROID TREE
// NOT the original tree.

void buildCentroid(int entryNode, int parent) {
  // Compute subtree sizes of this component.
  dfsSize(entryNode, -1);

  // Find centroid of this component.
  int centroid = findCentroid(entryNode, -1, sz[entryNode]);

  // Store centroid tree parent.
  centroidParent[centroid] = parent;

  // Remove centroid so future DFS cannot cross it.
  removed[centroid] = true;

  // Every remaining connected component
  // becomes an independent centroid decomposition.
  for (int child : adj[centroid]) {
    if (removed[child]) continue;

    buildCentroid(child, centroid);
  }
}

// Preprocessing for binary lifting
void dfs(int node, int p) {
  up[node][0] = p;

  rep(j, 1, LOG + 1) { up[node][j] = up[up[node][j - 1]][j - 1]; }

  for (int child : adj[node]) {
    if (child == p) continue;

    depth[child] = depth[node] + 1;

    dfs(child, node);
  }
}

int kthAncestor(int node, int k) {
  for (int j = 0; j <= LOG; j++) {
    if (k & (1 << j)) {
      node = up[node][j];
    }
  }
  return node;
}

int LCA(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);

  u = kthAncestor(u, depth[u] - depth[v]);

  if (u == v) return u;

  for (int j = LOG; j >= 0; j--) {
    if (up[u][j] != up[v][j]) {
      u = up[u][j];
      v = up[v][j];
    }
  }

  return up[u][0];
}

int dist(int u, int v) { return depth[u] + depth[v] - 2 * depth[LCA(u, v)]; }

// We update node color in centroid tree & it updates its centroid ancestors -
// TC = O(LogN)

void update(int v) {
  int cur = v;
  while (cur != -1) {
    best[cur] = min(best[cur], dist(cur, v));
    cur = centroidParent[cur];
  }
}

int query(int v) {
  int ans = INF;
  int cur = v;
  while (cur != -1) {
    ans = min(ans, best[cur] + dist(cur, v));
    cur = centroidParent[cur];
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  depth[1] = 0;
  dfs(1, 0);

  buildCentroid(1, -1);

  fill(best, best + N, INF);
  update(1);  // Initial node is red

  while (m--) {
    int t, v;
    cin >> t >> v;

    if (t == 1) {
      update(v);
    } else {
      pf(query(v));
    }
  }
}

int main() {
  solve();
  return 0;
}