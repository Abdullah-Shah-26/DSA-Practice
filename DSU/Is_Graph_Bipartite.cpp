#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! TC = E Alpha(V) || SC = O(V)

class parityDSU{
  public:
  vector<int> parent,size,parity;

  parityDSU(int n){
    parent.resize(n,0);
    size.resize(n,1);
    parity.resize(n,0);

    for(int i = 0; i < n; i++) parent[i] = i;
  }

  pair<int,int> find(int node){
    if(node == parent[node]) return {node, 0};

    auto res = find(parent[node]);

    parent[node] = res.first;
    parity[node] ^= res.second;

    return {parent[node], parity[node]};
  }

  // For Bipartite - we need opposite parity so enfore it
  // 0 - same parity
  // 1 - diff parity

  bool unite(int u, int v){
    // xu - parity from parent[u] to u
    auto [pu, xu] = find(u);
    auto [pv, xv] = find(v);

    if(pu == pv) return  (xu ^ xv) == 1;

    if(size[pu] < size[pv]){
      swap(xu,xv);
      swap(pu,pv);
    }

    size[pu] += size[pv];
    parent[pv] = pu;
    parity[pv] = xu^xv^1;

    return true;
  }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    parityDSU ds(n);

    for(int node = 0; node < n; node++){
      for(auto &nei : adj[node]){
        if(ds.unite(node, nei) == false){
          return false;
        }
      }
    }

    return true;
    }
};
