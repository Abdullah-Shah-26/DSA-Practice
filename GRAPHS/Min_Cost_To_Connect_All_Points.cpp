#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Kruskal Algorithm
//! Overall TC = O(N^2 Log N)
//! SC = O(N^2)
struct DSU{
  vector<int> parent,sz;

  DSU(int n){
    parent.resize(n);
    sz.resize(n,1);

    for(int i = 0; i < n; i++) parent[i] = i;
  }

  int find(int x){
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
  }

  bool unite(int u,int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0;

    if(sz[u] < sz[v]) swap(u,v);

    parent[v] = u;
    sz[u] += sz[v];

    return 1;
  }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
    vector<vector<int>> edges;    
    int n = points.size();
    for(int i = 0; i < n; i++){ //! O(N^2)
      for(int j = i + 1; j < n; j++){

        int x1 = points[i][0];
        int y1 = points[i][1];

        int x2 = points[j][0];
        int y2 = points[j][1];

        int dist = abs(x1-x2) + abs(y1-y2);

        edges.push_back({i,j,dist});
      }
    }

    auto cmp = [&](const vector<int> &a, const vector<int> &b){
      return a[2] < b[2];
    };

    sort(begin(edges), end(edges), cmp); //! O(N^2 Log (N))
    
    DSU dsu(n);

    int sum = 0;

    for(auto &e : edges){ //! O(E alpha(n)) == O(N^2)
      int u = e[0];
      int v = e[1];
      int wt = e[2];

      if(dsu.unite(u,v)){
        sum += wt;
      }
    }

    return sum;  
    }
};