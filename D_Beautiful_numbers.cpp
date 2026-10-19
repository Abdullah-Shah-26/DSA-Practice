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

LCM can have atmax 48 distinct values but they need to be mapped to limited
indices

This version : TLE 
==========================
*/

const ll m = 2520;
int lcmID[m + 1];
vi lcms;

void precompute() {
  for (int x = 1; x <= 2520; x++) {
    if (2520 % x == 0) {
      lcms.pb(x);
      lcmID[x] = (int)lcms.size() - 1;
    }
  }
}

string l, r;

ll dp[20][2][2][2520][48];

ll dfs(int i, bool tight, bool lz, ll rem, ll Lcm, string &s) {
  int n = s.size();

  if (i == n)
    return !lz && rem % Lcm == 0;

  int limit = tight ? (s[i] - '0') : 9;

  int Id = lcmID[Lcm];
  ll &ans = dp[i][tight][lz][rem][Id];

  if (ans != -1)
    return ans;

  ans = 0;

  for (int d = 0; d <= limit; d++) {

    bool newLz = lz && (d == 0);
    bool newT = tight && (d == s[i] - '0');

    ll newRem = rem;
    ll newLcm = Lcm;

    if (!newLz) {
      newRem = (rem * 10 + d) % m;

      if (d != 0)
        newLcm = lcm(newLcm, (ll)d);
    }

    ans = (ans + dfs(i + 1, newT, newLz, newRem, newLcm, s));
  }

  return ans;
}

ll f(string s) {

  memset(dp, -1, sizeof(dp));

  return dfs(0, 1, 1, 0, 1, s);
}

string subOne(string &s) {
  int i = (int)s.size() - 1;

  while (i >= 0 && s[i] == '0') {
    s[i] = '9';
    i--;
  }

  if (i >= 0)
    s[i]--;

  int j = 0;

  // Removing leading zeros
  // j + 1 < n ensures we dont remove the last zero
  while (j + 1 < (int)s.size() && s[j] == '0')
    j++;

  return s.substr(j);
}

void solve() {
  cin >> l >> r;

  string L = subOne(l);

  ll ans = (f(r) - f(L));

  cout << ans << endl;
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