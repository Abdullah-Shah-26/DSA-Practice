#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS - Get Diameter
//! TC = O(N) |  SC = O(N)

class Solution {
  public:
    pair<int,vector<int>> getDiameterPath(int st, vector<vector<int>> &adj){
      int n = adj.size();
      
      vector<int> dist(n, -1);
      vector<int> parent(n, -1);
      queue<int> q;

      q.push(st);
      dist[st] = 0;

      int farthest = st;

      while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto& nei : adj[node]){
          if(dist[nei] == -1){
            parent[nei] = node;
            dist[nei] = dist[node] + 1;

            if(dist[nei] > dist[farthest]){
              farthest = nei;
            } 

            q.push(nei);
          }
        }
      }
     

    //* Reconstruct Path
    vector<int> path;
    int cur = farthest;

    while(cur != -1){
      path.push_back(cur);
      cur = parent[cur];
    }

    reverse(begin(path), end(path));

    return {farthest, path};
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }    

    auto [farthestNode1, _] = getDiameterPath(0, adj);
    auto [farthestNode2, path] = getDiameterPath(farthestNode1, adj);

    int m = path.size();

    if(m & 1){
      return {path[m/2]};
    }

    return {path[m/2 - 1], path[m/2]};
    }
};

//! DFS 

class Solution {
  public:
    void dfsFarthest(int node, int p, int depth, vector<vector<int>> &adj, vector<int> &parent, int &farthest, int &maxDist){
      parent[node] = p;

      if(depth > maxDist){
        maxDist = depth; 
        farthest = node;
      }

      for(auto &nei : adj[node]){
        if(nei == p) continue;

        dfsFarthest(nei, node, depth + 1, adj, parent, farthest, maxDist);
      }
    }

    vector<int> buildPath(int cur, vector<int> &parent){
      vector<int> path;

      while(cur != -1){
        path.push_back(cur);
        cur = parent[cur];
      }

      reverse(begin(path), end(path));
      return path;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n == 1) return {0};

    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }    

    vector<int> parent(n, -1);

    // Find one endPoint of diameter
    int st = 0, dist = -1;
    dfsFarthest(0, -1, 0, adj, parent, st, dist);

    // Find other endPoint of diameter
    int end = 0;
    dist = -1;
    fill(parent.begin(), parent.end(), -1);
    dfsFarthest(st, -1, 0, adj, parent, end, dist);

    vector<int> path = buildPath(end, parent);

    int m = path.size();

    if(m & 1){
      return {path[m/2]};
    }
    
    return {path[m/2-1], path[m/2]};
    }
};