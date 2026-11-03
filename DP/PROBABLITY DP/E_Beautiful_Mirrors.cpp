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
const int MOD = 998244353;

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

E[i] = expected rem days starting at mirror i

Final Eq : 
E[i] = 1 + p[i] * E[i + 1] + (1 - p[i]) * E1

==========================
*/

ll power(ll a, ll b) {
  ll ans = 1;

  while (b > 0) {
    if (b & 1)
      ans = ans * a % MOD;

    b >>= 1;
    a = a * a % MOD;
  }

  return ans;
}

ll inv(ll x) { return power(x, MOD - 2) % MOD; }

void solve() {
  int n;
  cin >> n;

  ll ans = 0;
  vll p(n);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x; // p[i] = x / 100
    p[i] = x * inv(100) % MOD;
  }

  ll prod = 1;
  for (int i = n - 1; i >= 0; i--) {
    prod = prod * p[i] % MOD;
    ans = (ans + inv(prod)) % MOD;
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