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

ll binExpo(ll a, ll b) {
  ll ans = 1;

  while (b) {
    if (b & 1)
      ans = ans * a % MOD;

    a = a % MOD * a % MOD;
    b >>= 1;
  }

  return ans;
}

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  ll S = 0;

  for (int i = 0; i < m; i++) {
    ll a, b, f;
    cin >> a >> b >> f;

    S = (S + f) % MOD;
  }

  // nC2
  ll T = n * (n - 1) / 2;

  // kC2
  ll K = k * (k - 1) / 2;

  // 1/nC2
  ll invT = binExpo(T, MOD - 2);

  // k * s / nC2
  ll term1 = ((k * S) % MOD * (invT % MOD)) % MOD;

  // m * kC2 / (nC2)^2
  ll term2 = ((m % MOD) * K % MOD) % MOD * invT % MOD * invT % MOD;

  ll ans = (term1 + term2) % MOD;

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