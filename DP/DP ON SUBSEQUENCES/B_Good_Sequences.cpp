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

const int N = 1e5;

void solve() {
  int n;
  cin >> n;

  // Given a is sorted
  vi a(n);
  rv(a);

  // gcd(x, y) > 1 only if x,y share atleast 1 prime factor

  vi spf(N + 1, 0);
  for (int i = 1; i <= N; i++) spf[i] = i;

  for (int i = 2; i * i <= N; i++) {
    // Mark all the multiples of i
    for (int j = i * i; j <= N; j += i) {
      if (spf[j] == j) {
        spf[j] = i;
      }
    }
  }

  // best[p] = max prev dp div by prime p
  vi best(N + 1, 0);

  int ans = 1;

  for (int x : a) {
    int dp = 1;
    int y = x;

    // Distinct prime factors of x
    while (y > 1) {
      int p = spf[y];

      dp = max(dp, best[p] + 1);

      while (y % p == 0) {
        y /= p;
      }
    }

    // Update best
    y = x;
    while (y > 1) {
      int p = spf[y];
      best[p] = max(best[p], dp);

      while (y % p == 0) {
        y /= p;
      }
    }

    ans = max(ans, dp);
  }

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}