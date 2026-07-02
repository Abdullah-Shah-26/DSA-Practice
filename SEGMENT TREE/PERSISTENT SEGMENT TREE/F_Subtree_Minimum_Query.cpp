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

#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define pv(a)                 \
  do {                        \
    for (const auto &x : (a)) \
      cout << x << ' ';       \
    cout << '\n';             \
  } while (0)
#define rm(mat)         \
  for (auto &r : (mat)) \
    for (auto &x : (r)) \
  cin >> x
#define pm(mat)                   \
  do {                            \
    for (const auto &r : (mat)) { \
      for (const auto &x : (r))   \
        cout << x << ' ';         \
      cout << '\n';               \
    }                             \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================
Observation / Thinking
--------------------------

Node x, dist k
Find min value among descendants of x 
Ignore nodes whose depth > depth[x] + k

So nodes lie in subtree of x ->  Euler Tour
[tin[x], tout[x]] 

Inside [L,R] ignore nodes whose depth > limit

We add nodes depth by depth - Persistence 

==========================
*/

vvi adj;

vi tin, tout;
vi depth;
vi base;
vi a;

vvi nodesAtDepth;

int timer = 0;
int maxDepth = 0;

struct Node {
  int mn; // min value
  Node *left, *right;

  Node(int val = INF) {
    mn = val;
    left = right = NULL;
  }
};

Node *build(int l, int r, vi &a) {
  if (l == r)
    return new Node(a[l]);

  int mid = (l + r) >> 1;

  Node *leftChild = build(l, mid, a);
  Node *rightChild = build(mid + 1, r, a);

  Node *root = new Node();
  root->left = leftChild;
  root->right = rightChild;

  root->mn = min(leftChild->mn, rightChild->mn);

  return root;
}

int query(Node *root, int l, int r, int ql, int qr) {
  if (l > qr || r < ql)
    return INF;

  if (l >= ql && r <= qr) {
    return root->mn;
  }

  int mid = (l + r) >> 1;

  return min(query(root->left, l, mid, ql, qr),
             query(root->right, mid + 1, r, ql, qr));
}

Node *update(Node *root, int l, int r, int idx, int val) {
  Node *newRoot = new Node();
  *newRoot = *root;

  if (l == r) {
    newRoot->mn = val;
    return newRoot;
  }

  int mid = (l + r) >> 1;

  if (idx <= mid)
    newRoot->left = update(root->left, l, mid, idx, val);
  else
    newRoot->right = update(root->right, mid + 1, r, idx, val);

  newRoot->mn = min(newRoot->left->mn, newRoot->right->mn);

  return newRoot;
}

void dfs(int u, int p) {
  tin[u] = ++timer;

  maxDepth = max(maxDepth, depth[u]);
  nodesAtDepth[depth[u]].push_back(u);

  for (int v : adj[u]) {
    if (v == p)
      continue;
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
  tout[u] = timer;
}

void solve() {
  int n, r;
  cin >> n >> r;

  a.assign(n + 1, 0);
  tin.assign(n + 1, 0);
  tout.assign(n + 1, 0);
  depth.assign(n + 1, 0);
  adj.assign(n + 1, {});
  nodesAtDepth.assign(n + 1, {}); // Max possible depth = (n-1)

  rep(i, 1, n + 1) cin >> a[i];

  rep(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  timer = 0;
  maxDepth = 0;
  depth[r] = 0;
  dfs(r, 0);

  // roots[0] = nodes with depth <= 0
  base.assign(n + 1, INF);
  for (int u : nodesAtDepth[0])
    base[tin[u]] = a[u];

  vector<Node *> roots;
  roots.pb(build(1, n, base));

  for (int d = 1; d <= maxDepth; d++) {
    Node *cur = roots.back();

    for (int u : nodesAtDepth[d])
      cur = update(cur, 1, n, tin[u], a[u]);

    roots.pb(cur);
  }

  int m, last = 0;
  cin >> m;
  while (m--) {
    int p, q;
    cin >> p >> q;

    int x = ((p + last) % n) + 1;
    int k = (q + last) % n;
    int limit = min(maxDepth, depth[x] + k);

    last = query(roots[limit], 1, n, tin[x], tout[x]);
    pf(last);
  }
}

int main() {

  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}