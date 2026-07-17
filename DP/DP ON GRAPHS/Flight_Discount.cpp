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
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

static const auto fastio = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// CSES

using T = tuple<ll, ll, ll>;

int main() {

  ll n, m;
  cin >> n >> m;

  vector<vector<pll>> adj(n + 1);

  for (int i = 0; i < m; i++) {
    ll u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
  }

  vvll dist(n + 1, vll(2, LINF));
  priority_queue<T, vector<T>, greater<T>> pq; // cost, node, coupon used

  dist[1][0] = 0;

  pq.push({0, 1, 0});

  while (!pq.empty()) {
    auto [d, u, used] = pq.top();
    pq.pop();

    if (d > dist[u][used])
      continue;

    for (auto [v, w] : adj[u]) {

      // Dont use coupon
      if (d + w < dist[v][used]) {
        dist[v][used] = d + w;
        pq.push({dist[v][used], v, used});
      }

      // Use coupon
      if(used == 0){
        if(d + w/2 < dist[v][1]){
          dist[v][1] = d + w/2;
          pq.push({dist[v][1], v, 1});
        }
      }
    }
  }

  cout << dist[n][1] << endl;

  return 0;
}