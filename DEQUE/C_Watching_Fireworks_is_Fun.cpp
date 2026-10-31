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

n = street sections
m = no of fireworks
dp[x] = max happiness ending at street section x

==========================
*/

void solve() {
  ll n, m, d;
  cin >> n >> m >> d;

  vll a(m + 1), b(m + 1), t(m + 1);
  for (int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> t[i];

  // Happiness accumulated on watching the first firework standing at position = x
  // We can start from any position x initally
  vll dp(n + 1);
  for (int x = 1; x <= n; x++) dp[x] = b[1] - abs(a[1] - x);

  for (int i = 2; i <= m; i++) {
    vll ndp(n + 1, -LINF);

    // Time available = t[i] - t[i - 1]
    // Max dist we can travel = d * (time available)
    // Can be forward or backward
    // k = max num of street sections we can travel b/w 2 consecutive fireworks
    ll k = min(n, d * (t[i] - t[i - 1]));

    // Max prev happiness among reachable positions 
    deque<int> dq;
    int r = 0;

    for (ll x = 1; x <= n; x++) {
      int L = max(1LL, x - k);
      int R = min(n, x + k);

      while (r < R) {
        // Add new element
        r++;

        while (!dq.empty() && dp[dq.back()] <= dp[r]) dq.pop_back();

        dq.push_back(r);
      }

      // Remove elements outside window
      while (!dq.empty() && dq.front() < L) dq.pop_front();

      ll best = dp[dq.front()];

      ndp[x] = best + b[i] - abs(a[i] - x);
    }

    dp = ndp;
  }

  cout << *max_element(all(dp)) << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}