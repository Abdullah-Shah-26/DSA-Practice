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
const ll LINF = 4e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

#define rv(a) \
  for (auto& x : (a)) cin >> x
#define pv(a)                                   \
  do {                                          \
    for (const auto& x : (a)) cout << x << ' '; \
    cout << '\n';                               \
  } while (0)
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
  int n;
  cin >> n;

  vs a(2);
  cin >> a[0] >> a[1]; 

  map<pair<int, int>, int> dp;

  auto win = [&](int r, int c1, int c2, int c3){
    int cntA = 0; 

    if(a[r][c1] == 'A') cntA++;
    if(a[r][c2] == 'A') cntA++;
    if(a[r][c3] == 'A') cntA++;

    // A should be in majoirty 
    return cntA >= 2;
  };

  function<int(int, int)> f = [&](int i, int j) {
    if (i >= n || j >= n) return 0;

    if (dp.count({i, j})) return dp[{i, j}];

    // Max no of ways to arrange the tiles so that A wins 
    int ans = 0; 

    // 3 cells from top + 3 cells from bottom
    if (i + 2 < n && j + 2 < n) {
      ans = max(ans, win(0, i, i + 1, i + 2) + win(1, j, j + 1, j + 2) + f(i + 3, j + 3));
    } 

    // XX
    // X
    if(i == j || j == i + 1){
      ans = max(ans, (((a[0][i] == 'A') + (a[0][i + 1] == 'A') + (a[1][j] == 'A')) >= 2) + f(i + 2, j + 1));
    }

    // X
    // XX
    if(i == j || j + 1 == i){
      ans = max(ans, (((a[0][i] == 'A') + (a[1][j] == 'A') + (a[1][j + 1] == 'A')) >= 2)  + f(i + 1, j + 2));
    }

    return dp[{i, j}] = ans;
  };

  cout << f(0, 0) << endl;
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}