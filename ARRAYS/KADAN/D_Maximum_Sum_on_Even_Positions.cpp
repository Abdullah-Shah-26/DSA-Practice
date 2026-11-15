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

ll kadan(vll& a) {
  ll cur = 0, maxsum = 0;

  for (ll x : a) {
    cur = max(0LL, cur + x);
    maxsum = max(maxsum, cur);
  }

  return maxsum;
}

void solve() {
  int n;
  cin >> n;

  vll a(n);
  rv(a);

  ll sum = 0;
  for (int i = 0; i < n; i += 2) sum += a[i];

  vll v1, v2;

  for (int i = 0; i + 1 < n; i += 2) v1.pb(a[i + 1] - a[i]);  // (0, 1) (2, 3)

  for (int i = 1; i + 1 < n; i += 2) v2.pb(a[i] - a[i+1]);  // (1, 2) (3, 4)

  ll ans = sum + max(kadan(v1), kadan(v2));

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