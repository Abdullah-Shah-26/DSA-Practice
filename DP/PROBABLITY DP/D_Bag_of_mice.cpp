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

map<pii, double> dp;

double solve(int w, int b) {
  if (w <= 0)
    return 0.0;
  if (b <= 0)
    return 1.0;

  if (dp.count({w, b}))
    return dp[{w, b}];

  // Princess draws white -> wins immediately
  double ans = (double)w / (w + b);

  // Princess draws black, game continues
  double princessB = (double)b / (w + b);

  // Remove black mice drawn by princess
  int newW = w;
  int newB = b - 1;

  // Dragon draws black
  double dragonB = (double)newB / (newW + newB);

  // Remove dragon's black
  newB -= 1;

  // Prob that both princess & draco pick black
  double pContinue = princessB * dragonB;

  if (pContinue > 0.0) {
    // Now 1 random mouse jumps out
    // Prob that jumped mouse was black
    double jumpedB = (double)newB / (newW + newB);
    double blackCase = jumpedB * solve(newW, newB - 1);

    // Prob that jumped mouse was white
    double jumpedW = (double)newW / (newW + newB);
    double whiteCase = jumpedW * solve(newW - 1, newB);

    ans += pContinue * (blackCase + whiteCase);
  }

  return dp[{w, b}] = ans;
}

int main() {

  int w, b;
  cin >> w >> b;

  cout << fixed << setprecision(12) << solve(w, b) << endl;

  return 0;
}