#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
  vector<int> parent;
  vector<int> size;

  DSU(int n) {
    parent.resize(n);
    size.assign(n, 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
      return;

    if (size[u] < size[v])
      swap(u, v);

    parent[v] = u;
    size[u] += size[v];
  }
};

class Solution {
public:
  vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    
    DSU dsu(n);

    for (auto &e : edges) 
      dsu.merge(e[0], e[1]);
    
    // And of every connected component
    vector<int> compAnd(n, INT_MAX);

    for(auto &e : edges){
      int u = e[0], v = e[1], w = e[2];
      int root = dsu.find(u);
      compAnd[root] &= w;
    }

    vector<int> ans;

    for(auto &q : query){
      int u = q[0];
      int v = q[1];

      if(dsu.find(u) != dsu.find(v)) // u to v are in different components 
        ans.push_back(-1);
      else if(u == v) // No edges in b/w u & v, cost = 0
        ans.push_back(0);
      else       
        ans.push_back(compAnd[dsu.find(u)]);
    }

    return ans;
  }
};