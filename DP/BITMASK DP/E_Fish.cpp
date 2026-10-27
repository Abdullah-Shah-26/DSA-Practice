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

dp[mask] = probability that exactly the fishes in mask are alive

Initially all fishes are alive:
dp[(1 << n) - 1] = 1

k = number of alive fishes in mask

kC2 = k * (k - 1) / 2
    = number of pairs that can meet

Probability that a particular pair (i, j) meets = 1 / kC2

If fish i eats fish j:
new mask = mask ^ (1 << j)

Probability contributed to the new state:
dp[mask] * a[i][j] / kC2

If fish j eats fish i:
new mask = mask ^ (1 << i)

Probability contributed to the new state:
dp[mask] * a[j][i] / kC2

Process masks in descending order because every transition
removes one fish and produces a smaller mask.

Final answer:
dp[1 << i] = probability that fish i is the last survivor.

==========================
*/

void solve() {
  int n;
  cin >> n;

  vector<vector<double>> mat(n, vector<double>(n));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> mat[i][j];

  int total = (1 << n);

  vector<double> dp(total, 0.0);
  dp[total - 1] = 1.0;

  for (int mask = total - 1; mask >= 1; mask--) {

    // No of fishes that are alive
    int k = __builtin_popcount(mask);

    if (k < 2)
      continue;

    // Each guy can pair with every other guy left
    double pairs = k * (k - 1) / 2.0;

    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i)))
        continue;

      for (int j = i + 1; j < n; j++) {
        if (!(mask & (1 << j)))
          continue;

        // Both i,j are in mask (means they are alive)

        // Prob that i kills j
        // J becomes dead, so toggle it off in mask
        dp[mask ^ (1 << j)] += dp[mask] * mat[i][j] / pairs;

        // Prob that j kills i
        // I becomes dead
        dp[mask ^ (1 << i)] += dp[mask] * mat[j][i] / pairs;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << fixed << setprecision(6) << dp[1 << i] << " ";
  }

  cout << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}