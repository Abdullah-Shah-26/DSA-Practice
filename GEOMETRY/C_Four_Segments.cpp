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

// Segment
struct S {
  ll x1, y1, x2, y2;
};

void solve() {
  S a, b, c, d;

  cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
  cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
  cin >> c.x1 >> c.y1 >> c.x2 >> c.y2;
  cin >> d.x1 >> d.y1 >> d.x2 >> d.y2;

  S seg[] = {a, b, c, d};

  // horizontal, vertical
  int h = 0, v = 0;

  for (auto s : seg) {
    if (s.x1 == s.x2)
      h++;
    if (s.y1 == s.y2)
      v++;
  }

  // No of co-incident points
  int points = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      if (seg[i].x1 == seg[j].x1 && seg[i].y1 == seg[j].y1)
        points++;

      if (seg[i].x1 == seg[j].x2 && seg[i].y1 == seg[j].y2)
        points++;

      if (seg[i].x2 == seg[j].x1 && seg[i].y2 == seg[j].y1)
        points++;

      if (seg[i].x2 == seg[j].x2 && seg[i].y2 == seg[j].y2)
        points++;
    }
  }

  if (h == 2 && v == 2 && points == 4) {
    YES;
  } else {
    NO;
  }
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}