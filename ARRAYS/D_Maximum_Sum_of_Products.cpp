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
  int n;
  cin >> n;

  vll a, b;

  a.resize(n);
  b.resize(n);

  rv(a);
  rv(b);

  vll pref(n + 1, 0);
  for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i] * b[i];

  ll ans = pref[n];

  // pref[i] = sum[0...i - 1]
  // pref[l] = sum[0...l - 1]
  // pref[r + 1] = sum[0....r]

  for (int c = 0; c < n; c++) {
    // Odd center
    ll cur = a[c] * b[c];

    for (int l = c - 1, r = c + 1; l >= 0 && r < n; l--, r++) {
      // before : a[l] * b[l]
      // before : a[r] * b[r]
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ans = max(ans, pref[l] + cur + (pref[n] - pref[r + 1]));
    }

    // Even center
    cur = 0;
    for (int l = c, r = c + 1; l >= 0 && r < n; l--, r++) {
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ans = max(ans, pref[l] + cur + (pref[n] - pref[r + 1]));
    }
  }

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}