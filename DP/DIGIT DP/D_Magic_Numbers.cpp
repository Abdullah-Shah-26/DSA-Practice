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

ll m, d;
string a, b;

ll dp[2001][2001][2];

ll dfs(int i, int rem, bool tight, string& s) {
  int n = s.size();

  if (i == n) return rem == 0;

  if (dp[i][rem][tight] != -1) return dp[i][rem][tight];

  int limit = tight ? s[i] - '0' : 9;

  ll ans = 0;

  for (int digit = 0; digit <= limit; digit++) {
    // Skip leading zeros
    if (i == 0 && digit == 0) continue;

    // We must place given digit d 
    // At even positions from left (1 based idx)
    if (i % 2 == 1) {
      if (digit != d) continue;
    }
    // digit d cannot be at odd positions
    else {
      if (digit == d) continue;
    }

    int newRem = (rem * 10LL + digit) % m;
    bool newT = tight && (digit == s[i] - '0');

    ans = (ans + dfs(i + 1, newRem, newT, s)) % MOD;
  }

  return dp[i][rem][tight] = ans;
}

ll f(string s) {
  memset(dp, -1, sizeof(dp));
  return dfs(0, 0, true, s);
}

string subOne(string s) {
  int i = s.size() - 1;

  while (i >= 0 && s[i] == '0') {
    s[i] = '9';
    i--;
  }

  // Will skip leading zero in dfs
  // Cause the candidate answers must be of len = a,b
  // So we are not changing length here
  if(i >= 0) s[i]--;
  return s;
}

void solve() {
  cin >> m >> d >> a >> b;

  string aMinusOne = subOne(a);
  ll ans = (f(b) - f(aMinusOne) + MOD) % MOD;

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}