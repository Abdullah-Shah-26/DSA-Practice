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
#define YES cout << "Yes\n"
#define NO cout << "No\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================



==========================
*/

const int N = 24;

int n;
ll d[N];     // dist b/w object (x,y) and purse
ll d2[N][N]; // dist b/w 2 objects
vll dp;
vi choice;

ll f(int mask) {
  if (mask == 0)
    return 0;

  ll &ans = dp[mask];
  if (ans != -1)
    return ans;

  // Just choosing some obj that is not yet chosen
  // idx of the right most set bit
  int i = __builtin_ctz(mask);

  // Case 1 : Collect obj i alone
  int nextMask = mask ^ (1 << i);
  ans = 2 * d[i] + f(nextMask);
  choice[mask] = i;

  // Case 2 : Collect i with some remaining obj j
  for (int j = i + 1; j < n; j++) {
    if (!(mask & (1 << j)))
      continue;

    int nextMask = mask ^ (1 << i) ^ (1 << j);

    ll cost = d[i] + d[j] + d2[i][j] + f(nextMask);

    if (cost < ans) {
      ans = cost;
      choice[mask] = j;
    }
  }

  return ans;
}

void solve() {
  
  ll xs, ys;
  cin >> xs >> ys;
  
  cin >> n;
  vpll p(n);

  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;

    auto [x, y] = p[i];

    ll dx = x - xs;
    ll dy = y - ys;

    d[i] = dx * dx + dy * dy;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll dx = p[i].first - p[j].first;
      ll dy = p[i].second - p[j].second;

      d2[i][j] = dx * dx + dy * dy;
    }
  }

  int total = (1 << n);
  dp.assign(total, -1);
  choice.assign(total, -1);

  cout << f(total - 1) << endl;
  cout << 0 << " ";

  int mask = total - 1;

  while (mask) {
    int i = __builtin_ctz(mask);
    int j = choice[mask]; // best pair with i to pick up

    cout << i + 1 << " ";

    if (j != i) {
      cout << j + 1 << " ";

      // Picked both
      mask ^= (1 << i);
      mask ^= (1 << j);
    } else {

      // Just picked i
      mask ^= (1 << i);
    }
    cout << 0 << " ";
  }
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}