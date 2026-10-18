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

void solve() {
  ll n;
  cin >> n;

  vpll segs(n);

  for (auto &[l, r] : segs)
    cin >> l >> r;

  map<ll, ll> diff;

  for (auto [l, r] : segs) {
    diff[l]++;
    diff[r + 1]--;
  }

  vll ans(n + 1);
  ll cover = 0;

  for (auto it = diff.begin(); it != diff.end(); it++) {
    cover += it->second;

    auto nxt = next(it);
    if (nxt == diff.end())
      break;

    ll x = it->first;
    ll nxtX = nxt->first;

    if (cover > 0) {
      ans[cover] += nxtX - x;
    }
  }

  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";

  cout << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}