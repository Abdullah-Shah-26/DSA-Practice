#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS / DFS --- TLE
//* TC = (V * (V + E)) || SC = O(V + E)

class Solution {
public:
    int n,m;

    int bfs(int st, vector<vector<int>> &adj){
      vector<bool> vis(n, 0);
      queue<pair<int,int>> q;

      q.push({st, 0}); // node, dist
      vis[st] = 1;

      int sum = 0;

      while(!q.empty()){
        auto [node, dist] = q.front();
        q.pop();

        sum += dist;

        for(auto &nei : adj[node]){
          if(!vis[nei]){
            vis[nei] = 1; 
            q.push({nei, dist + 1});
          }
        }
      }

      return sum;
    }

    int dfs(int node, int parent, int depth, vector<vector<int>> &adj){
      int sum = depth;

      for(auto &nei: adj[node]){
        if(nei == parent) continue;
        sum += dfs(nei, node, depth + 1, adj);
      }

      return sum;
    }

    vector<int> sumOfDistancesInTree(int _n, vector<vector<int>>& edges) {
    n = _n;
    m = edges.size();

    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> ans(n,0);

    for(int i = 0; i < n; i++){
      ans[i] = dfs(i,-1,0,adj);
    }

    return ans;
    }
};

//! Rerooting DP
  