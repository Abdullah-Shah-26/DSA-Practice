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

Virtual Tree DP

dfsVT(u) returns:
Does subtree(u) still contain 1 active
important component connected to u?

cnt = number of children returning true

Case 1 : u is NOT important

cnt = 0

      u

Nothing below.
return false.

Case 2 : u is NOT important

      u
      |
      *

cnt = 1

Exactly 1 active component.
Pass it upward.

return true.

Case 3 : u is NOT important

      u
     / \
    *   *

cnt >= 2

Two (or more) important components meet.
Capture u.

ans++
return false

Case 4 : u IS important

      u*

No matter how many child components arrive,
they cannot connect through u.

Need one cut for every active child.

ans += cnt
return true


==========================
*/

const int N = 200005;
const int LOG = 20;

int n, q;

vi adj[N]; // original tree
vi vt[N];  // virtual tree

int up[N][LOG];
int depth[N];

int tin[N];
int tout[N];
int timer;

bool imp[N];

int ans; // min cities barbarians need to capture to isolate imp ones

void dfs(int u, int p) {
  tin[u] = ++timer;
  up[u][0] = p;

  for (int i = 1; i < LOG; i++)
    up[u][i] = up[up[u][i - 1]][i - 1];

  for (int v : adj[u]) {
    if (v == p)
      continue;

    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
  tout[u] = timer;
}

int LCA(int u, int v) {
  if (depth[u] < depth[v])
    swap(u, v);

  int diff = depth[u] - depth[v];

  for (int i = LOG - 1; i >= 0; i--) {
    if (diff & (1 << i))
      u = up[u][i];
  }

  if (u == v)
    return u;

  for (int i = LOG - 1; i >= 0; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }

  return up[u][0];
}

// Is u ancestor of v
bool isAncestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

vi buildVT(vi nodes) {

  auto cmp = [&](int a, int b) { return tin[a] < tin[b]; };

  sort(all(nodes), cmp);

  int sz = nodes.size();

  // Inserting LCA's of adj nodes
  for (int i = 0; i < sz - 1; i++) {
    nodes.pb(LCA(nodes[i], nodes[i + 1]));
  }

  sort(all(nodes), cmp);

  nodes.erase(unique(all(nodes)), nodes.end());

  for (int u : nodes)
    vt[u].clear();

  stack<int> st;
  st.push(nodes[0]);

  for (int i = 1; i < nodes.size(); i++) {

    // Pop until stack stack's top becomes ancestor of curNode
    while (!isAncestor(st.top(), nodes[i]))
      st.pop();

    vt[st.top()].push_back(nodes[i]);
    st.push(nodes[i]);
  }

  return nodes;
}

bool dfsVT(int u) {
  int cnt =
      0; // no of children whose subtree still contain 1 active imp component

  for (int v : vt[u])
    cnt += dfsVT(v);

  if (imp[u]) {
    ans += cnt;
    return true;
  }

  if (cnt >= 2) {
    ans++;
    return false;
  }

  return cnt == 1;
}

void solve() {
  cin >> n;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  depth[1] = 0;
  dfs(1, 0);

  cin >> q;
  while (q--) {

    int k;
    cin >> k;

    vi impNodes(k);

    for (int i = 0; i < k; i++) {
      cin >> impNodes[i];
      imp[impNodes[i]] = true;
    }

    bool valid = 1;

    // Adjacent nodes imp, cannot capture, -1
    for (int u : impNodes) {
      if (u != 1 && imp[up[u][0]]) {
        valid = 0;
        break;
      }
    }

    if (!valid) {
      pf(-1);

      for (int u : impNodes)
        imp[u] = false;

      continue;
    }

    vi nodes = buildVT(impNodes);

    ans = 0;

    dfsVT(nodes[0]); // Is root of VT

    pf(ans);

    // Clearing for another queries
    for (int u : nodes) {
      vt[u].clear();
      imp[u] = false;
    }
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