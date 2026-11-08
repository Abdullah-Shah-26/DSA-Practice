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

#define rv(a) \
  for (auto& x : (a)) cin >> x
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

const int N = 505;

int n, k;
int a[N];
bool dp[N][N][N];

// i = coin we are processing
// j = how much more to make sum k
// y = how much sum do we need to reach this particular sum y

/*

TLE :

bool f(int i, int j, int y) {
  if (j < 0 || y < 0 || y > j) return false;

  if (i == n) return j == 0 && y == 0;

  if (dp[i][j][y] != -1) return dp[i][j][y];

  int x = a[i];

  bool ans = f(i + 1, j, y);

  if (j >= x) {
    ans |= f(i + 1, j - x, y);

    if (y >= x) ans |= f(i + 1, j - x, y - x);
  }

  return dp[i][j][y] = ans;
}

*/

void solve() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) cin >> a[i];

  vi ans;

  // dp[i][j][k] = using first i coins, some subset sums to j, and some subset
  // of THAT subset sums to y
  dp[0][0][0] = true;

  for (int i = 1; i <= n; i++) {
    int x = a[i - 1];

    for (int j = 0; j <= k; j++) {
      for (int y = 0; y <= j; y++) {
        bool ok = dp[i - 1][j][y];

        if (j >= x) {
          ok |= dp[i - 1][j - x][y];

          if (y >= x) {
            ok |= dp[i - 1][j - x][y - x];
          }
        }

        dp[i][j][y] = ok;
      }
    }
  }

  for (int y = 0; y <= k; y++)
    if (dp[n][k][y]) ans.pb(y);

  cout << ans.size() << endl;
  for (int x : ans) cout << x << " ";

  cout << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}