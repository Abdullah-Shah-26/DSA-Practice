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

const int N = 1e6;

int divisors[N];

void precompute() {
  for (ll i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divisors[j]++;
    }
  }
}

class SegTree {
 public:
  int n;
  vll sum;
  vi mx;

  SegTree(vll& a) {
    this->n = (int)a.size();
    sum.resize(4 * n);
    mx.resize(4 * n);

    build(1, 0, n - 1, a);
  }

  void build(int i, int l, int r, vll& a) {
    if (l == r) {
      mx[i] = sum[i] = a[l];
      return;
    }

    int mid = (l + r) >> 1;

    build(2 * i, l, mid, a);
    build(2 * i + 1, mid + 1, r, a);

    mx[i] = max(mx[2 * i], mx[2 * i + 1]);
    sum[i] = sum[2 * i] + sum[2 * i + 1];
  }

  void update(int i, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return;

    // If max value of a segment or node <= 2
    // Then even if replace it with divisors cnt it remains same
    if (mx[i] <= 2) return;

    // Leaf node
    // a[i] = mx = sum
    if (l == r) {
      int val = divisors[mx[i]];
      mx[i] = val;
      sum[i] = val;
      return;
    }

    int mid = (l + r) >> 1;

    update(2 * i, l, mid, ql, qr);
    update(2 * i + 1, mid + 1, r, ql, qr);

    mx[i] = max(mx[2 * i], mx[2 * i + 1]);
    sum[i] = sum[2 * i] + sum[2 * i + 1];
  }

  ll query(int i, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return 0;

    if (l >= ql && r <= qr) return sum[i];

    int mid = (l + r) >> 1;

    ll L = query(2 * i, l, mid, ql, qr);
    ll R = query(2 * i + 1, mid + 1, r, ql, qr);

    return L + R;
  }

  void update(int l, int r) {
    if (l > r) return;

    return update(1, 0, n - 1, l, r);
  }

  ll query(int l, int r) {
    if (l > r) return 0;

    return query(1, 0, n - 1, l, r);
  }
};

void solve() {
  int n, m;
  cin >> n >> m;

  vll a(n);
  rv(a);

  SegTree seg(a);

  while (m--) {
    int t, l, r;
    cin >> t >> l >> r;

    l--;
    r--;

    if (t == 1) {
      // for (int i = l; i <= r; i++) a[i] = divisors[a[i]];
      seg.update(l, r);

    } else {
      // ll sum = 0;
      // for (int i = l; i <= r; i++) sum += a[i];
      // cout << sum << endl;
      cout << seg.query(l, r) << endl;
    }
  }
}

int main() {
  precompute();

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}