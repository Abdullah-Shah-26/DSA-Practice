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
  int n, p;
  cin >> n >> p;

  vi a(n);
  rv(a);

  vpii vals;
  for (int i = 0; i < n; i++)
    vals.pb({a[i], i});

  sort(all(vals));

  // Means edge (i, i + 1) is selected
  vb isConnected(n - 1, false);

  ll ans = 0;

  for (auto [g, idx] : vals) {
    if (g >= p)
      break;

    // Expand left
    int i = idx;
    while (i > 0 && !isConnected[i - 1] && a[i - 1] % g == 0) {
      isConnected[i - 1] = true;
      ans += g;
      i--;
    }

    // Expand right
    i = idx;
    while (i < n - 1 && !isConnected[i] && a[i + 1] % g == 0) {
      isConnected[i] = true;
      ans += g;
      i++;
    }
  }

  // Using default edge cost i.e p for rem edges
  for (int i = 0; i < n - 1; i++)
    if (!isConnected[i])
      ans += p;

  cout << ans << endl;
}

int main() {

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}