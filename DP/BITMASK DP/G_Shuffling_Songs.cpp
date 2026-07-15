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



==========================
*/

void solve() {
  int n;
  cin >> n;

  vector<string> g(n), w(n);

  for (int i = 0; i < n; i++)
    cin >> g[i] >> w[i];

  // Adj Matrix
  vector<vector<int>> adj(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j && (g[i] == g[j] || w[i] == w[j]))
        adj[i][j] = 1;

  int N = (1 << n);
  vector<vector<int>> dp(N, vi(n, 0));

  for (int mask = 1; mask < N; mask++) {
    for (int last = 0; last < n; last++) {
      if (!(mask & (1 << last)))
        continue;

      // Base case :
      if (mask == (1 << last)) {
        dp[mask][last] = 1;
        continue;
      }

      int prevMask = mask ^ (1 << last);
      for (int prev = 0; prev < n; prev++) {
        if ((prevMask & (1 << prev)) && dp[prevMask][prev] && adj[prev][last]) {
          dp[mask][last] = 1;
          break;
        }
      }
    }
  }

  int best = 0;
  for (int mask = 0; mask < N; mask++) 
    for (int last = 0; last < n; last++) 
      if (dp[mask][last])
        best = max(best, __builtin_popcount(mask));

  pf(n - best); // Min removals
}

int main() {

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}