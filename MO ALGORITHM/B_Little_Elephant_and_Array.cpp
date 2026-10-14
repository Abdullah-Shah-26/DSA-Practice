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

value = x
should occur x times
cnt how many such values exist in the range

A value x > n
can never occur exactly x times

Ex : x = 10, n = 5
10 can never occur 10 times in the array

==========================
*/

void solve() {
  int n, m;
  cin >> n >> m;

  vi a(n);
  rv(a);

  vector<array<int, 3>> queries(m);

  for (int i = 0; i < m; i++) {
    cin >> queries[i][0] >> queries[i][1];
    queries[i][0]--;
    queries[i][1]--;
    queries[i][2] = i;
  }

  int B = max(1, (int)sqrt(n));

  sort(all(queries), [&](auto &a, auto &b) {
    auto [aL, aR, i1] = a;
    auto [bL, bR, i2] = b;

    int x = aL / B;
    int y = bL / B;

    if (x != y)
      return x < y;

    return aR < bR;
  });

  vi ans(m, 0);
  vi freq(n + 1, 0);

  int cnt = 0;

  auto add = [&](int x) {
    if (x > n)
      return;

    // Remove old contribution
    if (freq[x] == x)
      cnt--;

    freq[x]++;

    // Add new contribution
    if (freq[x] == x)
      cnt++;
  };

  auto remove = [&](int x) {
    if (x > n)
      return;

    if (freq[x] == x)
      cnt--;

    freq[x]--;

    if (freq[x] == x)
      cnt++;
  };

  int L = 0, R = -1;

  for (auto [l, r, i] : queries) {

    // Expand
    while (L > l) {
      L--;
      add(a[L]);
    }

    while (R < r) {
      R++;
      add(a[R]);
    }

    // Shrink
    while (L < l) {
      remove(a[L]);
      L++;
    }

    while (R > r) {
      remove(a[R]);
      R--;
    }

    ans[i] = cnt;
  }

  for (auto x : ans)
    cout << x << endl;

  return;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}