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

x + y + z = n
max(1, x) = min(x + 1, x + y) = max(x + y + 1, n)

==========================
*/

const int LOG = 20;

// st[i][j] = min subarr starting at i with len pow(2, j)

class SparseTable {
 public:
  int n;
  vvll st;

  SparseTable(vll& a) {
    n = a.size();

    st.assign(n, vll(LOG));

    for (int i = 0; i < n; i++) st[i][0] = a[i];

    for (int j = 1; j < LOG; j++)
      for (int i = 0; i + (1 << j) <= n; i++)
        st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
  }

  ll query(int l, int r) {
    int k = __lg(r - l + 1);

    return min(st[l][k], st[r - (1 << k) + 1][k]);
  }
};

void solve() {
  int n;
  cin >> n;

  vll a(n);
  rv(a);

  SparseTable st(a);

  vll pref(n + 1, -LINF), suff(n + 1, -LINF);

  for (int i = 0; i < n; i++) pref[i + 1] = max(pref[i], a[i]);
  for (int i = n - 1; i >= 0; i--) suff[i] = max(suff[i + 1], a[i]);

  // left : [0, i - 1]
  // middle : [i, j - 1]
  // right : [j, n - 1]
  for (int i = 1; i < n - 1; i++) {
    ll mx = pref[i];

    // Middle part must be non empty, so j = i + 1 to .. some valid idx where suffmx == mx
    int L = lower_bound(suff.begin() + i + 1, suff.end(), mx, greater<ll>()) -
            suff.begin();

    int R = upper_bound(suff.begin() + i + 1, suff.end(), mx, greater<ll>()) -
            suff.begin();

    // for (int j = L; j < R; j++) {
    //   if (st.query(i, j - 1) == mx) {
    //     YES;
    //     cout << i << " " << j - i << " " << n - j << endl;
    //     return;
    //   }

    int low = L, high = R - 1;
    int ans = -1;

    // Left end pt of middle = i (fixed)
    // Need right end pt of middle = j such that given condition satisfies
    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (st.query(i, mid - 1) <= mx) {
        if (st.query(i, mid - 1) == mx) ans = mid;

        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    if (ans != -1) {
      YES;
      cout << i << " " << ans - i << " " << n - ans << endl;
      return;
    }
  }

  NO;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}