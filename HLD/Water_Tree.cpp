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

const int N = 500005;

class LazySeg {
 public:
  int n;

  vector<int> seg;
  vector<int> lazy;

  /*
  -1 = nothing pending
   0 = assign whole segment to 0
   1 = assign whole segment to 1
  */

  void init(int sz) {
    n = sz;
    seg.as(4 * n, 0);
    lazy.as(4 * n, -1);
  }

  // For pushing pending updates before going deeper
  void push(int i, int l, int r) {
    if (lazy[i] == -1) return;

    seg[i] = (r - l + 1) * lazy[i];

    if (l != r) {
      lazy[2 * i + 1] = lazy[i];
      lazy[2 * i + 2] = lazy[i];
    }

    lazy[i] = -1;
  }

  void update(int i, int l, int r, int ql, int qr, int val) {
    push(i, l, r);

    if (l > qr || r < ql) return;

    if (l >= ql && r <= qr) {
      lazy[i] = val;
      push(i, l, r);
      return;
    }

    int mid = (l + r) >> 1;
    update(2 * i + 1, l, mid, ql, qr, val);
    update(2 * i + 2, mid + 1, r, ql, qr, val);

    // we never ask how many filled vertices are there so its not used here
    seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
  }

  int query(int i, int l, int r, int pos) {
    push(i, l, r);

    if (l == r) return seg[i];

    int mid = (l + r) >> 1;

    if (pos <= mid) return query(2 * i + 1, l, mid, pos);

    return query(2 * i + 2, mid + 1, r, pos);
  }

  void update(int l, int r, int val) { update(0, 0, n - 1, l, r, val); }

  int query(int pos) { return query(0, 0, n - 1, pos); }
};

vector<int> adj[N];

// HLD
int parent[N];
int depth[N];
int sz[N];     
int heavy[N];  // child with max subtree
int head[N];   // head of heavy chain
int pos[N];    // idx in HLD order (For root->node)
int curPos = 0;
LazySeg seg;
/*

Root->node
HLD chains
head,pos

segTree
0-empty
1-filled
Instead of going to each vertex, marking its filled & empty
We are using segtree to mark it optimally in O(LogN)

*/

void fillSubtree(int v) { seg.update(pos[v], pos[v] + sz[v] - 1, 1); }

void emptyPath(int v) {
  while (head[v] != head[1]) {
    // empty the chain of v & repeat until we reach the root's chain
    seg.update(pos[head[v]], pos[v], 0); 
    v = parent[head[v]]; // jump to chain above
  } 
  seg.update(pos[1], pos[v], 0);
}

void dfs(int node, int p) {
  parent[node] = p;
  sz[node] = 1;
  heavy[node] = -1;

  int maxSz = 0;
  for (int child : adj[node]) {
    if (child == p) continue;

    depth[child] = depth[node] + 1;

    dfs(child, node);

    sz[node] += sz[child];

    // child with largest subtree becomes heavy
    if (sz[child] > maxSz) {
      heavy[node] = child;
      maxSz = sz[child];
    }
  }
}

void decompose(int node, int h) {
  head[node] = h;
  pos[node] = curPos++;

  if (heavy[node] != -1) {
    decompose(heavy[node], h);
  }

  for (int child : adj[node]) {
    if (child == parent[node]) continue;
    if (child == heavy[node]) continue;

    // Start new chain from every light child
    decompose(child, child);
  }
}
int n;
void solve() {
  cin >> n;

  rep(i, 1, n + 1) adj[i].clear();

  rep(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  depth[1] = 0;
  curPos = 0;
  dfs(1, 0);
  decompose(1, 1);

  seg.init(n);

  int q;
  cin >> q;

  while (q--) {
    int type, v;
    cin >> type >> v;

    if (type == 1) {
      fillSubtree(v);
    } else if (type == 2) {
      emptyPath(v);
    } else {
      cout << seg.query(pos[v]) << endl;
    }
  }
}

int main() {
  solve();
  return 0;
}