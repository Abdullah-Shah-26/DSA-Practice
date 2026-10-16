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

  vi c(2 * n);
  rv(c);

  // Every element after the 1st is strictly smaller than the chunk's first
  // element
  vvi chunks;

  chunks.pb({c[0]});

  for (int i = 1; i < 2 * n; i++)
    if (c[i] < chunks.back()[0]) // Stays in current chunk
      chunks.back().push_back(c[i]);
    else // Starts new chunk
      chunks.pb({c[i]});

  int k = (int)chunks.size();

  vi len(k);
  for (int i = 0; i < k; i++)
    len[i] = (int)chunks[i].size();

  // Subset sum DP
  // Picking the chunks to assign A
  // Rest get assigned to B
  // Both must have len = n
  vvi dp(k, vi(n + 1, -1));

  function<bool(int, int)> solve = [&](int i, int s) -> bool {
    if (s == 0)
      return true;

    if (i < 0)
      return false;

    int &ans = dp[i][s];

    if (ans != -1)
      return ans;

    bool skip = solve(i - 1, s);

    bool take = false;
    if (s >= len[i])
      take = solve(i - 1, s - len[i]);

    return ans = (take || skip);
  };

  if (!solve(k - 1, n)) {
    cout << -1 << endl;
    return;
  }

  vi choose(k, 0);

  function<void(int, int)> build = [&](int i, int s) {
    if (i < 0 || s == 0)
      return;

    // Can we reach s without chunk i
    // If yes skip else take
    if (solve(i - 1, s))
      build(i - 1, s);
    else {
      choose[i] = true;
      build(i - 1, s - len[i]);
    }
  };

  build(k - 1, n);

  // Re construction of a, b
  vi a, b;

  for (int i = 0; i < k; i++)
    for (int x : chunks[i])
      if (choose[i])
        a.pb(x);
      else
        b.pb(x);

  for (int x : a)
    cout << x << " ";
  cout << endl;

  for (int x : b)
    cout << x << ' ';
  cout << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}