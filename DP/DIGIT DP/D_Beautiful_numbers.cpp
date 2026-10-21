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

LCM(1,2,3,4,5,6,7,8,9) = 2520

2520 = 2^3 * 3^2 * 5 * 7

(3 + 1) * (2 + 1) * (1 + 1) * (1 + 1) = 48

LCM can have at max 48 distinct values but they need to be mapped to limited
indices

==========================
*/

const int m = 2520;
int lcmID[m + 1];
vi lcms;

ll dp[20][2][2520][48];

void precompute() {
  for (int x = 1; x <= m; x++) {
    if (m % x == 0) {
      lcms.pb(x);
      lcmID[x] = (int)lcms.size() - 1;
    }
  }

  memset(dp, -1, sizeof(dp));
}

ll dfs(int i, bool tight, bool lz, ll rem, ll Lcm, string &s) {
  int n = s.size();

  if (i == n)
    return !lz && rem % Lcm == 0;

  int limit = tight ? (s[i] - '0') : 9;

  int Id = lcmID[Lcm];

  if (!tight && dp[i][lz][rem][Id] != -1)
    return dp[i][lz][rem][Id];

  ll ans = 0;

  for (int d = 0; d <= limit; d++) {
    bool newLz = lz && (d == 0);
    bool newT = tight && (d == s[i] - '0');

    ll newRem = rem;
    ll newLcm = Lcm;

    if (!newLz) {
      newRem = (rem * 10 + d) % m;

      if (d != 0) {
        newLcm = lcm(newLcm, (ll)d);
      }
    }

    ans = (ans + dfs(i + 1, newT, newLz, newRem, newLcm, s));
  }

  if (!tight)
    dp[i][lz][rem][Id] = ans;

  return ans;
}

ll f(ll n) {
  if (n == 0)
    return 0;

  string s = to_string(n);

  // If after doing -1, our string len gets reduced
  // Pad zeros to front so that its len = 19
  s = string(19 - s.size(), '0') + s;

  return dfs(0, 1, 1, 0, 1, s);
}

void solve() {
  ll l, r;
  cin >> l >> r;

  cout << f(r) - f(l - 1) << endl;
}

int main() {
  precompute();

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}