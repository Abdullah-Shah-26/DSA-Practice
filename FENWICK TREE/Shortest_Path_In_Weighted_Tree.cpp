#include <bits/stdc++.h>
using namespace std;

// Overall : 
// TC = O(N + QLogN)
// SC = O(N)

//! Euler Tour + Fenwick Tree

class Fenwick{
  public: 
  int n;
  vector<int> bit;

  Fenwick(int n){
    this-> n = n;
    bit.resize(n + 1, 0);
  }

  void update(int i, int delta){
    while(i <= n){
      bit[i] += delta;
      i += (i & -i);
    }
  }

  int query(int i){
    int sum = 0;
    while(i > 0){
      sum += bit[i];
      i -= (i & -i);
    }
    return sum;
  }
};

class Solution {
  public:
    vector<vector<pair<int,int>>> adj;
    vector<int> tin;
    vector<int> tout;
    vector<int> parent;
    vector<int> dist;
    vector<int> ans;
    int timer;

    void dfs(int u, int p){
      tin[u] = ++timer;
      parent[u] = p;

      for(auto [v, w] : adj[u]){
        if(v == p) continue;
        dist[v] = dist[u] + w;
        dfs(v, u);
      }
      tout[u] = timer;
    }

    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {

    adj.assign(n + 1, {});
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    dist.assign(n + 1, 0);
    Fenwick ft(n + 2);
    timer = 0;

    map<pair<int,int>,int> edgeIdx; // To recover old edgeWt

    for(int i = 0; i < edges.size(); i++){
      auto &e = edges[i];

      int u = e[0];
      int v = e[1];
      int w = e[2];

      int a = min(u,v);
      int b = max(u,v);

      edgeIdx[{a,b}] = i;

      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }

    dfs(1, 0);

    // for(int i = 1; i <= n; i++){
    //   ft.update(tin[i], dist[i]);
    // }

    for(int i = 0; i < q.size(); i++){
      auto it = q[i];
      int type = it[0];

      if(type == 1){ // Update
        int u = it[1];
        int v = it[2];
        int newW = it[3];

        // Recovering old wt of (u,v)
        int a = min(u,v);
        int b = max(u,v);

        int idx = edgeIdx[{a,b}];
        int oldW = edges[idx][2];

        // The subtree of child gets affects 
        int child = -1;

        if(parent[u] == v) child = u;
        else child = v;
        
        int delta = newW - oldW;

        // Update oldW
        edges[idx][2] = newW;

        ft.update(tin[child], +delta);
        ft.update(tout[child] + 1, -delta);
      }
      else if(type == 2){ // Shortest path dist from root to x
        int x = it[1];
        ans.push_back(dist[x]  + ft.query(tin[x]));
      }
    }
    return ans;
    }
};