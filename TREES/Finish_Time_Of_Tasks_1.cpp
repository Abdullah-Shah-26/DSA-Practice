#include <bits/stdc++.h>
using namespace std;

// Post - Order DFS
class Solution {
public:
  vector<vector<int>> adj;

  long long dfs(int u, vector<int> &baseTime){
    if(adj[u].empty())
      return baseTime[u];
    
    long long earliest = 1e18; // minTime
    long long latest = -1e18; // maxTime

    for(int v : adj[u]){
      long long childTime = dfs(v, baseTime);

      earliest = min(earliest, childTime);
      latest = max(latest, childTime);
    }

    //     [ Own duration ] + latest
    return (latest - earliest) + baseTime[u] + latest;
  }

  long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
    adj.assign(n, {});

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
    }

    return dfs(0, baseTime);
  }
};