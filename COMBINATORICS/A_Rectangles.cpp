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
  ll n, m;
  cin >> n >> m;

  ll mat[n][m];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> mat[i][j];

  ll ans = 0;

  // Row
  for (int i = 0; i < n; i++) {
    ll w = 0, b = 0;
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 0)
        w++;
      else
        b++;
    }

    ans += (1LL << w) - 1;
    ans += (1LL << b) - 1;
  }

  // Col
  for (int j = 0; j < m; j++) {
    ll w = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (mat[i][j] == 0)
        w++;
      else
        b++;
    }

    // -1 for removing empty subset
    ans += (1LL << w) - 1;
    ans += (1LL << b) - 1;
  }

  // Each cell's singleton subset is counted twice:
  // Remove over count
  ans -= m * n;

  cout << ans << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}