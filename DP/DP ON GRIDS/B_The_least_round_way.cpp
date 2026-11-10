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
  int n;
  cin >> n;

  vvi a(n, vi(n));
  vvi two(n, vi(n));
  vvi five(n, vi(n));

  int zx = -1, zy = -1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];

      if (a[i][j] == 0) {
        zx = i;
        zy = j;
        continue;
      }

      int x = a[i][j];

      while (x % 2 == 0) {
        two[i][j]++;
        x /= 2;
      }

      x = a[i][j];

      while (x % 5 == 0) {
        five[i][j]++;
        x /= 5;
      }
    }
  }

  vvi dp2(n, vi(n, INF));
  vvi dp5(n, vi(n, INF));

  vector<vector<char>> par2(n, vector<char>(n));
  vector<vector<char>> par5(n, vector<char>(n));

  dp2[0][0] = two[0][0];
  dp5[0][0] = five[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!i && !j)
        continue;

      // Down
      if (i > 0 && dp2[i - 1][j] < dp2[i][j]) {
        dp2[i][j] = dp2[i - 1][j];
        par2[i][j] = 'D';
      }

      if (i > 0 && dp5[i - 1][j] < dp5[i][j]) {
        dp5[i][j] = dp5[i - 1][j];
        par5[i][j] = 'D';
      }

      // Right
      if (j > 0 && dp2[i][j - 1] < dp2[i][j]) {
        dp2[i][j] = dp2[i][j - 1];
        par2[i][j] = 'R';
      }

      if (j > 0 && dp5[i][j - 1] < dp5[i][j]) {
        dp5[i][j] = dp5[i][j - 1];
        par5[i][j] = 'R';
      }

      dp2[i][j] += two[i][j];
      dp5[i][j] += five[i][j];
    }
  }

  // Min trailing zeros ans can have
  int ans = min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]);

  // There is a cell with value 0
  // So no of trailing zeros = 1
  if (zx != -1 && ans > 1) {
    cout << 1 << endl;

    string path;

    // zx = row where zero lies
    // zy = col where zero lies
    // To go to zx we need to move in rows i.e go down
    // To go to zy we need to move in cols i.e go right
    for (int i = 0; i < zx; i++)
      path += 'D';
    for (int j = 0; j < zy; j++)
      path += 'R';
    for (int i = zx; i < n - 1; i++)
      path += 'D';
    for (int j = zy; j < n - 1; j++)
      path += 'R';

    cout << path << endl;
    return;
  }

  cout << ans << endl;

  vector<vector<char>> &par =
      (dp2[n - 1][n - 1] <= dp5[n - 1][n - 1]) ? par2 : par5;

  string path;

  int i = n - 1, j = n - 1;
  while (i > 0 || j > 0) {
    char dir = par[i][j];
    path += dir;

    if (dir == 'D')
      i--;
    else
      j--;
  }

  reverse(all(path));
  cout << path << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}