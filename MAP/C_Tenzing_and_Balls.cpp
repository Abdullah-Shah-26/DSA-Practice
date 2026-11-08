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

dp[i] = max no of balls removable from first i positions

Dont use position I
dp[i + 1] = dp[i]

Assume j is prev idx

Use position i
dp[i + 1] = max(dp[i + 1], i - j + 1 + dp[j])

After rearranging the eq : (dp[j] - j) + i + 1

If we have already seen this color in map :
Then we can consider take option

best[color] = max(dp[j] - j) among all prev occurences of that color

==========================
*/

void solve() {
  int n;
  cin >> n;

  vi a(n);
  rv(a);

  vi dp(n + 1, 0);
  map<int, int> best;

  for (int i = 0; i < n; i++) {
    dp[i + 1] = dp[i];  // skip

    if (best.count(a[i])) dp[i + 1] = max(dp[i + 1], i + 1 + best[a[i]]);

    auto it = best.find(a[i]);

    if (it == best.end()) {
      best[a[i]] = dp[i] - i;
    } else {
      it->second = max(it->second, dp[i] - i);
    }

    // This is causing error as 0 wins against -ve
    //  best[a[i]] = max(best[a[i]], dp[i] - i);
  }

  cout << dp[n] << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}