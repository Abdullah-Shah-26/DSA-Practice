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

1. DP State:

dp[n][x] = Probability that Jon has exactly x distinct orbs after n days.

2. Base Case:

dp[0][0] = 1

Initially, Jon has zero distinct orbs with probability 1.

3. Transitions:

From state (n, x):

Case 1: Pick an existing orb.
There are x existing orbs out of k.

dp[n + 1][x] += dp[n][x] * (x / k)

Case 2: Pick a new orb.
There are k - x new orbs out of k.

dp[n + 1][x + 1] += dp[n][x] * ((k - x) / k)

4. Recurrence:

dp[n + 1][x] = dp[n][x] * (x / k) + dp[n][x - 1] * ((k - x + 1) / k)

5. Final Answer:

For each query pi, find the minimum n satisfying:
dp[n][k] >= (pi - EPS)/2000

Because the required probability is (pi - EPS) / 2000.

6. Complexity:

TC: O(D * k)
SC: O(D * k)

D = Maximum number of days calculated.

==========================
*/

const int N = 1005;
const double eps = 1e-7; // 1 * 10pow(-7)

double dp[N];
int ans[N];

// Space Optimized : In place 

void solve() {
  int k, q, pi = 1;
  cin >> k >> q;

  dp[0] = 1;
  for (int n = 1; pi <= 1000; n++) {
    for (int x = k; x > 0; x--)
      dp[x] = (x * dp[x] + (k - x + 1) * dp[x - 1]) / k;

    while (pi <= 1000 && dp[k] >= (pi - eps) / 2000) {
      ans[pi] = n;
      pi++;
    }
    dp[0] = 0; // dp[0] is 1 only for first itr
  }

  while (q--) {
    int x;
    cin >> x;
    cout << ans[x] << endl;
  }
}

int main() {

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}