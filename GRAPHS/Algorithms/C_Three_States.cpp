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

0/1 BFS 

==========================
*/

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

int n, m;
vs grid;

vvi bfs(char state) {
  vvi dist(n, vi(m, INF));
  deque<pii> dq;

  // 0/1 bfs
  // From all sources of this belonging to this state
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == state) {
        dist[i][j] = 0;
        dq.pb({i, j});
      }
    }
  }

  while (!dq.empty()) {
    auto [r, c] = dq.front();
    dq.pop_front();

    for (int k = 0; k < 4; k++) {
      int nr = r + row[k];
      int nc = c + col[k];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#') {
        // Entering empty cell cost = 1
        // Entering state cell cost = 0
        int cost = (grid[nr][nc] == '.');
        int newd = dist[r][c] + cost;

        if (newd < dist[nr][nc]) {
          dist[nr][nc] = newd;

          if (cost == 0) {
            dq.push_front({nr, nc});
          } else {
            dq.pb({nr, nc});
          }
        }
      }
    }
  }

  return dist;
}

void solve() {
  cin >> n >> m;

  grid.resize(n);

  for (auto& row : grid) cin >> row;

  auto d1 = bfs('1');
  auto d2 = bfs('2');
  auto d3 = bfs('3');

  int ans = INF;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '#') continue;

      // Unreachable by any state, skip
      if (d1[i][j] == INF || d2[i][j] == INF || d3[i][j] == INF) continue;

      int cost = d1[i][j] + d2[i][j] + d3[i][j];

      // The shared cell was counted thrice
      // But we pay for it only once
      if (grid[i][j] == '.') {
        cost -= 2;
      }

      ans = min(ans, cost);
    }
  }

  if (ans == INF) ans = -1;

  cout << ans << endl;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}