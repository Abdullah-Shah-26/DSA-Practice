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
  int n, q;
  cin >> n >> q;

  vi a(n);
  rv(a);

  int B = max(1, (int)sqrt(n));
  vector<array<int, 3>> queries(q);

  for (int i = 0; i < q; i++) {
    cin >> queries[i][0] >> queries[i][1];
    queries[i][0]--;
    queries[i][1]--;
    queries[i][2] = i;
  }

  sort(begin(queries), end(queries), [&](auto &a, auto &b) {
    auto [aL, aR, i1] = a;
    auto [bL, bR, i2] = b;

    // Block no's
    int x = aL / B;
    int y = bL / B;

    // Different blocks
    // Query with smaller block no first
    if (x != y)
      return x < y;

    // Same block
    // Query with smaller R first
    return aR < bR;
  });

  vi freq(n + 1, 0);

  // cntFreq[x] = how many distinct values occur x times

  // mx = max freq
  // cntFreq[mx] = cnt of distinct values with max freq

  vi cntFreq(n + 1, 0);
  vi ans(q);

  int L = 0, R = -1, mx = 0;

  auto add = [&](int x) {
    // Remove old contribution
    cntFreq[freq[x]]--;

    freq[x]++;

    // Add new contribution
    cntFreq[freq[x]]++;

    mx = max(mx, freq[x]);
  };

  auto remove = [&](int x) {
    cntFreq[freq[x]]--;

    freq[x]--;

    cntFreq[freq[x]]++;

    if (cntFreq[mx] == 0)
      mx--;
  };

  for (auto [l, r, idx] : queries) {

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

    int len = r - l + 1;
    ans[idx] = max(1, 2 * mx - len);
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