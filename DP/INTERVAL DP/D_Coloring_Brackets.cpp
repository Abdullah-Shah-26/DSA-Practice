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



==========================
*/

const int N = 705;

string s;
int dp[N][N][3][3];
int matchPos[N];

int add(int a, int b) { return (a + b) % MOD; }

bool valid(int a, int b) {
  // Both brackets are uncolored
  if (a == 0 || b == 0) return true;

  // Both are colored with different colors
  if (a != b) return true;

  // Both are colored with the same color
  return false;
}

int solve(int l, int r, int x, int y) {
  if (l > r) return 0;

  int& ans = dp[l][r][x][y];

  if (ans != -1) return ans;

  ans = 0;

  if (l + 1 == r) {
    if ((x == 0 && y != 0) || (x != 0 && y == 0)) return ans = 1;

    return ans = 0;
  }

  int m = matchPos[l];

  // Outer pair encloses entire substr
  // (())
  // l  r
  if (m == r) {
    // Both outer bracket colors must be diff
    if ((x == 0) == (y == 0)) {
      return ans = 0;
    }

    for (int a = 0; a < 3; a++) {
      for (int b = 0; b < 3; b++) {
        if (!valid(x, a)) continue;
        if (!valid(y, b)) continue;
        ans = add(ans, solve(l + 1, r - 1, a, b));
      }
    }
  }

  // ( )  ( )
  // l m m+1 r

  else {
    for (int a = 0; a < 3; a++) {
      for (int b = 0; b < 3; b++) {
        // Last color of Left interval (a)
        // Must be compatible with 1st color of Right interval (b)

        if (!valid(a, b)) continue;

        int left = solve(l, m, x, a);
        int right = solve(m + 1, r, b, y);

        ans = (ans + 1LL * left % MOD * right) % MOD;
      }
    }
  }

  return ans;
}

int main() {
  cin >> s;
  int n = s.size();

  memset(dp, -1, sizeof(dp));

  stack<int> st;

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push(i);
    } else {
      int j = st.top();
      st.pop();

      matchPos[i] = j;
      matchPos[j] = i;
    }
  }

  int ans = 0;

  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      ans = (ans + solve(0, n - 1, x, y)) % MOD;
    }
  }

  cout << ans << endl;

  return 0;
}