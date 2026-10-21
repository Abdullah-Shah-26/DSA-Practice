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

  vll p(n);
  rv(p);

  int t;
  cin >> t;

  vb neg(n, false);
  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    neg[x - 1] = true; // Need to place -ve here
  }

  vll ans(n);
  stack<ll> st;

  for (int i = n - 1; i >= 0; i--) {
    if (neg[i]) {
      ans[i] = -p[i];
      st.push(p[i]);
    } else {
      
      // Can be either
      // Place the opening if possible
      if (!st.empty() && st.top() == p[i]) {
        ans[i] = p[i];
        st.pop();
      } else {
        ans[i] = -p[i];
        st.push(p[i]);
      }
    }
  }

  if (!st.empty()) {
    NO;
    return;
  }

  cout << "YES" << endl;
  for (auto x : ans)
    cout << x << " ";
  cout << endl;

  return;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}