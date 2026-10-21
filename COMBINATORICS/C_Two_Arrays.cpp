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

const int MAXN = 1025;

ll fact[MAXN], invFact[MAXN];

/*
==========================



==========================
*/

ll binExpo(ll a, ll b) {
  ll ans = 1;

  while (b) {
    if (b & 1)
      ans = ans * a % MOD;

    a = a * a % MOD;
    b >>= 1;
  }

  return ans;
}

void solve() {
  ll n, m;
  cin >> n >> m;

  ll N = n + 2 * m - 1;

  fact[0] = 1;
  for (ll i = 1; i <= N; i++)
    fact[i] = fact[i - 1] * i % MOD;

  invFact[N] = binExpo(fact[N], MOD - 2);
  for (int i = N; i >= 1; i--)
    invFact[i - 1] = invFact[i] * (i) % MOD;

  // (2*m + n - 1) C (n - 1)

  ll ans = fact[N] * invFact[n - 1] % MOD * invFact[2 * m] % MOD;

  cout << ans << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}