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

How many diff strings x can be repeated to make both s and t

==========================
*/

void solve() {
  string s, t;
  cin >> s >> t;

  // s and t must share same pattern
  // If we can form s by repeating x some times
  // We must also be able to form t
  if (s + t != t + s) {
    cout << 0 << endl;
    return;
  }

  int n = s.size();
  int m = t.size();

  int g = gcd(n, m);

  int ans = 0;

  // Every valid len of x when repeated some times must produce both s, t
  // That means len(x) must divide both n, m
  // Also the string constructed must be able to make both s, t
  for (int len = 1; len <= g; len++) {
    if (g % len != 0) continue;

    string x = s.substr(0, len);
    string rep = "";

    for (int i = 0; i < n / len; i++) rep += x;

    if (rep == s) ans++;
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