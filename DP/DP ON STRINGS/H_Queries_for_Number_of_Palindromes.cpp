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

string s;
int n, q;
int dp[N][N];
int pal[N][N];

int isPal(int l, int r) {
  if (l >= r)
    return 1;

  int &ans = pal[l][r];

  if (ans != -1)
    return ans;

  if (s[l] == s[r] && isPal(l + 1, r - 1))
    ans = 1;
  else
    ans = 0;

  return ans;
}

int solve(int l, int r) {
  if (l > r)
    return 0;

  if (l == r)
    return 1;

  int &ans = dp[l][r];

  if (ans != -1)
    return ans;

  ans = solve(l, r - 1)       // Cnt left substr
        + solve(l + 1, r)     // Cnt right substr
        - solve(l + 1, r - 1) // Remove duplicate overlap
        + isPal(l, r);        // Include whole substr if pali

  return ans;
}

int main() {

  cin >> s;
  n = (int)s.size();

  memset(dp, -1, sizeof(dp));
  memset(pal, -1, sizeof(pal));

  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;

    l--, r--;
    cout << solve(l, r) << endl;
  }

  return 0;
}