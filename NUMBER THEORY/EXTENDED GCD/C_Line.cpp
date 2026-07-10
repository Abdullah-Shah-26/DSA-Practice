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
#define rm(mat)         \
  for (auto &r : (mat)) \
    for (auto &x : (r)) \
  cin >> x
#define pm(mat)                   \
  do {                            \
    for (const auto &r : (mat)) { \
      for (const auto &x : (r))   \
        cout << x << ' ';         \
      cout << '\n';               \
    }                             \
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

A line on the plane is described by an equation Ax + By + C = 0. You are to find
any point on this line, whose coordinates are integer numbers from  - 5·1018 to
5·1018 inclusive, or to find out that such points do not exist. Input

The first line contains three integers A, B and C ( - 2·109 ≤ A, B, C ≤ 2·109) —
corresponding coefficients of the line equation. It is guaranteed that
A2 + B2 > 0.

ax + by = -c
ax + by = gcd(a,b) by extended gcd

==========================
*/

ll extendedGCD(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  ll x1, y1;
  ll gcd = extendedGCD(b, a % b, x1, y1);

  x = y1;
  y = x1 - (a / b) * y1;

  return gcd;
}

void solve() {
  ll a, b, c, x, y;
  cin >> a >> b >> c;

  ll g = extendedGCD(a, b, x, y);

  if ((-c) % g != 0) {
    pf(-1);
  } else {
    ll k = (-c) / g;
    x *= k;
    y *= k;
    cout << x << " " << y;
  }
}

int main() {

  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}