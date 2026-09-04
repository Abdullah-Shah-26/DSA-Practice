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

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a) \
  for (auto& x : (a)) cin >> x
#define pv(a)                                   \
  do {                                          \
    for (const auto& x : (a)) cout << x << ' '; \
    cout << '\n';                               \
  } while (0)
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

class SparseTable {
  int n, LOG;
  vvi st;

 public:
  SparseTable(vi& a) {
    n = a.size() - 1;  // array is 1 based

    LOG = 1;
    while ((1 << LOG) <= n) LOG++;

    st.assign(n + 1, vi(LOG));

    // Level 0 : range of size = 1
    for (int i = 1; i <= n; i++) st[i][0] = a[i];

    // Ranges of size 2, 4, 8, ...
    for (int j = 1; j < LOG; j++) {
      // Len of each block = 2^j
      // [i... i + (1 << j) - 1]
      int len = (1 << j);

      for (int i = 1; i + len - 1 <= n; i++) {
        int half = (1 << (j - 1));

        st[i][j] = max(st[i][j - 1], st[i + half][j - 1]);
      }
    }
  }

  int query(int l, int r) {
    int len = r - l + 1;

    int j = 0;

    // Check if we can increase j by 1 more level
    while ((1 << (j + 1)) <= len) {
      j++;
    }

    int block = (1 << j);

    return max(st[l][j], st[r - block + 1][j]);
  }
};

void solve() {
  ll n;
  int m, q, k;

  cin >> n >> m;

  // a[i] = x rows in the ith col from bottom are blocked
  // The rows are numbered from bottom to top
  // So the next available row for this col = (x + 1)

  vi a(m + 1);
  for (int i = 1; i <= m; i++) cin >> a[i];

  SparseTable sp(a);

  cin >> q;

  while (q--) {
    ll xs, ys, xf, yf;
    cin >> xs >> ys >> xf >> yf >> k;

    // Can we reach the dest ? Can only jumps of size k
    if (abs(xf - xs) % k != 0 || abs(yf - ys) % k != 0) {
      cout << "NO" << endl;
      continue;
    }

    // Highest row reachable from xs using jumps of size k
    ll xMax = xs + ((n - xs) / k) * k;

    // All cols from ys to yf must be clear
    int l = min(ys, yf);
    int r = max(ys, yf);

    int tallestObstacle = sp.query(l, r);

    if (xMax > tallestObstacle)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}