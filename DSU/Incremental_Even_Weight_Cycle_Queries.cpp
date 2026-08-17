#include <bits/stdc++.h>
using namespace std;

// Weighted DSU with parity constraint

class DSU {
public:
  vector<int> parent, size, wt;

  // wt[x] = xor from x to parent[x]

  DSU(int n) {
    parent.resize(n, 0);
    size.resize(n, 1);
    wt.resize(n, 0);

    iota(begin(parent), end(parent), 0);
  }

  pair<int, int> find(int x) {

    // If x is root, xor = 0
    if (x == parent[x])
      return {x, 0};

    auto p = find(parent[x]);

    parent[x] = p.first;
    wt[x] ^= p.second; // Xor tells if sum is even or odd (0, 1)

    return {parent[x], wt[x]};
  }

  bool unite(int u, int v, int w) {
    auto [pu, wu] = find(u);
    auto [pv, wv] = find(v);

    if (pu != pv) {
      if (size[pu] > size[pv]) {
        parent[pv] = pu;
        size[pu] += size[pv];
        wt[pv] = wu ^ wv ^ w; // Sum of wt of comp(U) + Sum of wt of comp(V) + current edge wt is even or odd
      } else {
        parent[pu] = pv;
        size[pv] += size[pu];
        wt[pu] = wu ^ wv ^ w;
      }

      // Not connected, can add current edge
      return true;
    }

    // Connected & in cycle, can only add this edge if sum of wt's is even
    return (wu ^ wv ^ w) == 0;
  }
};

class Solution {
public:
  int numberOfEdgesAdded(int n, vector<vector<int>> &edges) {
    DSU dsu(n);

    int cnt = 0;

    for (auto &e : edges) {
      int u = e[0];
      int v = e[1];
      int w = e[2];

      if (dsu.unite(u, v, w))
        cnt++;
    }

    return cnt;
  }
};