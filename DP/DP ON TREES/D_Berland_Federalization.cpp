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

int n, k;
vvpii adj;
vvi dp;
vi parent, parentEdge, sub;
vvi children;

// chioce[u][i][s] = cnt of nodes we took from ith child of u forming s nodes
vector<vvi> choice;

vi ans;

void dfs(int u, int p) {
  parent[u] = p;
  sub[u] = 1;

  // Post order dfs
  // Processing children first
  for (auto [v, edgeId] : adj[u]) {
    if (v == p)
      continue;

    parentEdge[v] = edgeId;
    dfs(v, u);

    sub[u] += sub[v];
    children[u].pb(v);
  }

  vi cur(k + 1, INF);
  cur[1] = 0; // Min cuts to select 1 node inside subtree u

  choice[u].resize(children[u].size(), vi(k + 1, -1));

  // For each child v of node u
  // Try including or excluding child v, update the minimum cuts for each
  // selected-node count.

  for (int i = 0; i < (int)children[u].size(); i++) {
    int v = children[u][i];

    // next[s] = Min cuts after processing this child with s selected nodes
    vi next(k + 1, INF);

    // have = no of nodes already selected from u and children processed so far.

    // take = number of additional nodes we select from the current child
    // subtree v.

    for (int have = 1; have <= k; have++) {
      if (cur[have] == INF)
        continue;

      // Case 1: Exclude entire subtree of v
      // Cut the edge u -- v
      if (cur[have] + 1 < next[have]) {
        next[have] = cur[have] + 1;
        choice[u][i][have] = 0;
      }

      // Case 2: Include some nodes from subtree v
      for (int take = 1; have + take <= k && take <= sub[v]; take++) {

        if (dp[v][take] == INF)
          continue;

        int totalNodes = have + take;
        int totalCuts = cur[have] + dp[v][take];

        if (totalCuts < next[totalNodes]) {
          next[totalNodes] = totalCuts;
          choice[u][i][totalNodes] = take;
        }
      }
    }

    cur = next;
  }

  dp[u] = cur;
}

// To recover edges that were cut
void reconstruct(int u, int nodesNeeded) {

  // Undo in reverse order
  for (int i = children[u].size() - 1; i >= 0; i--) {
    int v = children[u][i];

    int take = choice[u][i][nodesNeeded];

    // This child's subtree was excluded
    if (take == 0) {
      ans.pb(parentEdge[v]);
    }

    // These many nodes were taken from the child
    else {
      reconstruct(v, take);
    }

    nodesNeeded -= take;
  }
}

void solve() {
  cin >> n >> k;

  adj.resize(n + 1);
  dp.resize(n + 1);
  children.resize(n + 1);
  choice.resize(n + 1);

  parent.assign(n + 1, 0);
  parentEdge.assign(n + 1, 0);
  sub.assign(n + 1, 0);

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].pb({v, i});
    adj[v].pb({u, i});
  }

  dfs(1, 0);

  int bestRoot = -1;
  int minCuts = INF;

  // Desired componnent can start at any node
  for (int u = 1; u <= n; u++) {
    int cutsNeeded = dp[u][k];

    // If u is not tree root, disconnect it from parent
    if (u != 1)
      cutsNeeded++;

    if (cutsNeeded < minCuts) {
      minCuts = cutsNeeded;
      bestRoot = u;
    }
  }

  // Cut the edge above chosen comp, if req
  if (bestRoot != 1) {
    ans.pb(parentEdge[bestRoot]);
  }

  // Recovering all cuts inside chosen subtree
  reconstruct(bestRoot, k);

  cout << (int)ans.size() << endl;

  // Id's of edges we cut
  for (auto edgeId : ans)
    cout << edgeId << " ";

  cout << endl;
}

int main() {

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}