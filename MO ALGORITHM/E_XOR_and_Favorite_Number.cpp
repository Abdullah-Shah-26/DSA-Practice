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
  int n, m;
  ll k;
  cin >> n >> m >> k;

  vll a(n);
  rv(a);

  // pref xor
  vll pref(n + 1, 0);

  for (int i = 1; i <= n; i++)
    pref[i] = pref[i - 1] ^ a[i - 1];

  // [l, r, idx]
  vector<array<int, 3>> queries(m);

  for (int i = 0; i < m; i++) {

    // [l, r]
    cin >> queries[i][0] >> queries[i][1];

    // For pref xor we need [l - 1, r] = pref[r] xor pref[l - 1]
    queries[i][0]--;
    queries[i][2] = i;
  }

  int B = max(1, (int)sqrt(n));

  sort(all(queries), [&](auto &a, auto &b) {
    auto [aL, aR, i1] = a;
    auto [bL, bR, i2] = b;

    int x = aL / B;
    int y = bL / B;

    // Different block no
    // Smaller block no first
    if (x != y)
      return x < y;

    // Same block no
    // Smaller R comes first
    return aR < bR;
  });

  vll freq(1 << 20, 0);
  ll cnt = 0;

  int L = 0, R = -1;
  vll ans(m, 0);

  auto add = [&](ll x) {
    cnt += freq[x ^ k];
    freq[x]++;
  };

  auto remove = [&](ll x) {
    freq[x]--;
    cnt -= freq[x ^ k];
  };

  for (int i = 0; i < m; i++) {
    auto [l, r, idx] = queries[i];

    // Expand
    while (L > l) {
      L--;
      add(pref[L]);
    }

    while (R < r) {
      R++;
      add(pref[R]);
    }

    // Shrink
    while (L < l) {
      remove(pref[L]);
      L++;
    }

    while (R > r) {
      remove(pref[R]);
      R--;
    }

    ans[idx] = cnt;
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
