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

int n, m;
vvll best;
vvll dp;

ll f(int i, ll rem) {
  if (rem == 0) return 0;
  if (i == n) return -LINF;

  ll& ans = dp[i][rem];

  if (ans != -1) return ans;

  ans = -LINF;

  ll sz = best[i].size() - 1;

  for (ll k = 0; k <= min(rem, sz); k++) {
    ans = max(ans, f(i + 1, rem - k) + best[i][k]);
  }

  return ans;
}

void solve() {
  cin >> n >> m;

  best.resize(n);

  for (int i = 0; i < n; i++) {
    int sz;
    cin >> sz;

    vll a(sz);
    rv(a);

    vll pref(sz + 1, 0);
    vll suff(sz + 1, 0);

    for (int j = 0; j < sz; j++) pref[j + 1] = pref[j] + a[j];
    for (int j = sz - 1; j >= 0; j--) suff[j] = suff[j + 1] + a[j];

    best[i].assign(sz + 1, 0);

    for (int k = 1; k <= sz; k++) {
      for (int l = 0; l <= k; l++) {
        best[i][k] = max(best[i][k], pref[l] + suff[sz - (k - l)]);
      }
    }
  }

  dp.assign(n + 1, vll(m + 1, -1));

  cout << f(0, m) << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}