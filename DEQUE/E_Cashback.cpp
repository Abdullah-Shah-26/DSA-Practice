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



==========================
*/

void solve() {
  int n, c;
  cin >> n >> c;

  vll a(n), pref(n + 1, 0);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pref[i + 1] = pref[i] + a[i];
  }

  if (c == 1) {
    cout << 0 << endl;
    return;
  }

  vll dp(n + 1, 0);
  deque<int> dq;

  // dp[i] = min cost to partition first i elements
  for (int i = 1; i <= n; i++) {
    int r = i - 1;

    // Min of last c elements
    while (!dq.empty() && a[r] <= a[dq.back()])
      dq.pop_back();

    dq.push_back(r);

    int l = i - c;

    // Remove elements out of current window
    while (!dq.empty() && dq.front() < l)
      dq.pop_front();

    // Case 1 :
    // Last seg is of len = 1
    dp[i] = dp[i - 1] + a[r];

    // Case 2 :
    // Last seg of of len = c
    if (i >= c) {
      ll windowSum = pref[r + 1] - pref[l];
      ll windowMin = a[dq.front()];
      ll cost = windowSum - windowMin;

      dp[i] = min(dp[i], dp[i - c] + cost);
    }
  }

  cout << dp[n] << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}