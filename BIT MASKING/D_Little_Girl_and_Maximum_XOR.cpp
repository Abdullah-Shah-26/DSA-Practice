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

One the highest differing bit is k
We can achieve any xor from k to 0, all set to 1

Xor is max when highest possible bit differ and we want lower bits to differ as much as possible

==========================
*/

void solve() {
  ll l, r;
  cin >> l >> r;

  // MSB to LSB, the first bit where l, r differ
  int k = -1;

  for (int i = 60; i >= 0; i--) {
    if (((l >> i) & 1LL) != ((r >> i) & 1LL)) {
      k = i;
      break;
    }
  }

  cout << ((1LL << (k + 1)) - 1) << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}