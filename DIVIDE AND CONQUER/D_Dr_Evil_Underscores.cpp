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

int f(vi &a, int bit) {
  if (bit < 0 || a.empty())
    return 0;

  vi zero, one;

  for (int x : a) {
    if (x & (1 << bit))
      one.pb(x);
    else
      zero.pb(x);
  }

  if (zero.empty())
    return f(one, bit - 1);
  if (one.empty())
    return f(zero, bit - 1);

  return (1 << bit) + min(f(zero, bit - 1), f(one, bit - 1));
}

void solve() {
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  cout << f(a, 29) << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}