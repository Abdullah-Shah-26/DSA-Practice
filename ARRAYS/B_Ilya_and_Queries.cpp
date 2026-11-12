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

void solve() {
  string s;
  cin >> s;

  int n = s.size();

  vi pref(n + 1, 0);

  // pref[i] = comparision b/w s[i - 2] & s[i - 1] + all prev comparisions

  for (int i = 1; i < n; i++) {
    pref[i + 1] = pref[i] + (s[i - 1] == s[i]);
  }

  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r; // 1 based idx

    // pref[r] = includes all prev + s[r - 2] == s[r - 1]

    // These are outside the query so 
    // pref[l] = includes all prev + s[l - 2] == s[l - 1]
    cout << pref[r] - pref[l] << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}