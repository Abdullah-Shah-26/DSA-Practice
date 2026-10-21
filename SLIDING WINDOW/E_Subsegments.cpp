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
  ll n, k;
  cin >> n >> k;

  vll a(n);
  rv(a);

  map<ll, ll> m;
  set<ll> st;

  for (int i = 0; i < k - 1; i++) {
    ll x = a[i];

    m[x]++;

    if (m[x] == 1)
      st.insert(x);
    else if (m[x] == 2)
      st.erase(x);
  }

  for (int i = k - 1; i < n; i++) {

    // Entering window
    ll x = a[i];

    m[x]++;

    if (m[x] == 1)
      st.insert(x);
    else if (m[x] == 2)
      st.erase(x);

    if (st.empty())
      cout << "Nothing" << endl;
    else
      cout << *st.rbegin() << endl;

    // Leaving window
    ll y = a[i - k + 1];

    if (m[y] == 1)
      st.erase(y);
    else if (m[y] == 2) // Cause now its freq = 1
      st.insert(y);

    m[y]--;
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}