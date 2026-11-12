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
  int n, k;
  cin >> n >> k;

  vi a(n);
  rv(a);

  auto check = [&](int x) -> bool {
    vi pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + (a[i - 1] >= x ? 1 : -1);
    }

    int mn = 0;
    for (int r = k; r <= n; r++) {
      mn = min(mn, pref[r - k]);

      if (pref[r] > mn) {
        return true;
      }
    }

    return false;
  };

  int low = 1, high = n;
  int ans = 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

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