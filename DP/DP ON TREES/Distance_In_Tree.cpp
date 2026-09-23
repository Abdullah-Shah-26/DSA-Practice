#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define oset                                   \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Macros ----------
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define nl        \
  do {            \
    cout << '\n'; \
  } while (0)

const int MAXN = 50001;
const int MAXK = 501;

vector<int> adj[MAXN];
int dp[MAXN][MAXK];
int n, k;
ll ans = 0;

//! TC = O(N * K) | SC = O(N * K)

// dp[u][d] = no of nodes in subtree of u (including u) at dist d from u

void dfs(int u, int p) {
  dp[u][0] = 1; // u itself

  for (auto &v : adj[u]) {
    if (v != p) {
      dfs(v, u);

      // Count pairs going from u to v
      for (int d1 = 0; d1 < k; d1++) {
        int d2 = k - d1 - 1;
        ans += 1LL * dp[u][d1] * dp[v][d2]; // old nodes at u * new nodes at v
      }

      // Reindexed
      for (int d = 1; d <= k; d++) {
        dp[u][d] += dp[v][d - 1]; // put v's nodes into u
      }
    }
  }
}

// ---------- Solve ---------
void solve() {
  memset(dp, 0, sizeof(dp));
  cin >> n >> k;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  dfs(1, 0);

  cout << ans;
  nl;
}

// ---------- Main ----------
int main() {
  solve();
  return 0;
}
