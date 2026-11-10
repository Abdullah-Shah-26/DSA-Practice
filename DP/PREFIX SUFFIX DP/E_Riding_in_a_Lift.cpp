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
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================

ndp[j] = ways we can finish current trip on floor j

We dont know which floor we started from 
So we try all possible prev valid floors 

==========================
*/

void solve() {
  int n, a, b, k;
  cin >> n >> a >> b >> k;

  vll dp(n + 1), ndp(n + 1), pref(n + 1);

  dp[a] = 1;

  for (int i = 1; i <= k; i++) {
    pref[0] = 0;

    // prefix sum of prev dp values
    for (int j = 1; j <= n; j++)
      pref[j] = (pref[j - 1] + dp[j]) % MOD;

    fill(all(ndp), 0);

    for (int j = 1; j <= n; j++) {
      if (j == b)
        continue;

      int l, r;

      if (j < b) {
        l = 1;
        r = (b + j - 1) / 2;
      } else {
        l = (b + j) / 2 + 1;
        r = n;
      }

      // pref[r] - pref[l - 1] = all ways from valid dist prev floors
      // -dp[j] = to remove ways that start the trip on same floor we are trying to reach
      ndp[j] = (pref[r] - pref[l - 1] + MOD - dp[j] + MOD) % MOD;
    }

    dp.swap(ndp);
  }

  int ans = 0;
  for (int j = 1; j <= n; j++)
    ans = (ans + dp[j]) % MOD;

  cout << ans << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}