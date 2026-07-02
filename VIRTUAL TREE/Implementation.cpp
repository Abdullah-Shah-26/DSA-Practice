#include <bits/stdc++.h>
using namespace std;

// Preprocessing : TC = O(NLogN) | SC = O(NLogN)
// Per Query     : TC = O(KLogK + KLogN) | SC = O(K)

const int N = 200005;
const int LOG = 20;

vector<int> adj[N];

int tin[N], tout[N], timer;
int depth[N];
int up[N][LOG];

void dfs(int u, int p) { // O(N)
  tin[u] = ++timer;
  up[u][0] = p;

  for (int i = 1; i < LOG; i++)
    up[u][i] = up[up[u][i - 1]][i - 1];

  for (int v : adj[u]) {
    if (v != p)
      dfs(v, u);
  }

  tout[u] = timer;
}

// Is u ancestor of v
bool isAncestor(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

// 1 Way of writing
// int LCA(int u, int v){
//   if(isAncestor(u, v))
//     return u;

//   if(isAncestor(v, u))
//     return v;

//   for(int i = LOG-1; i >= 0; i--){
//     if(!isAncestor(up[u][i], v))
//       u = up[u][i];
//   }

//   return up[u][0];
// }

int kthAncestor(int node, int k) {
  for (int j = LOG - 1; j >= 0; j--) {
    if (k & (1 << j))
      node = up[node][j];
  }
  return node;
}

int LCA(int u, int v) {
  if (depth[u] < depth[v])
    swap(u, v);

  int diff = depth[u] - depth[v];

  u = kthAncestor(u, diff);

  if (u == v)
    return u;

  for (int i = LOG - 1; i >= 0; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }

  return up[u][0];
}

vector<int> vt[N]; // Virtual Tree
vector<int> used;  // Nodes present in current vt

vector<int> buildVT(vector<int> nodes) {

  auto cmp = [&](int a, int b) { // Sort by euler order
    return tin[a] < tin[b];
  };

  sort(begin(nodes), end(nodes), cmp); // O(KLogK)

  // Add LCA of adjacent nodes
  int sz = nodes.size();
  for (int i = 0; i < sz - 1; i++) // O(KLogN)
    nodes.push_back(LCA(nodes[i], nodes[i + 1]));

  // Sort again based on euler order
  sort(begin(nodes), end(nodes), cmp);

  // Remove duplicates
  nodes.erase(unique(begin(nodes), end(nodes)), nodes.end()); // O(K)

  // Clearing prev tree queries
  for (int u : nodes)
    vt[u].clear();

  used = nodes;

  stack<int> st;
  st.push(nodes[0]);

  for (int i = 1; i < nodes.size(); i++) {

    // Pop until stack's top is ancestor of curNode
    while (
        !(tin[st.top()] <= tin[nodes[i]] && tout[st.top()] >= tout[nodes[i]]))
      st.pop();

    vt[st.top()].push_back(nodes[i]); // ancestor -> child
    st.push(nodes[i]);
  }

  return nodes;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  depth[1] = 0;
  dfs(1, 1);

  int q;
  cin >> q;

  while (q--) {
    int k;
    cin >> k;

    // Important nodes that matter for this query
    vector<int> imp(k);

    for (int i = 0; i < k; i++)
      cin >> imp[i];

    vector<int> nodes = buildVT(imp);

    //-------------------------------------------------
    // Can Run DFS / DP on the Virtual Tree here
    //
    // solve(nodes[0]);
    //
    //-------------------------------------------------

    // Clearing for next query
    for (int u : nodes)
      vt[u].clear();
  }

  return 0;
}
