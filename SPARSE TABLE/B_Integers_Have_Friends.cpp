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

m divides x
m divides y
x mod m = y mod m
(x - y) mod m == 0
m divides (x - y)

==========================
*/

const int LOG = 20;

struct SparseTable {
  int n;
  vvll st;

  SparseTable(vll &a) {
    n = (int)a.size();
    st.assign(LOG, vll(n));

    // GCD of intervals of len = 1
    for (int i = 0; i < n; i++)
      st[0][i] = a[i];

    // Each level combines two adjacent intervals of len 2^(j - 1) to form an
    // interval of len 2^j
    for (int j = 1; j < LOG; j++) {
      for (int i = 0; i + (1 << j) <= n; i++) {
        st[j][i] = gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  // GCD of range [l,r] both inclusive
  ll query(int l, int r) {

    // Position of largest set bit from right
    // So that we can find largest power of 2 not exceeding query len
    int k = 31 - __builtin_clz(r - l + 1);

    // Combines 2 overlapping intervals of len = 2^k
    return gcd(st[k][l], st[k][r - (1 << k) + 1]);
  }
};

void solve() {
  int n;
  cin >> n;

  vll a(n);
  rv(a);

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  // diff array
  vll d(n - 1);
  for (int i = 0; i < n - 1; i++)
    d[i] = abs(a[i + 1] - a[i]);

  SparseTable st(d);

  // Largest subarr with gcd > 1
  int ans = 1;

  for (int l = 0; l < d.size(); l++) {
    int low = l, high = d.size() - 1;
    int bestr = l - 1;

    while (low <= high) {
      int mid = (low + high) >> 1;

      // Once gcd becomes 1 it can never become > 1
      if (st.query(l, mid) > 1) {
        bestr = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    // +1 extra to convert diff arr len to interval len
    ans = max(ans, bestr - l + 2);
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