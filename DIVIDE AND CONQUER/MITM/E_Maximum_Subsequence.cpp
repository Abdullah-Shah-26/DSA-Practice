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
  ll N, m;
  cin >> N >> m;

  vll a(N);
  rv(a);

  ll n1 = N / 2;
  ll n2 = N - n1;

  vll L, R;

  for (int mask = 0; mask < (1 << n1); mask++) {
    ll sum = 0;

    for (int i = 0; i < n1; i++) {
      if (mask & (1 << i)) {
        sum = (sum + a[i]) % m;
      }
    }

    L.pb(sum);
  }

  for (int mask = 0; mask < (1 << n2); mask++) {
    ll sum = 0;

    for (int i = 0; i < n2; i++) {
      if (mask & (1 << i)) {
        sum = (sum + a[i + n1]) % m;
      }
    }

    R.pb(sum);
  }

  sort(all(R));

  ll ans = 0;

  for(ll x : L){
    // x + y < m
    // y < m - x
    // No wrap around case
    auto it = lower_bound(all(R), m - x);

    if(it != R.begin()){
      --it;
      ans = max(ans, x + *it);
    }

    // Max using wrap around 
    ans = max(ans, (x + R.back()) % m);
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