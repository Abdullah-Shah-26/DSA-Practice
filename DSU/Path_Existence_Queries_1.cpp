#include <bits/stdc++.h>
using namespace std;

// Without  DSU

class Solution {
public:
  vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries) {

    vector<int> comp(n, -1);
    vector<bool> ans;

    int compId = 0;
    comp[0] = compId;

    for (int i = 1; i < n; i++) {
      if (nums[i] - nums[i - 1] > maxDiff)
        compId++;

      comp[i] = compId;
    }

    for (auto &q : queries) {
      int u = q[0];
      int v = q[1];

      ans.push_back(comp[u] == comp[v]);
    }

    return ans;
  }
};

// Using DSU

class DSU {
public:
  vector<int> parent, sz;

  DSU(int n) {
    parent.resize(n);
    sz.assign(n, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
      return;

    if (sz[a] < sz[b])
      swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
  }
};

class Solution {
public:
  vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries) {

    DSU dsu(n);

    for (int i = 1; i < n; i++) {
      if (nums[i] - nums[i - 1] <= maxDiff)
        dsu.unite(i, i - 1);
    }

    vector<bool> ans;

    for (auto &q : queries)
      ans.push_back(dsu.find(q[0]) == dsu.find(q[1]));

    return ans;
  }
};