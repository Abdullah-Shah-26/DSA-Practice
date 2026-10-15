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

Easy version : 
Here window size == k always 

==========================
*/

void solve() {
  int n, k, q;
  cin >> n >> k >> q;

  int a[n + 1];

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  // Counts freq of key = a[i] - i
  map<int, int> m;

  // Multiset of all cnt's to get maxCnt fast
  multiset<int> st;

  // Every key intitally starts with freq = 0
  for (int i = 1; i <= n; i++)
    st.insert(0);

  // For 1st window of size [1..k-1]
  for (int i = 1; i < k; i++) {
    // remove old freq
    int key = a[i] - i;
    st.erase(st.find(m[key]));

    m[key]++;

    // add new freq
    st.insert(m[key]);
  }

  int ans[n + 1];

  for (int i = k; i <= n; i++) {
    // Add contribution of position i, before that its remove old contribution
    int key = a[i] - i;
    st.erase(st.find(m[key]));
    m[key]++;
    st.insert(m[key]);

    // Start idx of current window
    int idx = i - k + 1;

    // Minimal changes = window size - max freq of (a[i] - i)
    ans[idx] = k - *st.rbegin();

    // Update outgoing element's contribution
    st.erase(st.find(m[a[idx] - idx]));
    m[a[idx] - idx]--;
    st.insert(m[a[idx] - idx]);
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    cout << ans[l] << endl;
  }
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}