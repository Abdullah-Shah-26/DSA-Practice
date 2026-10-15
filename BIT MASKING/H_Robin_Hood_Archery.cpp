#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
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

int main() {
  const int N = 1000000;

  // Randomized xor hashing
  // To avoid false +ve's like for ex : 
  // 1 2 3 
  // xor 1 ^ 2 ^ 3 = 0
  // But the values dont occur even times even though we get xor = 0


  vector<ull> mask(N + 1);
  std::mt19937_64 rng((unsigned)chrono::high_resolution_clock::now()
                          .time_since_epoch()
                          .count());

  // Randon hash per value
  for (int i = 1; i <= N; i++) mask[i] = rng();

  int t = 1;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<ull> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] ^ mask[a[i]];

    while (q--) {
      int l, r;
      cin >> l >> r;

      ull x = pref[r] ^ pref[l - 1];

      // x == 0, every value appears even times
      // This makes sure sherrif donest lose, cause sherrif can mirror Robin's choices
      if (x == 0)
        YES;
      else
        NO;
    }
  }

  return 0;
}