#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
const ll LINF = 1e18;
const int MOD = 998244353;

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
#define rm(mat)         \
  for (auto &r : (mat)) \
    for (auto &x : (r)) \
  cin >> x
#define pm(mat)                   \
  do {                            \
    for (const auto &r : (mat)) { \
      for (const auto &x : (r))   \
        cout << x << ' ';         \
      cout << '\n';               \
    }                             \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================
Question
--------------------------


Problem Statement

Find, modulo 998244353, the number of integers x with 1≤x≤N that satisfy exactly
one of the following three conditions.

    x is a multiple of 3.
    The decimal representation of x contains 3.
    Exactly three different digits are used in the decimal representation of x.

Here, the decimal representation of an integer should not have unnecessary
leading 0s. Constraints

    N is an integer.
    1≤N<10500

Input

The input is given from Standard Input in the following format:

N

Output

Output the answer.
Sample Input 1
Copy

45

Sample Output 1
Copy

19

Among the integers from 1 to 45, there are 19 integers satisfying exactly one of
the conditions in the problem statement, as follows.

    There are 10 integers satisfying only the first condition:
6,9,12,15,18,21,24,27,42,45. There are 9 integers satisfying only the second
condition: 13,23,31,32,34,35,37,38,43. There are no integers satisfying only the
third condition.


==========================
*/

/*

dp[pos][tight][lz][rem][has3][mask]

pos   : 500 digits, 501
tight : 0/1
lz    : 0/1
rem   : curNo % 3
        [0,1,2]
has3  : 0/1
        whether digit 3 appered
mask  : which digit  (0-9) have been used
      : 10 digits - (1 << 10) = 1024 masks

*/

ll dp[501][2][2][3][2][1 << 10];

ll f(string &s, int i, bool tight, bool lz, int rem, bool has3, int mask) {

  if (i == (int)s.size()) {
    if (lz)
      return 0;

    // Need exactly one cond'n to be true

    bool c1 = (rem == 0);                      // multiple of 3
    bool c2 = has3;                            // contains dig 3
    bool c3 = (__builtin_popcount(mask) == 3); // exactly 3 distinct digits

    return (c1 + c2 + c3) == 1;
  }

  ll &ans = dp[i][tight][lz][rem][has3][mask];

  if (ans != -1)
    return ans;

  ans = 0;

  int ub = tight ? s[i] - '0' : 9;

  for (int d = 0; d <= ub; d++) {
    int nT = tight && (d == ub);

    // still leading zeros
    if (lz && d == 0) {
      ans += f(s, i + 1, nT, 1, 0, 0, 0);
    } else {
      int nRem = (rem * 10 + d) % 3;
      bool nHas3 = has3 || (d == 3);
      int nMask = mask | (1 << d);

      ans += f(s, i + 1, nT, 0, nRem, nHas3, nMask);
    }

    ans %= MOD;
  }

  return ans;
}

void solve() {
  string s;
  cin >> s;
  int n = s.size();

  memset(dp, -1, sizeof(dp));

  cout << f(s, 0, 1, 1, 0, 0, 0) << endl;
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}