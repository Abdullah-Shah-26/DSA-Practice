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

L[i] stores the freq of a[i] up to i, and ft stores freq of L[i] before idx j

==========================
*/

// Stores freq of L values inserted so far
class Fenwick {
  int n;
  vi bit;

public:
  Fenwick(int n) : n(n), bit(n + 1, 0) {}

  void add(int i, int val) {
    while (i <= n) {
      bit[i] += val;
      i += (i & -i);
    }
  }

  int sum(int i) {
    int ans = 0;

    while (i > 0) {
      ans += bit[i];
      i -= (i & -i);
    }

    return ans;
  }
};

void solve() {
  int n;
  cin >> n;

  vi a(n);
  vi L(n), R(n);

  map<int, int> cnt;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    L[i] = ++cnt[a[i]];
  }

  cnt.clear();

  for (int i = n - 1; i >= 0; i--) {
    R[i] = ++cnt[a[i]];
  }

  Fenwick ft(n);
  ll ans = 0;

  // For current j, cnt prev i < j where L[i] > R[j]
  // ft.sum(R[j]) = no of elemets whose L[i] <= R[j]
  // No of prev inserted elements = j
  for (int j = 0; j < n; j++) {
    ans += j - ft.sum(R[j]);
    ft.add(L[j], 1);
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