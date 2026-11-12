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

B. 0-1 MST
time limit per test
1 second
memory limit per test
256 megabytes

Ujan has a lot of useless stuff in his drawers, a considerable part of which are
his math notebooks: it is time to sort them out. This time he found an old dusty
graph theory notebook with a description of a graph.

It is an undirected weighted graph on n vertices. It is a complete graph: each
pair of vertices is connected by an edge. The weight of each edge is either 0 or
1; exactly m edges have weight 1, and all others have weight 0.

Since Ujan doesn't really want to organize his notes, he decided to find the
weight of the minimum spanning tree of the graph. (The weight of a spanning tree
is the sum of all its edges.) Can you find the answer for Ujan so he stops
procrastinating? Input

The first line of the input contains two integers n and m (1≤n≤105,
0≤m≤min(n(n−1)2,105)), the number of vertices and the number of edges of weight
1 in the graph.

The i-th of the next m lines contains two integers ai and bi (1≤ai,bi≤n, ai≠bi),
the endpoints of the i-th edge of weight 1.

It is guaranteed that no edge appears twice in the input.
Output

Output a single integer, the weight of the minimum spanning tree of the graph.
Examples
Input
Copy

6 11
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6

Output
Copy

2

Input
Copy

3 0

Output
Copy

0

When we cannot construct a complement graph : 

==========================
*/

void solve() {
  int n, m;
  cin >> n >> m;

  // vector<set<int>> adj(n + 1)
  set<int> adj[n + 1];

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }

  // Initially nothing is visited 
  set<int> unvis;
  for (int i = 1; i <= n; i++) unvis.insert(i);

  int comp = 0;
  while (!unvis.empty()) {
    comp++;

    queue<int> q;
    q.push(*unvis.begin());
    unvis.erase(unvis.begin());

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (auto it = unvis.begin(); it != unvis.end();) {
        int v = *it;

        // wt = 1
        if (adj[u].count(v))
          ++it;
        // wt = 0
        else { 
          q.push(v);
          it = unvis.erase(it);
        }
      }
    }
  }

  cout << comp - 1 << endl;
  return;
}

int main() {
  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}