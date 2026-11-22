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

const int N = 500000;
const int K = 750;

ll a[N + 1];
ll sum[K][K];

// sum[x][y] = sum of all a[i] such that i % x == y
// sum[mod][remainder]

void solve() {
  int q;
  cin >> q;

  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;

    // update
    if (t == 1) {
      a[x] += y;

      for (int mod = 1; mod < K; mod++) sum[mod][x % mod] += y;
    }

    // query
    else {

      // smaller mod, more valid indices, precompute ans
      if (x < K)
        cout << sum[x][y] << endl;

      // larger mod, less valid indices, brute force & find
      else {
        ll ans = 0;

        // i mod x = y
        // i = y + k*x
        for (int i = y; i <= N; i += x) ans += a[i];

        cout << ans << endl;
      }
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