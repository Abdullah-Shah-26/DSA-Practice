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

f(l, r) = Can [l, r] shrink to 1 element
If yes return that element + 1
else return -1

g(i) = min element remaining in suff[i, n - 1]

==========================
*/

int n;
vi a;
vvi dp;
vi memo;

// To check if interval can me merged into a single element
int f(int l, int r) {
  if (l == r) return a[l];

  int& ans = dp[l][r];

  if (ans != -2) return ans;

  ans = -1;

  for (int k = l; k < r; k++) {
    int left = f(l, k);
    int right = f(k + 1, r);

    if (left != -1 && left == right) return ans = left + 1;
  }

  return ans;
}

// To compute the min possible len of the array 
int g(int i) {
  if (i == n) return 0;

  int& ans = memo[i];

  if (ans != -1) return ans;

  ans = n;

  // Trying every possible segment starting at [i -> j]
  // To check whether it can be reduced to single element
  // If yes, then try remaining array from j + 1  
  for (int j = i; j < n; j++)
    if (f(i, j) != -1) ans = min(ans, 1 + g(j + 1));

  return ans;
}

void solve() {
  cin >> n;

  a.resize(n);

  for (int& x : a) cin >> x;

  dp.assign(n, vi(n, -2));
  memo.assign(n, -1);

  cout << g(0) << endl;

  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}