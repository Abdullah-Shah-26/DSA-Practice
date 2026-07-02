#include <bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>> adj;
vector<int> color;
vector<int> freq; // times color c appears
vector<int> ans;

// Euler Tour
vector<int> tin, tout;
vector<int> euler;
int timer = 0;

// Subtree size
vector<int> sub;

vector<int> heavyChild;

int maxFreq;
long long sum;

void dfsSz(int u, int p) {
  sub[u] = 1;
  heavyChild[u] = -1;

  int largerSz = 0;

  for (int v : adj[u]) {
    if (v == p)
      continue;

    dfsSz(v, u);

    sub[u] += sub[v];

    if (sub[v] > largerSz) {
      largerSz = sub[v];
      heavyChild[u] = v;
    }
  }
}

// 0 based Euler indexing
void dfsEuler(int u, int p) {
  tin[u] = timer;
  euler[timer] = u;
  timer++;

  for (int v : adj[u]) {
    if (v == p)
      continue;

    dfsEuler(v, u);
  }

  tout[u] = timer - 1;
}

void addNode(int u) { freq[color[u]]++; }

void removeNode(int u) { freq[color[u]]--; }

void dfs(int u, int p, bool keep) {

  // Process all light children
  for (int v : adj[u]) {
    if (v == p || v == heavyChild[u])
      continue;

    dfs(v, u, false);
  }

  // Process heavy child
  if (heavyChild[u] != -1)
    dfs(heavyChild[u], u, true);

  // Merge all light subTrees
  for (int v : adj[u]) {
    if (v == p || v == heavyChild[u])
      continue;

    for (int i = tin[v]; i <= tout[v]; i++) {
      int node = euler[i];
      addNode(node);
    }
  }

  // Add current node
  addNode(u);
  ans[u] = true;

  // If this subtree shouln't be kept
  // erase everything belonging to it
  if (!keep) {
    for (int i = tin[u]; i <= tout[u]; i++)
      removeNode(euler[i]);

    maxFreq = 0;
    sum = 0;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  color.assign(n + 1, 0);
  adj.assign(n + 1, {});

  tin.assign(n + 1, 0);
  tout.assign(n + 1, 0);

  euler.assign(n, 0);

  sub.assign(n + 1, 0);
  heavyChild.assign(n + 1, -1);

  freq.assign(n + 1, 0);
  ans.assign(n + 1, 0);

  for (int i = 1; i <= n; i++)
    cin >> color[i];

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  timer = 0; 
  maxFreq = 0; 
  sum = 0; 

  dfsSz(1, 0);
  dfsEuler(1, 0);
  dfs(1, 0, true);

  for(int i = 1; i <= n; i++)
    cout << ans[i] << " ";

  return 0; 
}