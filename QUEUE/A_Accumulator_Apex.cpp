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

Custom comparator for pq

==========================
*/

struct chunk {
  ll minpref = 0;  // deepest dip inside this chunk
  ll sum = 0;      // total sum of this chunk
};

struct Node {
  ll minpref = 0;  // x + minpref >= 0
  ll sum = 0;
  int listId;
  int idx;  // index of chunk
};

void solve() {
  ll x, k;
  cin >> x >> k;

  vector<vector<chunk>> lists(k);

  for (int i = 0; i < k; i++) {
    int n;
    cin >> n;

    ll sum = 0, minpref = 0;

    for (int j = 0; j < n; j++) {
      ll w;
      cin >> w;

      sum += w;
      minpref = min(minpref, sum);  // deepest dip

      if (sum > 0) {
        lists[i].pb({minpref, sum});
        sum = 0;
        minpref = 0;
      }
    }
  }

  // Largest min pref first
  auto cmp = [](const auto& a, const auto& b) { return a.minpref < b.minpref; };

  priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

  // Initially putting 1st chunk of each list in pq
  for (int i = 0; i < k; i++) {
    if (!lists[i].empty()) {
      pq.push({lists[i][0].minpref, lists[i][0].sum, i, 0});
    }
  }

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    // We are unable to take even the easiest chunk, break
    if (x + cur.minpref < 0) break;

    x += cur.sum;

    int nxt = cur.idx + 1;  // nxt chunk of same list

    if (nxt < lists[cur.listId].size()) {
      auto& c = lists[cur.listId][nxt];
      pq.push({c.minpref, c.sum, cur.listId, nxt});
    }
  }

  cout << x << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}