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
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define yno(a) cout << ((a) ? "Yes\n" : "No\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================

ABC : 478
Problem E : 

==========================
*/

void solve() {
  int n, q;
  cin >> n >> q;

  vvpii it(q + 1);

  for (int i = 0; i < q; i++) {
    int l, r, x;
    cin >> l >> r >> x;

    it[x].pb({l, r});
  }

  vi diff(n + 2);

  for (int x = 1; x <= q; x++) {
    vpii &v = it[x];

    if (v.empty())
      continue;

    sort(v.begin(), v.end());

    int l = v[0].first;
    int r = v[0].second;

    for (int i = 1; i < (int)v.size(); i++) {
      int nl = v[i].first;
      int nr = v[i].second;

      if (nl <= r) {
        r = max(r, nr);
      } else {
        diff[l]++;
        diff[r + 1]--;

        l = nl;
        r = nr;
      }
    }

    diff[l]++;
    diff[r + 1]--;
  }

  int cur = 0;

  for (int i = 1; i <= n; i++) {
    cur += diff[i];
    cout << cur << " ";
  }

  cout << '\n';
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}