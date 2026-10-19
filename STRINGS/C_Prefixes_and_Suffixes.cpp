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

// Validating whether c1 / c2 is correct string
bool check(string c, vs &s, string &ans) {
  int n = c.size();

  // Without used both identical strings can be assigned P, means no suffix assigned to that len
  vb used(n, false);
  ans.assign(s.size(), '?');

  for (int i = 0; i < (int)s.size(); i++) {
    int len = s[i].size();

    if (s[i] == c.substr(0, len) && !used[len]) {
      ans[i] = 'P';
      used[len] = true;
    } else if (s[i] == c.substr(n - len)) {
      ans[i] = 'S';
    } else
      return false;
  }

  return true;
}

void solve() {
  int n;
  cin >> n;

  vs s(2 * n - 2);

  // Strings that can possibly be Longest pref or suff
  vi longest;

  for (int i = 0; i < 2 * n - 2; i++) {
    cin >> s[i];

    if (s[i].size() == n - 1)
      longest.pb(i);
  }

  string a = s[longest[0]];
  string b = s[longest[1]];

  // String len = n
  // Largest pref / suff len = n - 1

  // Assumeing a is longest pref & b is suff
  string c1 = a + b.back();

  // Assuming b is largest pref & a is suff
  string c2 = b + a.back();

  string ans(2 * n - 2, '?');

  if (check(c1, s, ans) || check(c2, s, ans)) {
    cout << ans << endl;
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}