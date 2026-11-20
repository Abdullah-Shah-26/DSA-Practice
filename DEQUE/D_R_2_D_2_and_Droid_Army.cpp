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

Monotonic deque for each col to get max element efficiently

Sliding window on rows to get longest consecutive drones (range) we can kill
using atmost k shots

==========================
*/

void solve() {
  int n, m;
  cin >> n >> m;

  ll k;
  cin >> k;

  vvi a(n, vi(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];

  vector<deque<int>> dq(m);
  vi ans(m, 0);

  int l = 0;
  int maxLen = 0;

  for (int r = 0; r < n; r++) {

    // Add row r to every col's dq
    for (int j = 0; j < m; j++) {
      while (!dq[j].empty() && a[dq[j].back()][j] <= a[r][j])
        dq[j].pop_back();

      dq[j].pb(r);
    }

    // sum of max in each col from row l -> r
    ll sum = 0;

    for (int j = 0; j < m; j++)
      sum += a[dq[j].front()][j];

    // Shrink while invalid
    while (sum > k) {

      for (int j = 0; j < m; j++) {
        if (!dq[j].empty() && l == dq[j].front())
          dq[j].pop_front();
      }

      l++;

      sum = 0;
      for (int j = 0; j < m; j++)
        if (!dq[j].empty())
          sum += a[dq[j].front()][j];
    }

    // ans[j] = max of each col from longest valid window of rows [l.r]
    if (r - l + 1 > maxLen) {
      maxLen = r - l + 1;

      for (int j = 0; j < m; j++)
        ans[j] = a[dq[j].front()][j];
    }
  }

  for (int j = 0; j < m; j++)
    cout << ans[j] << (j + 1 == m ? '\n' : ' ');
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}