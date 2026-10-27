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

// Max no of bits
const int B = 30;
const int N = 1e5 + 5;
int pref[B][N][2];
int suff[B][N][2];

void solve() {
  int n;
  cin >> n;

  vi a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  for (int i = 0; i < B; i++) suff[i][n + 1][0] = suff[i][n + 1][1] = 0;

  for (int i = 0; i < B; i++) {
    for (int j = 1; j <= n; j++) {

      // !! converts num to 0 or 1
      int t = !!(a[j] & (1 << i));

      for (int k = 0; k < 2; k++) {
        pref[i][j][k] = (t == k) + pref[i][j - 1][k ^ t];
      }
    }

    for (int j = n; j >= 1; j--) {
      int t = !!(a[j] & (1 << i));

      for (int k = 0; k < 2; k++) {
        suff[i][j][k] = (t == k) + suff[i][j + 1][k ^ t];
      }
    }
  }

  ll ans = 0;

  for (int i = 1; i <= n; i++) {
    // MSB in 0 based idx
    int z = 31 - __builtin_clz(a[i]);

    // The left side must have XOR bit 1. The right side must have XOR bit 0, or
    // be empty. Empty XOR is 0, so we add 1 to the zero-bit coun
    ans += 1LL * pref[z][i - 1][1] * (1 + suff[z][i + 1][0]);

    // Vice versa
    ans += 1LL * (1 + pref[z][i - 1][0]) * suff[z][i + 1][1];
  }

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