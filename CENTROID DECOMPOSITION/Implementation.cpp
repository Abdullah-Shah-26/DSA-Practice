#include <bits/stdc++.h>
using namespace std;

// TC = O(N*LogN)  ||  SC = O(N) 

const int N = 100005;

vector<int> adj[N];

int sz[N];       // Subtree size
bool removed[N]; // Marking instead of physically removing
int centroidParent[N];

// Compute subtree size - TC = O(K) idI = component size
void dfs(int node, int parent) {
  sz[node] = 1;

  for (int child : adj[node]) {
    if (child == parent)
      continue;

    if (removed[child])
      continue;

    dfs(child, node);

    sz[node] += sz[child];
  }
}

// Find centroid of current subtree - TC = O(K)
int findCentroid(int node, int p, int totalSz) {
  for (int child : adj[node]) {
    if (child == p)
      continue;

    if (removed[child])
      continue;

    if (sz[child] > totalSz / 2)
      return findCentroid(child, node, totalSz);
  }
  return node;
}

// Building centroid tree
void buildCentroid(int entryNode, int p) { // O(K)

  dfs(entryNode, -1);

  int centroid = findCentroid(entryNode, -1, sz[entryNode]);

  // Storing centroid tree's parent
  centroidParent[centroid] = p;

  for (int child : adj[centroid]) {
    if (removed[child])
      continue;

    buildCentroid(child, centroid);
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    adj[i].clear();
    removed[i] = false;
  }

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  buildCentroid(1, -1);
}