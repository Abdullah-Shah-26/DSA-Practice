#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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

#define rv(a)         \
  for (auto &x : (a)) \
  cin >> x
#define pv(a)                 \
  do {                        \
    for (const auto &x : (a)) \
      cout << x << ' ';       \
    cout << '\n';             \
  } while (0)
#define rm(mat)         \
  for (auto &r : (mat)) \
    for (auto &x : (r)) \
  cin >> x
#define pm(mat)                   \
  do {                            \
    for (const auto &r : (mat)) { \
      for (const auto &x : (r))   \
        cout << x << ' ';         \
      cout << '\n';               \
    }                             \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define endl '\n'

/*
==========================
Observation / Thinking
--------------------------

Diameter/2 = Center of tree

- If Diameter = Even
- Only 1 center
- Choose it and make it black
- Keep increasing dist
- ans = d/2 + 1

1 --- 2 --- 3

- If Diameter = Odd
- 2 Centers
- Ans changes

1 --- 2 --- 3 --- 4

- C1 = 2
- C2 = 3

operations : 2
2 1
3 1

1 --- 2 --- 3 --- 4 --- 5 --- 6

- c1 = 3
- c2 = 4

ops : 
3 1
4 1 
3 3
4 3 

==========================
*/

int n;
vvi adj;

int bfs(int st, vi &parent) {
  vi dist(n + 1, -1);
  queue<int> q;

  q.push(st);
  dist[st] = 0;
  parent[st] = 0;

  int farthest = st;
  int maxDist = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        parent[v] = u;
        q.push(v);

        if (dist[v] > maxDist) {
          farthest = v;
          maxDist = dist[v];
        }
      }
    }
  }

  return farthest;
}

void solve() {
  cin >> n;
  adj.assign(n + 1, {});

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  vi dummy(n + 1, 0);
  int A = bfs(1, dummy);

  vi parent(n + 1, 0);
  int B = bfs(A, parent);

  vi path;
  int cur = B;

  while (cur != 0) {
    path.pb(cur);
    cur = parent[cur];
  }

  // Path contains vertices
  // Diameter = edges

  int d = path.size() - 1;

  if (d % 2 == 0) {
    int center = path[d / 2];
    int r = d / 2;

    pf(r + 1); // no of ops
    for (int d = 0; d <= r; d++) {
      cout << center << " " << d << endl;
    }
  } else {
    int c1 = path[d / 2];
    int c2 = path[d / 2 + 1];
    int r = (d + 1) / 2;

    vpii seta, setb;

    for (int d = 0; d <= r; d++) {
      seta.pb({c1, d});
    }

    for (int d = 1; d <= r; d += 2) {
      setb.pb({c1, d});
      setb.pb({c2, d});
    }

    if (setb.size() < seta.size()) {
      cout << setb.size() << endl;
      for (auto p : setb)
        cout << p.first << " " << p.second << endl;
    } else {
      cout << seta.size() << endl;
      for (auto p : seta)
        cout << p.first << ' ' << p.second << endl;
    }
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