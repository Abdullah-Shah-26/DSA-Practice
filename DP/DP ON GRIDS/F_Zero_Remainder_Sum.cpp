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

I need to choose the subset of each row so that its sum is max & is div by k and size of subset <= m/2 for each row

I need to do it for all rows and find max sum

i = cur row
j = cur col
cnt = elem selected from cur row
rem = total sum % k

==========================
*/

int n, m, k;
vvi grid;

int dp[71][71][71][71];

int f(int i, int j, int cnt, int rem) {
  if (i == n) return rem == 0 ? 0 : -INF;

  // Go to next row
  if (j == m) return f(i + 1, 0, 0, rem);

  if (dp[i][j][cnt][rem] != -1) return dp[i][j][cnt][rem];

  int skip = f(i, j + 1, cnt, rem);
  
  int take = -INF;

  if (cnt < m / 2)
    take = grid[i][j] + f(i, j + 1, cnt + 1, (rem + grid[i][j]) % k);

  return dp[i][j][cnt][rem] = max(take, skip);
}

void solve() {
  cin >> n >> m >> k;
  grid.assign(n, vi(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> grid[i][j];
  }

  memset(dp, -1, sizeof(dp));
  cout << f(0, 0, 0, 0) << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}