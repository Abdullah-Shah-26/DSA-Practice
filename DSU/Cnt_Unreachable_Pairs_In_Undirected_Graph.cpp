#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* TC = O(V + E) || SC = O(V)

class DSU {
  public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        return (x == parent[x]) ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
    DSU dsu(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      if(dsu.find(u) != dsu.find(v)){
        dsu.unite(u,v);
      }
    }  

    long long cnt = 0;
    long long remaining = n;
    
    for(int i = 0; i < n; i++){
      if(dsu.find(i) == i){ // Only root of comp has total size 
        long long size = dsu.size[i];
        cnt += size * (remaining - size);
        remaining -= size;
      }
    }

    return cnt;     
    }
};

//! BFS / DFS ------------------------------------------------------|
//* TC = O(V + E) || SC = O(V + E)

class Solution {
  public:
    int dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
      vis[node] = 1;
      int size = 1;

      for(auto& nei : adj[node]){
        if(!vis[nei]){
          size += dfs(nei, vis, adj);
        }
      }

      return size;
    }

    int bfs(int st, vector<int> &vis, vector<vector<int>> &adj){
      int size = 0;
      queue<int> q;

      q.push(st);
      vis[st] = 1;

      while(!q.empty()){
        int node = q.front();
        q.pop();

        size++;

        for(auto &nei : adj[node]){
          if(!vis[nei]){
            vis[nei] = 1;
            q.push(nei);
          }
        }
      }

      return size;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }    

    vector<int> vis(n, 0);
    vector<int> comp; // stores comp sizes
    for(int i = 0; i < n; i++){
      if(!vis[i]){
        // comp.push_back(dfs(i, vis, adj));
        comp.push_back(bfs(i, vis, adj));
      }
    }

    long long cnt = 0;
    long long rem = n;

    for(auto &s : comp){
      cnt += s * (rem - s);
      rem -= s;
    }

    return cnt;
    }
};