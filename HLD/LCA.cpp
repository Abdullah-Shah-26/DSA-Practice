#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

// SPOJ - LCA - Problem

vector<int> adj[N];

int parent[N];
int depth[N];

int sz[N];    // size of subtree rooted at this node
int heavy[N]; // child with largest subtree (-1 if none)

int head[N]; // first node of heavy chain
int pos[N];  // idx in HLD order (root->node path)

int curPos;  // next available pos in base arr

// Calculate
// 1. subtree size
// 2. heavy child

void dfs(int node, int p) {

  parent[node] = p;
  sz[node] = 1;
  heavy[node] = -1;

  int maxSz = 0;

  for (int child : adj[node]) {
    if (child == p)
      continue;

    depth[child] = depth[node] + 1;

    dfs(child, node);

    sz[node] += sz[child];

    // Child with largest subtree becomes heavy
    if (sz[child] > maxSz) {
      maxSz = sz[child];
      heavy[node] = child;
    }
  }
}

// Break the tree into heavy chain
// Heavy child continues current chain
// Every light child starts a new chain

void decompose(int node, int h) { // h = head of current chain

  head[node] = h;
  pos[node] = curPos++;

  if (heavy[node] != -1) {
    decompose(heavy[node], h);
  }

  // Start new chain from every light child
  for (int child : adj[node]) {

    if (child == parent[node])
      continue;
    if (child == heavy[node])
      continue;

    decompose(child, child);
  }
}

// Keep jumping chain by chain until both nodes
// belong to same heavy chain

int LCA(int u, int v) {
  while (head[u] != head[v]) {
    if (depth[head[u]] > depth[head[v]]) 
      u = parent[head[u]];
    else
      v = parent[head[v]];
  }

  // Both nodes -> same chain then less deeper one is LCA 
  return depth[u] < depth[v] ? u : v;
}

int main(){

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    curPos = 0;
    for(int i = 1; i <= n; i++)
      adj[i].clear();

    for(int node = 1; node <= n; node++){
      int m;
      cin >> m;

      while(m--){
        int child;
        cin >> child;

        adj[node].push_back(child);
        adj[child].push_back(node);
      }
    }

    depth[1] = 0;

    dfs(1,0);
    decompose(1,1);

    int q;
    cin >> q;

    while(q--){
      int u,v;
      cin >> u >> v;
      cout << LCA(u,v) << endl;
    }
  }

  return 0; 
}