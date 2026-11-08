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

const int N = 1e5 + 5;
const int M = (1 << 7);

ll n, p, k;
ll dp[N][M + 1];
ll skill[N][7];
ll a[N], idx[N];

// f(i, mask) = max strength using people from i..n-1, where mask = pos already
// filled in team

// At i, 3 choices :
// Play at jth pos, (j not in mask) -> s[i][j] + f(i + 1, mask | (1 << j))
// Be audience only if (taken < k) -> a[i] + f(i + 1, mask)
// SKip if audience full

ll f(int i, int mask) {
  if (i == n) {
    return (mask == ((1 << p) - 1)) ? 0 : -LINF;
  }

  ll& ans = dp[i][mask];

  if (ans != -1) return ans;

  // Audience is sorted in desc order
  // So guys remaining at front are best possible candidates
  // So we dont have any choice but to take them as audience
  int audience = i - __builtin_popcount(mask);
  ans = f(i + 1, mask) + (audience < k ? a[idx[i]] : 0);

  // Play at pos j
  for (int j = 0; j < p; j++) {
    if (!(mask & (1 << j))) {
      ans = max(ans, f(i + 1, mask | (1 << j)) + skill[idx[i]][j]);
    }
  }

  return ans;
}

void solve() {
  cin >> n >> p >> k;

  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < p; j++) cin >> skill[i][j];

  for (int i = 0; i < n; i++) idx[i] = i;

  auto cmp = [&](ll i, ll j) { return a[i] > a[j]; };

  // Sort the audience in desc order
  sort(idx + 0, idx + n, cmp);

  memset(dp, -1, sizeof(dp));

  cout << f(0, 0) << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}