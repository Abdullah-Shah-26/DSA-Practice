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



==========================
*/

void solve() {
  int n, s, len;
  cin >> n >> s >> len;

  vll a(n);
  rv(a);

  vi g(n), dp(n + 1, INF);
  deque<int> mn, mx;

  int l = 0;
  for (int r = 0; r < n; r++) {
    while (!mn.empty() && a[mn.back()] >= a[r]) mn.pop_back();
    mn.pb(r);

    while (!mx.empty() && a[mx.back()] <= a[r]) mx.pop_back();
    mx.pb(r);

    while (a[mx.front()] - a[mn.front()] > s) {
      if (l == mx.front()) mx.pop_front();
      if (l == mn.front()) mn.pop_front();
      l++;
    }

    g[r] = r - l + 1;
  }

  // g[r] = len of longest valid subarr ending at r

  dp[0] = 0;
  deque<int> dq;  // To get min dp[k] among all prev states

  for (int i = 1; i <= n; i++) {
    // Add new valid states
    int k = i - len;

    if (k >= 0 && dp[k] != INF) {
      while (!dq.empty() && dp[dq.back()] >= dp[k]) dq.pop_back();

      dq.push_back(k);
    }

    // Remove states outsize of valid range
    int L = i - g[i - 1];

    while (!dq.empty() && dq.front() < L) dq.pop_front();

    // Ans + 1 cause we are adding new piece
    if (!dq.empty()) dp[i] = dp[dq.front()] + 1;
  }

  if (dp[n] == INF)
    cout << -1 << endl;
  else
    cout << dp[n] << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}