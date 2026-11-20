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

const int N = 1e5 + 5;
const int LOG = 20;

vi adj[N];
vi nodesAtDepth[N];

int up[N][LOG];
int depth[N], tin[N], tout[N];
int timer = 0;

void dfs(int u, int p) {
  tin[u] = ++timer;

  up[u][0] = p;

  for (int j = 1; j < LOG; j++)
    up[u][j] = up[up[u][j - 1]][j - 1];

  nodesAtDepth[depth[u]].pb(tin[u]);

  for (int v : adj[u]) {
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }

  tout[u] = timer;
}

int kthAncestor(int u, int k) {
  for (int j = 0; j < LOG; j++)
    if (k & (1 << j))
      u = up[u][j];

  return u;
}

void solve() {
  int n;
  cin >> n;

  for (int v = 1; v <= n; v++) {
    int p;
    cin >> p;

    if (p != 0) {
      adj[p].pb(v);
    }
  }

  for (int u = 1; u <= n; u++) {
    if (up[u][0] == 0 && tin[u] == 0) {
      dfs(u, 0);
    }
  }

  int m;
  cin >> m;

  while (m--) {
    int v, p;
    cin >> v >> p;

    int z = kthAncestor(v, p);

    if (z == 0) {
      cout << 0 << " ";
      continue;
    }

    vi &a = nodesAtDepth[depth[v]];

    int l = lower_bound(all(a), tin[z]) - begin(a);
    int r = upper_bound(all(a), tout[z]) - begin(a);

    cout << r - l - 1 << " "; 
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}