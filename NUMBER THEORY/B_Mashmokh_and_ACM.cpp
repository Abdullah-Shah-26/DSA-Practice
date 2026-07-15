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
  ll n, k;
  cin >> n >> k;

  vll factors[n + 1];
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        factors[i].pb(j);

        if (i / j != j) {
          factors[i].push_back(i / j);
        }
      }
    }
  }

  ll dp[k + 1][n + 1]; // dp[i][j] =  good arrays of len i ending in j

  for (int i = 1; i <= n; i++)
    dp[1][i] = 1;

  for (int i = 2; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = 0LL; // initialization

      for (auto f : factors[j]) {
        dp[i][j] = (dp[i][j] + dp[i - 1][f]) % MOD;
      }
    }
  }

  ll cnt = 0;
  for (ll j = 1; j <= n; j++)
    cnt = (cnt + dp[k][j]) % MOD;

  pf(cnt);
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}