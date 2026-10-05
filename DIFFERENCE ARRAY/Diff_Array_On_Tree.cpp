#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvpii = vector<vector<pii>>;

const int LOG = 20;
const int N = 100005;

int n;

vvpii adj;

int parent[N];
int depth[N];
int up[LOG][N];

int ans[N];
int cnt[N];

int ep[N]; // edge ID connecting u with parent[u]

vi order;

void dfs(int root) {
  vector<int> st;
  st.push_back(root);

  parent[root] = root;

  while (!st.empty()) {
    int u = st.back();
    st.pop_back();

    order.push_back(u);

    for (auto [v, edgeId] : adj[u]) {
      if (v == parent[u])
        continue;

      parent[v] = u;
      depth[v] = depth[u] + 1;
      ep[v] = edgeId;

      st.push_back(v);
    }
  }
}

void build() {
  for (int u = 1; u <= n; u++)
    up[0][u] = parent[u];

  for (int j = 1; j < LOG; j++) {
    for (int u = 1; u <= n; u++) {
      up[j][u] = up[j - 1][up[j - 1][u]];
    }
  }
}

int lca(int a, int b) {
  if (depth[a] < depth[b])
    swap(a, b);

  int diff = depth[a] - depth[b];

  for (int j = 0; j < LOG; j++) {
    if (diff & (1 << j))
      a = up[j][a];
  }

  if (a == b)
    return a;

  for (int j = LOG - 1; j >= 0; j--) {
    if (up[j][a] != up[j][b]) {
      a = up[j][a];
      b = up[j][b];
    }
  }

  return parent[a];
}

void solve() {
  cin >> n;

  adj.resize(n + 1);

  for (int edgeId = 1; edgeId <= n - 1; edgeId++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back({v, edgeId});
    adj[v].push_back({u, edgeId});
  }

  // Root tree at 1
  dfs(1);

  build();

  int k;
  cin >> k;

  while (k--) {
    int a, b;
    cin >> a >> b;

    int Lca = lca(a, b);

    cnt[a]++;
    cnt[b]++;
    cnt[Lca] -= 2;
  }

  // Reverse DFS order:
  // children are processed before parents.
  reverse(order.begin(), order.end());

  for (int u : order) {
    if (u == 1)
      continue;

    // cnt[u] is the answer for edge parent[u] -- u
    ans[ep[u]] = cnt[u];

    // Send u's contribution to its parent.
    // Just like diff array we take pref sum there 
    cnt[parent[u]] += cnt[u];
  }

  for (int id = 1; id <= n - 1; id++) {
    cout << ans[id] << ' ';
  }

  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}