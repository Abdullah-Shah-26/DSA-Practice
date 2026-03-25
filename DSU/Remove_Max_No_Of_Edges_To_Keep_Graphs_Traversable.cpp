#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// M = No of Edges
// N = No of Nodes
//! TC = O(M Log M + M Alpha(N))
//! SC = O(N + M)

class DSU{
  public: 
  vector<int>parent,sz;
  int components;

  DSU(int n){
    parent.resize(n+1);
    sz.resize(n+1,1);
    components = n;

    for(int i = 1; i <= n; i++) parent[i] = i;
  }

  int find(int node){
    while(node != parent[node]){
      parent[node] = parent[parent[node]];
      node = parent[node];
    }
    return node;
  }

  void unite(int u,int v){
    u = find(u);
    v = find(v);

    if(u == v) return;

    if(sz[u] < sz[v]) swap(u,v);

    parent[v] = u;
    sz[u] += sz[v];

    components--;
  }

  bool isSingleComp(){
    return components == 1;
  }

};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    int edgeCnt = 0;
    DSU Alice(n);
    DSU Bob(n);

    auto cmp = [&](const vector<int> &arr1, const vector<int> &arr2){
      return arr1[0] > arr2[0];
    };

    sort(begin(edges), end(edges),cmp);

    for(auto &e : edges){
      int type = e[0];
      int u = e[1];
      int v = e[2];

      bool addedEdge = 0;
      
      if(type == 3){

          if(Alice.find(u) != Alice.find(v)){
            Alice.unite(u,v);
            addedEdge = 1;
          }

          if(Bob.find(u) != Bob.find(v)){
            Bob.unite(u,v);
            addedEdge = 1;
          }

          if(addedEdge){
            edgeCnt++;
          }
      } 
      else if(type == 2){
         
          if(Bob.find(u) != Bob.find(v)){
            Bob.unite(u,v);
            edgeCnt++;
          }
      }
      else{

          if(Alice.find(u) != Alice.find(v)){
            Alice.unite(u,v);
            edgeCnt++;
          }
      } 

    }

    if(Alice.isSingleComp() == 1 && Bob.isSingleComp() == 1){
      return edges.size() - edgeCnt;
    }

    return -1;
    }
};