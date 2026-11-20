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

  vll a(n);
  rv(a);

  ll ans = 0;
  ll maxVal = *max_element(all(a));

  // Guess the max element mx that Bob takes.
  // Elements > mx cannot belong to the segment.
  // Find max-sum contiguous segment using only
  // elements <= mx.
  // Subtract mx from its sum to obtain a candidate answer.

  // The segment need not actually contain mx.
  // When mx equals the segment's actual maximum, its
  // exact score is considered.

  // arr : [-2, 5, 5, -1]
  // pref: [-2, 3, 8, 7]

  // At idx 2:
  // cur = 8
  // best = -2
  // cur - best = 8 - (-2) = 10 i.e subarr [5, 5] 
  // Bob takes 5
  // Score = 10 - 5 = 5 

  for (ll mx = 0; mx <= maxVal; mx++) {
    ll cur = 0;  // pref sum
    ll best = 0; // min sum

    for (ll val : a) {
      if (val > mx)
        val = -INF;

      cur += val;
      best = min(best, cur);

      ans = max(ans, (cur - best) - mx);
    }
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