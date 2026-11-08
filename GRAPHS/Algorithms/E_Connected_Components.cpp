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

When we cannot reconstruct edges of complement graph :

E. Connected Components?
time limit per test
2 seconds
memory limit per test
256 megabytes

You are given an undirected graph consisting of n vertices and edges. Instead of
giving you the edges that exist in the graph, we give you m unordered pairs
(x, y) such that there is no edge between x and y, and if some pair of vertices
is not listed in the input, then there is an edge between these vertices.

You have to find the number of connected components in the graph and the size of
each component. A connected component is a set of vertices X such that for every
two vertices from this set there exists at least one path in the graph
connecting these vertices, but adding any other vertex to X violates this rule.
Input

The first line contains two integers n and m (1 ≤ n ≤ 200000, ).

Then m lines follow, each containing a pair of integers x and y (1 ≤ x, y ≤ n,
x ≠ y) denoting that there is no edge between x and y. Each pair is listed at
most once; (x, y) and (y, x) are considered the same (so they are never listed
in the same test). If some pair of vertices is not listed in the input, then
there exists an edge between those vertices. Output

Firstly print k — the number of connected components in this graph.

Then print k integers — the sizes of components. You should output these
integers in non-descending order. Example Input Copy

5 5
1 2
3 4
3 2
4 2
2 5

Output
Copy

2
1 4

==========================
*/

const int N = 200005;

set<int> adj[N];

int cc = 0;
set<int> unused;
vector<int> comps;

void dfs(int u) {
  unused.erase(u);
  comps[cc]++;

  int v = -1;

  while (1) {
    auto it = unused.upper_bound(v);

    if (it == unused.end())
      break;

    v = *it;

    // Edge doesnt exist
    if (adj[u].count(v))
      continue;

    dfs(v);
  }
}

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    u--;
    v--;

    adj[u].insert(v);
    adj[v].insert(u);
  }

  for (int i = 0; i < n; i++)
    unused.insert(i);

  for (int i = 0; i < n; i++) {
    if (unused.count(i)) {
      comps.pb(0);
      dfs(i);
      cc++;
    }
  }

  sort(all(comps));

  cout << cc << endl;
  for (int sz : comps)
    cout << sz << " ";
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}

// Another way of solving :
/*

const int N = 500005;

vector<int> adj[N];
int mark[N];

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  vector<int> rem(n);
  iota(all(rem), 0);
  vector<vector<int>> ans;

  while (!rem.empty()) {
    int s = rem.back();
    rem.pop_back();
    vector<int> comp = {s};

    // comp doubles as the BFS queue
    for (int i = 0; i < (int)comp.size(); i++) {
      int u = comp[i];

      // Marking unallowed edges from u
      for (int v : adj[u])
        mark[v] = u + 1;

      vector<int> keep;
      for (int v : rem) {
        if (mark[v] == u + 1)
          keep.pb(v);
        else // From u can visit these
          comp.pb(v);
      }

      swap(rem, keep);
    }
    ans.pb(comp);
  }

  cout << ans.size() << endl;
  for (auto &vec : ans) {
    cout << vec.size() << " ";
    for (int x : vec)
      cout << x + 1 << " ";
    cout << endl;
  }
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}

*/
