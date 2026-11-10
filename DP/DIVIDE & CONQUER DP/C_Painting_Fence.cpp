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

const int N = 5005;

int n;
int a[N], mn[N][N];
int dp[N][N];

int f(int l, int r, int base) {
  if (l > r)
    return 0;

  int &ans = dp[l][r];
  if (ans != -1)
    return ans;

  int m = mn[l][r];

  // Paint every plank in this range vertically
  ans = r - l + 1;

  // Paint horizontal layers
  int hori = m - base;

  int i = l;
  while (i <= r) {
    if (a[i] == m) { // This plank is fully painted by m layers
      i++;
      continue;
    }

    int j = i;

    while (j <= r && a[j] > m) // j stops at first plank equal to m
      j++;

    hori += f(i, j - 1, m);

    i = j;
  }

  return ans = min(ans, hori);
}

void solve() {
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  // Precomputing min ht of every interval
  for (int l = 0; l < n; l++) {
    mn[l][l] = a[l];

    for (int r = l + 1; r < n; r++) {
      mn[l][r] = min(mn[l][r - 1], a[r]);
    }
  }

  memset(dp, -1, sizeof(dp));

  cout << f(0, n - 1, 0) << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}