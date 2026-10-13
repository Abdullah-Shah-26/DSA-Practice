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

const ll INF = 4e18;
const ll LINF = 4e18;
const ll MOD = 1e9 + 7;

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

Every unblocked segment sum <= mid
Sum of all blocked elements <= mid

Assume we decide to block a[i] and previous elemeent was blocked at j, then the
segment in b/w must satisfy

  a[j + 1] + ...... a[i - 1] <= mid

And blocked sums becomes

  dp[i] = dp[j] + a[i]

dp[i] = min blocked sum when i is blocked and all segments before it are valid

==========================
*/

void solve() {
  int n;
  cin >> n;

  // Blocking the last element
  // Checking the final segment after last blocked element
  // To handle this use sential 0 in input
  vll a(n + 1);
  ll high = 0;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    high += a[i];
  }

  vll pref(n + 2);
  for (int i = 0; i <= n; i++) pref[i + 1] = pref[i] + a[i];

  vll dp(n + 3);
  ll low = 1, ans = n;

  function<bool(ll)> check = [&](ll mid) -> bool {
    dp[0] = 0;

    deque<int> dq;

    for (int i = 0; i <= n; i++) {
      while (!dq.empty() && dp[dq.back()] >= dp[i]) dq.pop_back();

      dq.push_back(i);

      while (pref[i] - pref[dq.front()] > mid) dq.pop_front();

      dp[i + 1] = dp[dq.front()] + a[i];
    }

    return dp[n + 1] <= mid;
  };

  while (low <= high) {
    ll mid = low + (high - low) / 2;

    if (check(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
