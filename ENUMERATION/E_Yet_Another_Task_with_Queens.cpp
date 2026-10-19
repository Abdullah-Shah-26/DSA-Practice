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

  vpii queens(m);
  vi w(m, 0), t(9, 0);

  for (int i = 0; i < m; i++)
    cin >> queens[i].first >> queens[i].second;

  auto process = [&](int type) {
    vector<tuple<int, int, int>> v;

    for (int i = 0; i < m; i++) {
      auto [r, c] = queens[i];
      int key, pos;

      if (type == 0) {
        key = r;
        pos = c;
      } else if (type == 1) {
        key = c;
        pos = r;
      } else if (type == 2) {
        key = r - c;
        pos = r;
      } else {
        key = r + c;
        pos = r;
      }

      v.emplace_back(key, pos, i);
    }

    sort(all(v));

    for (int i = 1; i < m; i++) {
      auto [key1, r1, i1] = v[i - 1];
      auto [key2, r2, i2] = v[i];

      // Both attack each other
      if (key1 == key2) {
        w[i1]++;
        w[i2]++;
      }
    }
  };

  for (int t = 0; t < 4; t++)
    process(t);

  for (int attacks : w)
    t[attacks]++;

  for (int i = 0; i <= 8; i++)
    cout << t[i] << ' ';

  cout << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}