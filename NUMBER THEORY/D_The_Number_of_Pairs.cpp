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

const int N = 20000000;

// Cnt of distinct prime factors of every number
ll cnt[N + 1];

void precompute() {
  for (int p = 2; p <= N; p++) {
    if (cnt[p] != 0)
      continue;

    for (int j = p; j <= N; j += p) {
      cnt[j]++;
    }
  }
}

void solve() {
  ll c, d, x;
  cin >> c >> d >> x;

  ll ans = 0;

  auto process = [&](ll g) {
    ll num = x / g + d;

    if (num % c != 0)
      return;

    ll k = num / c;

    ans += (1LL << cnt[k]);
  };

  for (ll g = 1; g * g <= x; g++) {
    if (x % g != 0)
      continue;

    process(g);

    if (g != x / g)
      process(x / g);
  }

  cout << ans << endl;
}

int main() {
  precompute();

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}