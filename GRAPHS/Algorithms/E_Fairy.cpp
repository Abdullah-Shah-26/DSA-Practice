#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

#define rv(a) \
  for (auto& x : (a)) cin >> x
#define pv(a)                                   \
  do {                                          \
    for (const auto& x : (a)) cout << x << ' '; \
    cout << '\n';                               \
  } while (0)
#define rm(mat)         \
  for (auto& r : (mat)) \
    for (auto& x : (r)) cin >> x
#define pm(mat)                                     \
  do {                                              \
    for (const auto& r : (mat)) {                   \
      for (const auto& x : (r)) cout << x << ' '; \
      cout << '\n';                                 \
    }                                               \
  } while (0)
#define pf(x) cout << x << '\n'
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define rs resize
#define as assign
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yno(a) cout << ((a) ? "YES\n" : "NO\n")
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define endl '\n'

const int MAXN = 10005;

int n, m;

vector<pair<int, int>> adj[MAXN];  // [nei, edgeId]

int parent[MAXN];
int parentEdge[MAXN];
int depth[MAXN];

int color[MAXN];
int tin[MAXN];

bool vis[MAXN];

int oddCnt[MAXN];
int evenCnt[MAXN]; // Must keep track of even cycles to avoid parity merging

int component[MAXN];
int oddCycleInComp[MAXN];

bool ans[MAXN];

int timer = 0;
int totalOddCycles = 0; // Global tracker for all odd cycles

void dfs(int node, int par, int edgeUsed, int curCol, int compId) {
  vis[node] = 1;

  parent[node] = par;
  parentEdge[node] = edgeUsed;

  component[node] = compId;

  color[node] = curCol;

  if (par == 0)
    depth[node] = 0;
  else
    depth[node] = depth[par] + 1;

  tin[node] = ++timer;

  for (auto [child, edgeId] : adj[node]) {
    if (edgeId == edgeUsed) continue;

    if (!vis[child]) {
      dfs(child, node, edgeId, !curCol, compId);
    }
  }
}

void dfsAccumulate(int node, int par) {
  for (auto [child, edgeId] : adj[node]) {
    if (parent[child] != node || parentEdge[child] != edgeId)
      continue;  // Skip back edge else infinite recursion

    dfsAccumulate(child, node);

    oddCnt[node] += oddCnt[child];
    evenCnt[node] += evenCnt[child];

    // This accumulates cnt of odd cylce each tree edge is part of
    // [u,v] = cnt how many odd cycles it belongs to
  }
}

// what edge can i remove so graph becomes bipartite ???
// a graph is not bipartite cause of odd cycles
// so removing an edge makes oddd cycle break

void solve() {
  cin >> n >> m;

  vpii edges;
  edges.pb({-1, -1});  // dummy so edges are 1 - indexed

  for (int id = 1; id <= m; id++) {
    int u, v;
    cin >> u >> v;

    edges.pb({u, v});  // edges[id]  = {U,V}

    adj[u].pb({v, id});
    adj[v].pb({u, id});
  }

  // Graph isnt guarenteed to be connected so
  int compId = 0;
  for (int node = 1; node <= n; node++) {
    if (!vis[node]) {
      compId++;
      dfs(node, 0, 0, 0, compId);
    }
  }

  // Undirected Graph
  // Only 2 kinds of edge possible
  
  // Tree edge :
  // parent[u] == v || parent[v] == u
  // Back edge :
  // neither parent[u] == v nor parent[v] == u

  // Back edge :
  // same colored end pts
  // tree path has even len
  // + this edge from Odd cycle
  // Component not bipartite

  // diff color end pts
  // tree path has odd len
  // + this edge form even cycle
  // Doest break bipartiteness

  memset(ans, false, sizeof(ans));
  for (int edgeId = 1; edgeId <= m; edgeId++) {
    auto [u, v] = edges[edgeId];

    bool isTreeEdge = (parent[u] == v && parentEdge[u] == edgeId) || (parent[v] == u && parentEdge[v] == edgeId);

    // Back Edge :
    if (!isTreeEdge) {
      if (depth[u] < depth[v]) swap(u, v);

      if (color[u] == color[v]) {
        // same color endpts
        // odd cycle
        // comp not bipatite

        totalOddCycles++;
        oddCycleInComp[component[u]]++;

        // Post Order DFS
        // Use diff array on trees to mark path
        // We come back from deepest node to upward
        // So u = deepest
        // v = upward
        // u ---> v
        // so update should start from u and stop at v

        oddCnt[u]++;
        oddCnt[v]--;

        // How many odd cycles use each TreeEdge
      } else {
        evenCnt[u]++;
        evenCnt[v]--;
      }
    }
  }

  for (int node = 1; node <= n; node++) {
    if (parent[node] == 0)  // dfs root
      dfsAccumulate(node, 0);
  }

  // Edge case: If already bipartite, removing ANY edge keeps it bipartite
  if (totalOddCycles == 0) {
    cout << m << endl;
    for (int i = 1; i <= m; i++) cout << i << (i == m ? "" : " ");
    cout << endl;
    return;
  }

  for (int edgeId = 1; edgeId <= m; edgeId++) {
    auto [u, v] = edges[edgeId];

    bool isTreeEdge = (parent[u] == v && parentEdge[u] == edgeId) || (parent[v] == u && parentEdge[v] == edgeId);

    if (!isTreeEdge && color[u] == color[v]) {
      if (totalOddCycles == 1)
        ans[edgeId] = true;
    }
  }

  // IF we have 2 backedges in same component, removing one only removes one odd
  // cycle, other remains

  for (int node = 1; node <= n; node++) {
    if (parent[node] == 0) continue;

    // Tree edge must cover ALL odd cycles and ZERO even cycles
    if (oddCnt[node] == totalOddCycles && evenCnt[node] == 0) {
      ans[parentEdge[node]] = true;
    }
  }

  vi finalAns;
  for (int edgeId = 1; edgeId <= m; edgeId++) {
    if (ans[edgeId]) {
      finalAns.pb(edgeId);
    }
  }

  cout << finalAns.size() << endl;
  pv(finalAns);
}

int main() {
  solve();
  return 0;
}