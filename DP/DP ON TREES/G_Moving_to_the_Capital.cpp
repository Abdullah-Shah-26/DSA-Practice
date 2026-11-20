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

void solve() {
  int n, m;
  cin >> n >> m;

  vvi adj(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
  }

  // BFS
  // To compute shortest dist from city 1
  vi dist(n + 1, -1);
  queue<int> q;

  dist[1] = 0;
  q.push(1);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  vi dp(n + 1, -1);

  // dp[u] = If we start at city u how close to city 1 can we be 

  function<void(int)> dfs = [&](int u) {
    if (dp[u] != -1)
      return;

    dp[u] = dist[u];

    for (int v : adj[u]) {

      // We move to city with greater dist
      // No special move needed
      if (dist[u] < dist[v]) {
        dfs(v);
        dp[u] = min(dp[u], dp[v]);
      } 
      
      // dist[u] >= dist[v]
      // We move to city with smaller/equal dist
      // It consumes our special move
      // We dont have any special moves ahead so we dont explore using dfs 
      else {
        dp[u] = min(dp[u], dist[v]);
      }
    }
  };

  dfs(1);

  for (int u = 1; u <= n; u++)
    cout << dp[u] << " ";

  cout << endl;
}

int main() {

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}