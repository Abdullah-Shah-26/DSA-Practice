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
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================

dp[i][0] = min cost up to i, s[i] not reversed
dp[i][1] = min cost up to i, s[i] is reversed

==========================
*/

void solve() {
  int n;
  cin >> n;

  vll c(n);
  rv(c);

  vs s(n), rev(n);

  for (int i = 0; i < n; i++) {
    cin >> s[i];
    rev[i] = s[i];
    reverse(all(rev[i]));
  }

  vvll dp(n, vll(2, LINF));

  dp[0][0] = 0;
  dp[0][1] = c[0];

  for (int i = 1; i < n; i++) {

    // Current str is not reversed
    if (s[i - 1] <= s[i])
      dp[i][0] = min(dp[i][0], dp[i - 1][0]);

    if (rev[i - 1] <= s[i])
      dp[i][0] = min(dp[i][0], dp[i - 1][1]);

    // Cur str is reversed
    if (s[i - 1] <= rev[i])
      dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i]);

    if (rev[i - 1] <= rev[i])
      dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
  }

  ll ans = min(dp[n - 1][0], dp[n - 1][1]);

  if (ans == LINF)
    cout << -1 << endl;
  else
    cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}