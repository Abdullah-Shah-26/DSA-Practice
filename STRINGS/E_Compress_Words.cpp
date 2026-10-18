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

// Longest prefix which is also a suffix
vi buildLPS(string &s) {
  int n = s.size();
  vi lps(n, 0);

  for (int i = 1, j = 0; i < n;) {
    if (s[i] == s[j]) {
      lps[i] = j + 1;
      i++;
      j++;
    } else if (j > 0)
      j = lps[j - 1];
    else
      i++;
  }

  return lps;
}

void solve() {
  int n;
  cin >> n;

  vs s(n);
  for (auto &w : s)
    cin >> w;

  string ans = s[0];

  for (int i = 1; i < n; i++) {
    string nxt = s[i];

    // Overlap cannot be longer than the shorter string
    int len = min(ans.size(), nxt.size());
    string cur = ans.substr(ans.size() - len);

    // Largest prefix of next that matches
    // Suffix of ans(cur) that part should be eliminated and rest should be concatinated
    string temp = nxt + "#" + cur;
    vi LPS = buildLPS(temp);

    int overLap = LPS.back();
    ans += nxt.substr(overLap);
  }

  cout << ans << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}