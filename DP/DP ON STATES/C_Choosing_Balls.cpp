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

For each ball (v[i], c[i]) :

- continue same color = dp[c[i]] + a * v[i]

- switch to different color = max(dp[x]) for x != c[i] + b * v[i]

- start new sequence = b * v[i]

==========================
*/

void solve() {
  int n, q;
  cin >> n >> q;

  vll value(n), color(n);
  rv(value);
  rv(color);

  while (q--) {
    ll a, b;
    cin >> a >> b;

    // No of unique colors <= n
    // dp[c] = max score of seq ending with color c

    // A valid seq can have score = 0
    // So we initialize with -LINF to prevent false +ve
    vll dp(n + 1, -LINF);
    ll mx1 = 0, mx2 = 0;
    ll c1 = -1, c2 = -1;

    for (int i = 0; i < n; i++) {
      ll c = color[i];
      ll v = value[i];

      ll old = dp[c];

      // Only continue if the seq exists
      ll same = (old == -LINF) ? -LINF : old + a * v;

      ll diff = (c != c1 ? mx1 : mx2) + b * v;

      ll start = b * v;

      dp[c] = max({old, same, diff, start});

      if (c == c1) {
        mx1 = dp[c];
      } else if (dp[c] >= mx1) {
        mx2 = mx1;
        c2 = c1;

        mx1 = dp[c];
        c1 = c;
      } else if (c == c2) {
        mx2 = dp[c];
      } else if (dp[c] > mx2) {
        mx2 = dp[c];
        c2 = c;
      }
    }

    cout << mx1 << endl;
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}