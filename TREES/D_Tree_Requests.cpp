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

const int N = 500005;

string s;

vi adj[N];
int tin[N], tout[N];
vpii prefXor[N]; // [entry time, pref xor]

int timer = 0;

void dfs(int u, int depth) {
  tin[u] = ++timer;

  int prev = prefXor[depth].back().second;
  int cur = prev ^ (1 << (s[u] - 'a'));

  prefXor[depth].pb({tin[u], cur});

  for (int v : adj[u])
    dfs(v, depth + 1);

  tout[u] = ++timer;
}

void solve() {
  int n, m;
  cin >> n >> m;

  for (int v = 1; v < n; v++) {
    int p;
    cin >> p;

    p--;
    adj[p].pb(v);
  }

  cin >> s;

  // Pushing dummy vals
  for (int d = 0; d < n; d++)
    prefXor[d].pb({0, 0});

  dfs(0, 0);

  while (m--) {

    // vertex, depth
    int v, h;
    cin >> v >> h;

    v--;
    h--;

    int l = lower_bound(all(prefXor[h]), make_pair(tin[v], -1)) -
            prefXor[h].begin() - 1;

    int r = lower_bound(all(prefXor[h]), make_pair(tout[v], -1)) -
            prefXor[h].begin() - 1;

    int mask = prefXor[h][r].second ^ prefXor[h][l].second;

    if (mask == 0 || __builtin_popcount(mask) == 1) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}