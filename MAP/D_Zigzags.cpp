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

  vll a(n);
  rv(a);

  ll ans = 0;

  // for (int i = 0; i < n; i++) {
  //   for (int j = i + 1; j < n; j++) {
  //     for (int k = j + 1; k < n; k++) {
  //       for (int l = k + 1; l < n; l++) {
  //         if (a[i] == a[k] && a[j] == a[l]) cnt++;
  //       }
  //     }
  //   }
  // }

  map<ll, ll> left, right;

  // left = occ of a[k] before l
  // right = occ of a[j] after k

  for (ll x : a) right[x]++;

  for (int j = 0; j < n; j++) {
    right[a[j]]--;  // Now right contains indices > j

    for (int k = j + 1; k < n; k++) {
      right[a[k]]--;  // Now right contains indices > k

      // i.e right contains occ of a[j] after k
      ans += left[a[k]] * right[a[j]];
    }

    for (int k = j + 1; k < n; k++) right[a[k]]++;

    // So we add this before we go to next j
    // So left contains indices before cur j
    left[a[j]]++;
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