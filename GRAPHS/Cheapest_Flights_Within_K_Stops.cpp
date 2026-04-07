#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS on Layers 
//* TC = O(V*E)   ||  SC = O(V+E)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
    vector<pair<int,int>> adj[n];

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      int wt = e[2];

      adj[u].push_back({v,wt});
    }

    vector<int> dist(n, INT_MAX);
    
    queue<pair<int,int>> q;
    q.push({src, 0});    
    
    dist[src] = 0;

    int steps = 0;
    while(!q.empty() && steps <= k){
      int size = q.size();

      while(size--){
        auto it = q.front();
        q.pop();

        int node = it.first;
        int dis = it.second;

        for(auto &nei : adj[node]){
          int adjNode = nei.first;
          int edWt = nei.second;

          if(dis + edWt < dist[adjNode]){
            dist[adjNode] = dis + edWt;
            q.push({adjNode, dist[adjNode]});
          }
        }
      }

      steps++;
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

//! DP on edges
//* TC = O(K*E)  || SC = O(K*N)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<int>> dp(k + 2, vector<int> (n, INT_MAX));

    // edges, node = min cost to reach this node via using exactly these edges
    dp[0][src] = 0; // 0 Cost to reach src using 0 edges
    
    for(int edges = 1; edges <= k+1; edges++){
      for(auto &e : flights){
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if(dp[edges-1][u] == INT_MAX) continue;

        dp[edges][v] = min(dp[edges][v], dp[edges-1][u] + w);
      }
    }

    int ans = INT_MAX;
    for(int edges = 0; edges <= k + 1; edges++){
      ans = min(ans,dp[edges][dst]);
    }

    return ans == INT_MAX ? -1 : ans;
    }
};

//* Space Optimized 
//* SC = O(N)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> prev(n, INT_MAX);
    int ans = INT_MAX;

    // edges, node = min cost to reach 
    prev[src] = 0; // 0 Cost to reach src using 0 edges
    
    for(int edges = 1; edges <= k+1; edges++){
      vector<int> cur(n, INT_MAX);
      for(auto &e : flights){
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if(prev[u] == INT_MAX) continue;

        cur[v] = min(cur[v], prev[u] + w);
      }
      ans = min(ans, cur[dst]);
      prev = cur;
    }
    return ans == INT_MAX ? -1 : ans;
    }
};