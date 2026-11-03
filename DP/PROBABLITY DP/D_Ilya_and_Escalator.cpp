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

dp[i][j] = prob that after ith second there are j people in escalator

==========================
*/

void solve() {
  int n;
  cin >> n;

  double p, t;
  cin >> p >> t;

  vector<vector<double>> dp(t + 1, vector<double>(n + 1, 0.0));

  // Prob that 0 seconds have passed & 0 people have entered the escalator = 100 percent
  dp[0][0] = 1.0;

  for (int i = 0; i < t; i++) {
    for (int j = 0; j <= n; j++) {

      // Already n people entered the escalator
      if (j == n) {
        dp[i + 1][j] += dp[i][j];
      }

      else {
        // Prob that jth person enters the q
        dp[i + 1][j + 1] += dp[i][j] * p;

        // Prob that jth person doesnt enter the q
        dp[i + 1][j] += dp[i][j] * (1 - p);
      }
    }
  }

  // Expected num of people on escalator after t seconds
  double ans = 0.0;

  for (int j = 0; j <= n; j++)
    ans += (dp[t][j] * j);

  cout << fixed << setprecision(10) << ans << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}