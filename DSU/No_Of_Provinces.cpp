#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = O(N^2 * Alpha(N)) - Inverse Ackerman const
//! SC = O(N)

class DSU{
  public:
    int components;
    vector<int> parent, size;
    
    DSU(int n){
      parent.resize(n, 0);
      size.resize(n, 1);
      components = n;
      for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x){
      if(x == parent[x]) return x;

      return parent[x] = find(parent[x]);
    }

    void merge(int u,int v){
      u = find(u);
      v = find(v);

      if(u == v) return;

      if(size[u] < size[v]) swap(u,v);

      parent[v] = u;
      size[u] += size[v];

      components--;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
    int n = adj.size();
    DSU dsu(n);

    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        if(adj[i][j] == 1){
          dsu.merge(i, j);
        }
      }
    } 
    
    return dsu.components;
    }
};