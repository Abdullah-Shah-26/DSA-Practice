#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Ordered Set
#define pbds                                   \
  tree<int, null_type, less<int>, rb_tree_tag, \
       tree_order_statistics_node_update>
// order_of_key(k) : No of Elements < k
// *find_by_order(i) : Value at idx i (0 - based)

// ---------- Type aliases ----------
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvpi = vector<vector<pi>>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ---------- Newline helper ----------
inline void nl() { cout << '\n'; }

// ---------- Macros ----------
#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define rm(mat)         \
  for (auto &r : (mat)) \
    for (auto &x : (r)) \
  cin >> x
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)

// ---------- Solve ---------
void solve() {
  ll n;
  cin >> n;
  vi x(n), v(n);
  rv(x);
  rv(v);

  auto check = [&](ld T) {
    ld L = -1e18, R = 1e18;

    rep(i, 0, n) {
      L = max(L, x[i] - v[i] * T);
      R = min(R, x[i] + v[i] * T);
    }
    return L <= R;
  };

  ld l = 0, r = 1e18;
  int it = 100;
  while (it--) {
    ld mid = l + (r - l) / 2;

    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << fixed << setprecision(12) << r << endl;
}

// ---------- Main ----------
int main() {
  solve();
  return 0;
}