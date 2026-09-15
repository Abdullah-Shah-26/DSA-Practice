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

#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define pv(a)                 \
  do {                        \
    for (const auto &x : (a)) \
      cout << x << ' ';       \
    cout << '\n';             \
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

Markov State Recurrence 

==========================
*/

// Memo
tuple<double, double, double> dp[101][101][101];

// get<0> - Rock wins 
// get<1> - Scissor wins
// get<2> - Paper wins

bool vis[101][101][101];

tuple<double, double, double> dfs(int r, int s, int p) {

  // s vs p, s always wins
  if (r == 0) {
    return {0, 1, 0};
  }

  // r vs p, p always wins
  if (s == 0) {
    return {0, 0, 1};
  }

  // r vs s, r always wins
  if (p == 0) {
    return {1, 0, 0};
  }

  if (vis[r][s][p])
    return dp[r][s][p];

  vis[r][s][p] = true;

  double total = 1.0 * r * s + 1.0 * s * p + 1.0 * r * p;

  // Assuming 
  
  // Paper kills rock
  auto a = dfs(r - 1, s, p);
  
  // Rock kills scissor
  auto b = dfs(r, s - 1, p);

  // Scissor kills paper
  auto c = dfs(r, s, p - 1);

  // Prob that paper kill rock
  double x = 1.0 * r * p / total;

  // Prob that rock kill scissor
  double y = 1.0 * r * s / total;

  // Prob that scissor kill rock
  double z = 1.0 * s * p / total;

  // Law of total probablity : 

  // Prob that rock wins =  Sum of (Prob that this situation happens * prob that rock wins after that situation)
  double R = x * get<0>(a) + y * get<0>(b) + z * get<0>(c);
  double S = x * get<1>(a) + y * get<1>(b) + z * get<1>(c);
  double P = x * get<2>(a) + y * get<2>(b) + z * get<2>(c);

  return dp[r][s][p] = {R, S, P};
}

void solve() {
  int r, s, p;
  cin >> r >> s >> p;

  auto [R, S, P] = dfs(r, s, p);

  cout << fixed << setprecision(12);
  cout << R << " " << S << " " << P << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}