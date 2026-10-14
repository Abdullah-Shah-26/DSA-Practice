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
#define pv(a)                 \
  do {                        \
    for (const auto &x : (a)) \
      cout << x << ' ';       \
    cout << '\n';             \
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

Here :
power = sum of (freq^2 * value) for every distinct value in range

==========================
*/

void solve() {
  int n, t;
  cin >> n >> t;

  vi a(n);
  rv(a);

  // [l, r, idx]
  vector<array<int, 3>> q(t);

  for (int i = 0; i < t; i++) {
    cin >> q[i][0] >> q[i][1];
    q[i][0]--;
    q[i][1]--;
    q[i][2] = i;
  }

  int B = max(1, (int)sqrt(n));

  sort(begin(q), end(q), [&](auto &a, auto &b) {
    auto [aL, aR, i1] = a;
    auto [bL, bR, i2] = b;

    // Block no's
    int x = aL / B;
    int y = bL / B;

    // Different blocks
    // Qry with smaller block no comes first
    if (x != y)
      return x < y;

    // Same block
    // Qry with smaller R comes first
    return aR < bR;
  });

  vll freq(1e6 + 1, 0);
  vll ans(t);

  int L = 0, R = -1;
  ll power = 0;

  auto add = [&](int i) {
    ll x = a[i];

    freq[x]++;

    // Remove old contribution
    // Add new contribution

    ll newC = freq[x] * freq[x] * x;
    ll oldC = (freq[x] - 1) * (freq[x] - 1) * x;

    power += (newC - oldC);
  };

  auto remove = [&](int i) {
    ll x = a[i];

    freq[x]--;

    ll newC = freq[x] * freq[x] * x;
    ll oldC = (freq[x] + 1) * (freq[x] + 1) * x;

    power += (newC - oldC);
  };

  for (auto [l, r, idx] : q) {

    // Expand range
    while (L > l) {
      L--;
      add(L);
    }

    while (R < r) {
      R++;
      add(R);
    }

    // Shrink range
    while (L < l) {
      remove(L);
      L++;
    }

    while (R > r) {
      remove(R);
      R--;
    }

    ans[idx] = power;
  }

  for (ll x : ans)
    cout << x << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}

