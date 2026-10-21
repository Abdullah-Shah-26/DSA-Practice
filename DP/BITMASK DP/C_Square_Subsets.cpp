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

Given an array, count the non-empty subsets whose product is a perfect square.

36 = 2^2 * 3^2
36 = 6*6

prime exponents must be even

exp odd = 1
exp even = 0

so xor 

combined xor mask == 0 
no is a perfect square
==========================
*/

void solve() {
  int n;
  cin >> n;

  vi freq(71, 0);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    freq[x]++;
  }

  vector<int> primes = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

  vi mask(71, 0);

  for (int x = 1; x <= 70; x++) {
    int val = x;

    for (int j = 0; j < 19; j++) {
      int exponent = 0;

      while (val % primes[j] == 0) {
        val /= primes[j];
        exponent++;
      }

      if (exponent & 1)
        mask[x] |= (1 << j);
    }
  }

  vll pow2(n + 1, 1);

  for (int i = 1; i <= n; i++)
    pow2[i] = pow2[i - 1] * 2 % MOD;

  vll dp(1 << 19, 0);
  vll ndp(1 << 19, 0);

  // dp[s] = ways to select processed elements with xor = s

  dp[0] = 1;

  for (int x = 1; x <= 70; x++) {
    int c = freq[x];

    if(c == 0)
      continue;

    int m = mask[x];

    // Ways to choose all occurences = 2^c
    // Even occ = odd occ = half = 2^c/2 = 2^(c - 1)
    // Even selections make xor = 0
    ll ways = pow2[c - 1];

    for (int s = 0; s < (1 << 19); s++)
      ndp[s] = ways * ((dp[s] + dp[s ^ m]) % MOD) % MOD;

    dp.swap(ndp);
  }

  // -1 to remove empty subset
  cout << (dp[0] - 1 + MOD) % MOD << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}