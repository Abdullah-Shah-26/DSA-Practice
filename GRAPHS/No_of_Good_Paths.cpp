#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class DSU{
  public:
  vector<int> parent,sz;

  DSU(int n){
    parent.resize(n,0);
    sz.resize(n,1);

    for(int i = 1; i < n; i++) parent[i] = i;
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
  }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& val, vector<vector<int>>& edges) {
    int n = val.size();   
    // N = Nodes
    // E = Edges

    vector<vector<int>> adj(n);

    for(auto &e : edges){ //! O(E)
      int u = e[0], v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    DSU dsu(n);

    map<int, vector<int>> valToNodes;

    for(int i = 0;i < n; i++){ //! O(N)
      int value = val[i];
      valToNodes[value].push_back(i);
    }

    long long ans = n;

    vector<bool> isActive(n, 0);

    for(auto &it : valToNodes){
      vector<int> nodes = it.second;

      for(auto &u : nodes){
        for(auto &v : adj[u]){
          if(isActive[v]){
            dsu.unite(u,v);
          }
        }
        isActive[u] = 1;
      }

      vector<int> leaders;

      for(auto &u : nodes){
        int parent = dsu.find(u);
        leaders.push_back(parent);
      }

      int m = leaders.size();
      sort(leaders.begin(), leaders.end()); //! O(N Log N)
      for(int j = 0; j < m; j++){
        long long cnt = 0;
        int curParent = leaders[j];

        // If the nodes are in single component, increase count, cause they can form valid paths
        while(j < m && leaders[j] == curParent){
          cnt++;
          j++;
        }
        j--;

        ans += (cnt * (cnt - 1))/2;
      }
    }

    return ans;
    }
};