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
#define pf(x) cout << x << ' '
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

A, B can be taken as diameter points

d(A,C) + d(B,C) = d(A,X) + d(B,X) + 2 * d(X,C)
                = D + 2 * d(X,C)

          d(X,C) = (d(A,C) + d(B,C)) - D)/2

==========================
*/

const int N = 200005;

int n;
vi adj[N];

// {farthestNode, distArr}
pair<int, vi> bfs(int st) {
  vi dist(n + 1, -1);
  queue<int> q;

  q.push(st);
  dist[st] = 0;

  int maxDist = 0;
  int farthest = st;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);

        if (dist[v] > maxDist) {
          maxDist = dist[v];
          farthest = v;
        }
      }
    }
  }

  return {farthest, dist};
}

void solve() {
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb(v);
    adj[v].pb(u);
  }

  int A = bfs(1).first;

  // distA is dist of all nodes from A & B is the farthest node from A
  auto [B, distA] = bfs(A);

  // distB is dist of all nodes from B
  auto [_, distB] = bfs(B);

  int C = -1;
  int maxSum = -1;

  for (int i = 1; i <= n; i++) {
    if (i == A || i == B)
      continue;

    if (distA[i] + distB[i] > maxSum) {
      maxSum = distA[i] + distB[i];
      C = i;
    }
  }

  int diameter = distA[B];

  // Extra edges C add : (distA[C] + distB[C] - daimeter)/2

  int extra = (maxSum - diameter) / 2;
  int total = extra + diameter;

  cout << total << endl;
  pf(A);
  pf(B);
  pf(C);
}

int main() {

  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}