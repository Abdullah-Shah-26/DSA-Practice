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

Classical DSU on Tree Problem

==========================
*/

int n;
vvi adj;

vi sub; // subtree size
vi heavy;

vi tin, tout;
vi euler;

vi freq;
vi color;
vll ans;

int timer = 0;
int maxFreq;
ll sum; // sum of colors having freq = maxFreq

void dfsSize(int u, int p) {
  sub[u] = 1;
  heavy[u] = -1;

  int mx = 0;

  for (int v : adj[u]) {
    if (v == p)
      continue;

    dfsSize(v, u);

    sub[u] += sub[v];

    if (sub[v] > mx) {
      mx = sub[v];
      heavy[u] = v;
    }
  }
}

void dfsEuler(int u, int p) {
  tin[u] = timer;
  euler[timer] = u;
  timer++;

  for (int v : adj[u]) {
    if (v != p)
      dfsEuler(v, u);
  }

  tout[u] = timer - 1;
}

void add(int u) {
  int c = color[u];

  freq[c]++;

  if (freq[c] > maxFreq) {
    maxFreq = freq[c];
    sum = c;
  } else if (freq[c] == maxFreq)
    sum += c;
}

void remove(int u) { freq[color[u]]--; }

void dfs(int u, int p, bool keep) {

  // Process light children
  for (int v : adj[u]) {
    if (v == p || v == heavy[u])
      continue;

    dfs(v, u, false);
  }

  // Process heavy child
  if (heavy[u] != -1)
    dfs(heavy[u], u, true);

  // Merge all light subtree
  for (int v : adj[u]) {
    if (v == p || v == heavy[u])
      continue;

    for (int i = tin[v]; i <= tout[v]; i++)
      add(euler[i]);
  }

  // Add curNode
  add(u);
  ans[u] = sum;

  if (!keep) {
    for (int i = tin[u]; i <= tout[u]; i++)
      remove(euler[i]);

    maxFreq = 0;
    sum = 0;
  }
}

void solve() {
  cin >> n;

  adj.assign(n + 1, {});
  color.assign(n + 1, 0);

  sub.assign(n + 1, 0);
  heavy.assign(n + 1, -1);

  tin.assign(n + 1, 0);
  tout.assign(n + 1, 0);
  euler.assign(n, 0);

  freq.assign(n + 1, 0);
  ans.assign(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> color[i];

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  timer = 0;
  maxFreq = 0;
  sum = 0;

  dfsSize(1, 0);
  dfsEuler(1, 0);
  dfs(1, 0, true);

  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
}

int main() {

  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}