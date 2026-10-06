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



==========================
*/

void solve() {
  string s;
  cin >> s;

  int n = s.size();

  // Here start is the left end point of the valid substring
  // start[i] = left end point of valid substring ending at i
  vi start(n + 1, -1);

  int maxL = 0;

  stack<int> st;
  map<int, int> m;

  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push(i);
    } else {
      if (st.empty()) {
        continue;
      }

      int idx = st.top();
      st.pop();

      // The valid substring can be extended
      // From idx till i (opening brace towards right)
      start[i] = idx;

      // Connect both
      //   |
      // ( ) ( )
      //     | i
      //    idx
      //
      // Here idx - 1 is the character just before
      // the current valid substring.
      //
      // If it is ')' and there is already a valid
      // substring ending there, connect both substrings.

      if (idx > 0 && s[idx - 1] == ')' && start[idx - 1] >= 0) {
        start[i] = start[idx - 1];
      }

      int L = i - start[i] + 1;
      m[L]++;

      maxL = max(maxL, L);
    }
  }

  // Case where there is no valid substring
  m[0] = 1;

  cout << maxL << " " << m[maxL] << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}