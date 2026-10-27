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

struct Point {
  ll x, y;
};

struct Rect {
  Point P, Q;
};

Rect mergeRect(const Rect &a, const Rect &b) {

  // Max of bottom left
  // Min of top right
  // Gives us the co-ord of intersected rectangle

  return {{max(a.P.x, b.P.x), max(a.P.y, b.P.y)},
          {min(a.Q.x, b.Q.x), min(a.Q.y, b.Q.y)}};
}

// A valid rectangle will have
// Bottom Left co-ord <= Top Right co-ord
bool valid(const Rect &r) { return r.P.x <= r.Q.x && r.P.y <= r.Q.y; }

void solve() {
  int n;
  cin >> n;

  vector<Rect> a(n), pref(n), suff(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i].P.x >> a[i].P.y >> a[i].Q.x >> a[i].Q.y;
  }

  pref[0] = a[0];
  for (int i = 1; i < n; i++)
    pref[i] = mergeRect(pref[i - 1], a[i]);

  suff[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--)
    suff[i] = mergeRect(suff[i + 1], a[i]);

  // Some (n - 1) rect have common pt
  // So we try to exclude each rect
  // Merge the rest of them
  // And check if there is a valid inter-section pt among those (n - 1) rect
  for (int i = 0; i < n; i++) {
    Rect cur;

    if (i == 0) {
      cur = suff[1];
    } else if (i == n - 1) {
      cur = pref[n - 2];
    } else {

      // Exclude i
      cur = mergeRect(pref[i - 1], suff[i + 1]);
    }

    if (valid(cur)) {
      cout << cur.P.x << " " << cur.P.y << endl;
      return;
    }
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}