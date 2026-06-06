#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
class Solution {
public:
  int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passFees) {
  int m = edges.size();
  int n = passFees.size(); 
  int ans = INF;   

  // dp[t][u] = min cost to reach city u in exactly t time
  vector<vector<int>> dp(maxTime + 1, vector<int> (n, INF));
  dp[0][0] = passFees[0];

  for(int t = 0; t <= maxTime; t++){
    for(auto &e : edges){
      int u = e[0], v = e[1], w = e[2]; // w minutes

      if(t + w > maxTime)
        continue;

      // Bi-directional Roads
      // Enter v, payFee[v]
      if(dp[t][u] != INF)
        dp[t + w][v] = min(dp[t + w][v], dp[t][u] + passFees[v]);

      // Enter u, payFee[v]
      if(dp[t][v] != INF)
        dp[t + w][u] = min(dp[t + w][u], dp[t][v] + passFees[u]);
    }

    ans = min(ans, dp[t][n - 1]);
  }

  return ans == INF ? -1 : ans;
  }
};