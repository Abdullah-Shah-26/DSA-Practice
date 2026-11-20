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

Min colors needed (k) = 1 (if DAG)
                      = 2 (if cyclic)

==========================
*/

const int N = 5005;

// Directed acyclic graph
bool dag;

vvpii adj;
vi state(N, 0);
vi color(N, 1);

// state = 0(unvis), 1(in rec stack), 2(finished)

void dfs(int u) {
  state[u] = 1;

  for (auto [v, id] : adj[u]) {
    if (state[v] == 0) {
      color[id] = 1;
      dfs(v);
    }
    // Back edge
    else if (state[v] == 1) {
      dag = false;
      color[id] = 2;
    }
  }

  state[u] = 2;
}

void solve() {
  int n, m;
  cin >> n >> m;

  adj.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back({v, i});
  }

  dag = true;
  for (int u = 1; u <= n; u++)
    if (state[u] == 0)
      dfs(u);

  if (dag)
    cout << 1 << endl;
  else
    cout << 2 << endl;

  for (int i = 0; i < m; i++)
    cout << color[i] << " ";

  cout << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}