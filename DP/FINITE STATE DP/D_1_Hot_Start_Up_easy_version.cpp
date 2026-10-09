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

#define rv(a) \
  for (auto& x : (a)) cin >> x
#define pv(a)                                   \
  do {                                          \
    for (const auto& x : (a)) cout << x << ' '; \
    cout << '\n';                               \
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



==========================
*/

void solve() {
  int n, k;
  cin >> n >> k;

  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vll hot(k + 1), cold(k + 1);
  for (int i = 1; i <= k; i++) cin >> cold[i];
  for (int i = 1; i <= k; i++) cin >> hot[i];

  // dp[i][j] = min total time after finishing programs upto i
  // where j is the last program run on other cpu
  // j = 0 means cpu hasn't run anything
  vvll dp(n + 1, vll(k + 1, LINF));

  // 1st program can run on any cpu & there is no last program
  dp[1][0] = cold[a[1]];

  for (int i = 2; i <= n; i++) {
    int x = a[i];

    for (int j = 0; j <= k; j++) {
      if (dp[i - 1][j] == LINF) continue;

      // Case 1 :
      // Run a[i] on same cpu
      // If a[i] == a[i - 1], its hot start
      // else its cold start
      ll cost1 = ((a[i] == a[i - 1]) ? hot[x] : cold[x]);
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost1);

      // Case 2 :
      // Run a[i] on other cpu
      // That cpu ran last program j
      // Now the cpu that previously ran a[i - 1] becomes the other cpu
      ll cost2 = ((j == x) ? hot[x] : cold[x]);
      dp[i][a[i - 1]] = min(dp[i][a[i - 1]], dp[i - 1][j] + cost2);
    }
  }

  cout << *min_element(all(dp[n])) << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}