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
  int n, m;
  cin >> n >> m;

  vi cnt(m + 1);
  vi a;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.pb(x);

    if (x <= m) {
      cnt[x]++;
    }
  }

  vvi divisors(m + 1);

  for (int i = 1; i <= m; i++)
    for (int j = i; j <= m; j += i)
      divisors[j].pb(i);

  // Best LCM that forms Longest Subsequence
  int bestL = 1;
  vi ans(m + 1);

  for (int l = 1; l <= m; l++) {
    for (int d : divisors[l]) {
      ans[l] += cnt[d];
    }

    if (ans[l] > ans[bestL])
      bestL = l;
  }

  cout << bestL << " " << ans[bestL] << endl;

  for (int i = 0; i < n; i++)
    if (a[i] <= m && bestL % a[i] == 0)
      cout << i + 1 << " ";

  cout << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}