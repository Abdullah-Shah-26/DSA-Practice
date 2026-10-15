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

class Fenwick {
 private:
  int n;
  vector<ll> bit;

 public:
  Fenwick(int n) {
    this->n = n;
    bit.assign(n + 1, 0);
  }

  void update(int idx, ll val) {
    while (idx <= n) {
      bit[idx] += val;
      idx += idx & -idx;
    }
  }

  ll query(int idx) {
    ll sum = 0;

    while (idx > 0) {
      sum += bit[idx];
      idx -= idx & -idx;
    }

    return sum;
  }

  ll rangeQuery(int left, int right) {
    if (left > right) return 0;

    return query(right) - (left ? query(left - 1) : 0);
  }
};

void solve() {
  ll n, t;
  cin >> n >> t;

  vll a(n);
  rv(a);

  vll pref(n + 1, 0);

  for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i - 1];

  // Co-ordinate compress
  vll vals = pref;
  sort(all(vals));
  vals.erase(unique(all(vals)), vals.end());

  int m = vals.size();

  Fenwick ft(m + 1);

  auto getId = [&](ll x) {
    // +1 cause fenwick is 1 based
    return lower_bound(all(vals), x) - begin(vals) + 1;
  };

  ll inserted = 0;

  // Insert first pref inside ft
  pref[0] = 0;
  int pos = getId(pref[0]);
  ft.update(pos, 1);
  inserted++;

  ll ans = 0;

  // pref[j] - pref[i] < t
  // pref[i] > pref[j] - t

  for (int j = 1; j <= n; j++) {
    ll x = pref[j] - t;

    // Cnt of prev pref sums <= x
    int id = upper_bound(all(vals), x) - begin(vals);
    int cnt = ft.query(id);

    // Cnt of prev pref sums > x
    ans += inserted - cnt;

    int pos = getId(pref[j]);
    ft.update(pos, 1);

    inserted++;
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