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

// phi(n) = cnt of integers in range [1,n] coprime to n

ll phi(ll n) {
  ll ans = n;

  for (ll p = 2; p * p <= n; p++) {
    if (n % p == 0) {
      // p = prime factor of n
      // Every multiple of p shares a common factor with n
      // So those multiples can't be coprime to n
      // So we remove all their contribution from ans

      ans -= ans / p;

      // Removing all occurences of this prime factor from n
      // Since we need to process all distinct prime factors once
      while (n % p == 0) n /= p;
    }
  }

  // Handles 1 remaining prime factor
  // Ex : 14 = 2 * 7
  // 2 processed in above loop but not 7
  if (n > 1) {
    ans -= ans / n;
  }

  return ans;
}

void solve() {
  ll a, m;
  cin >> a >> m;

  ll g = gcd(a, m);

  // Since g divides both a and m:
  // (i.e (a, m) are multiple of g)
  // a = g * a' and m = g * m'

  // Need gcd(a + x, m) == g
  // Then x must also be divisible by g.
  // So let x = g * k.

  // Original constraint: 0 <= x < m
  // Substituting x = g * k:
  // 0 <= g * k < m
  // Dividing by g:
  // 0 <= k < m / g

  // Now the GCD condition becomes:
  // gcd(a / g + k, m / g) = 1

  // k ranges from 0 to (m / g) - 1.
  // Therefore, (a / g + k) gives exactly (m / g) consecutive integers.

  // Any n consecutive integers have every remainder modulo n exactly once.
  // So these numbers have the same set of remainders as [1, m / g].

  // GCD depends only on the remainder modulo m / g.
  // Therefore, the number of values coprime to m / g
  // is the same as the count in [1, m / g].

  // Euler's Totient phi(n) counts integers in [1, n] coprime to n.
  // Hence, answer = phi(m / g).

  cout << phi(m / g) << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}