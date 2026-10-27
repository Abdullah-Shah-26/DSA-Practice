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

map<string, int> atomicNum = {
    {"H", 1},   {"He", 2},  {"Li", 3},  {"Be", 4},  {"B", 5},   {"C", 6},
    {"N", 7},   {"O", 8},   {"F", 9},   {"Ne", 10}, {"Na", 11}, {"Mg", 12},
    {"Al", 13}, {"Si", 14}, {"P", 15},  {"S", 16},  {"Cl", 17}, {"Ar", 18},
    {"K", 19},  {"Ca", 20}, {"Sc", 21}, {"Ti", 22}, {"V", 23},  {"Cr", 24},
    {"Mn", 25}, {"Fe", 26}, {"Co", 27}, {"Ni", 28}, {"Cu", 29}, {"Zn", 30},
    {"Ga", 31}, {"Ge", 32}, {"As", 33}, {"Se", 34}, {"Br", 35}, {"Kr", 36},
    {"Rb", 37}, {"Sr", 38}, {"Y", 39},  {"Zr", 40}, {"Nb", 41}, {"Mo", 42},
    {"Tc", 43}, {"Ru", 44}, {"Rh", 45}, {"Pd", 46}, {"Ag", 47}, {"Cd", 48},
    {"In", 49}, {"Sn", 50}, {"Sb", 51}, {"Te", 52}, {"I", 53},  {"Xe", 54},
    {"Cs", 55}, {"Ba", 56}, {"La", 57}, {"Ce", 58}, {"Pr", 59}, {"Nd", 60},
    {"Pm", 61}, {"Sm", 62}, {"Eu", 63}, {"Gd", 64}, {"Tb", 65}, {"Dy", 66},
    {"Ho", 67}, {"Er", 68}, {"Tm", 69}, {"Yb", 70}, {"Lu", 71}, {"Hf", 72},
    {"Ta", 73}, {"W", 74},  {"Re", 75}, {"Os", 76}, {"Ir", 77}, {"Pt", 78},
    {"Au", 79}, {"Hg", 80}, {"Tl", 81}, {"Pb", 82}, {"Bi", 83}, {"Po", 84},
    {"At", 85}, {"Rn", 86}, {"Fr", 87}, {"Ra", 88}, {"Ac", 89}, {"Th", 90},
    {"Pa", 91}, {"U", 92},  {"Np", 93}, {"Pu", 94}, {"Am", 95}, {"Cm", 96},
    {"Bk", 97}, {"Cf", 98}, {"Es", 99}, {"Fm", 100}};

int dp[18][1 << (17)];

bool backtrack(int i, int rem, vi& target, vi& sum, vi& groups) {
  int k = target.size();

  // We were able to form all our target's
  // And there are no rem atoms left
  if (i == k) return rem == 0;

  if (dp[i][rem] != -1) return dp[i][rem];

  for (int mask = rem; mask; mask = (mask - 1) & rem) {
    if (sum[mask] != target[i]) continue;

    groups[i] = mask;

    if (backtrack(i + 1, rem ^ mask, target, sum, groups)) {
      return dp[i][rem] = true;
    }
  }

  return dp[i][rem] = false;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vs a(n), b(k);
  vi x(n), target(k);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x[i] = atomicNum[a[i]];
  }

  for (int i = 0; i < k; i++) {
    cin >> b[i];
    target[i] = atomicNum[b[i]];
  }

  int total = (1 << n);
  vi sum(total);

  //* TC = O(2^n)
  // Reuse smaller subste sum's method
  for (int mask = 1; mask < total; mask++) {
    // Idx of lowest set bit in 0 based idx
    int bit = __builtin_ctz(mask);

    // sum[mask] = sum[mask without selecting this atom] + value of this atom
    sum[mask] = sum[mask ^ (1 << bit)] + x[bit];
  }

  // groups[i] = bitmask of subset assigned to i
  vi groups(k);
  int rem = total - 1;

  memset(dp, -1, sizeof(dp));

  // Backtracking
  if (!backtrack(0, rem, target, sum, groups)) {
    NO;
    return;
  }

  // Greedy : Not working for hidden tests
  // for (int i = 0; i < k; i++) {
  //   bool found = false;

  //   for (int mask = rem; mask; mask = (mask - 1) & rem) {
  //     if (sum[mask] == target[i]) {
  //       groups[i] = mask;
  //       rem ^= mask;
  //       found = true;
  //       break;
  //     }
  //   }

  //   if (!found) {
  //     NO;
  //     return;
  //   }
  // }

  YES;
  for (int i = 0; i < k; i++) {
    bool first = true;

    for (int j = 0; j < n; j++) {
      if (groups[i] & (1 << j)) {
        if (!first) cout << "+";
        cout << a[j];
        first = false;
      }
    }

    cout << "->" << b[i] << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}