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
  ll n, k;
  cin >> n >> k;

  vll a(n);
  rv(a);

  sort(all(a));

  ll low = a[n / 2];
  ll high = a[n - 1] + k;
  ll ans = low;

  auto check = [&](ll x) {
    ll cost = 0;

    for (int i = n / 2; i < n; i++) {
      if (a[i] < x) {
        cost += abs(x - a[i]);

        if (cost > k)
          return false;
      }
    }

    return cost <= k;
  };

  while (low <= high) {
    ll mid = low + (high - low) / 2;

    if (check(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
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