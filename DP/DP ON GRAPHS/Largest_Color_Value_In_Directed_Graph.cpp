#include <bits/stdc++.h>
using namespace std;

// Graph DP + Topo - Khan's

// TC = O(V + E) * 26
// SC = O(V + E) + O(V * 26) + O(V)

class Solution {
  public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();

    vector<int> adj[n];
    vector<int> indeg(n,0);

    for(auto &e: edges){
      int u = e[0];
      int v = e[1];

      indeg[v]++;
      adj[u].push_back(v);
    }

    queue<int> q;

    for(int i = 0; i < n; i++){
      if(indeg[i] == 0){
        q.push(i);
      }
    }    

    int processed = 0;
    vector<vector<int>> dp(n, vector<int>(26, 0));

    // dp[u][c] = max cnt of nodes with color c of any path ending at u

    for(int i = 0; i < n; i++){
      dp[i][colors[i] - 'a'] = 1;
    }

    int ans = 1;

    while(!q.empty()){
      int u = q.front();
      q.pop();
      
      processed++;

      for(int v : adj[u]){

        for(int c = 0; c < 26; c++){
          dp[v][c] = max(dp[v][c], dp[u][c] + (colors[v]-'a' == c)); 
          ans = max(ans, dp[v][c]);
        }

        indeg[v]--;

        if(indeg[v] == 0){
          q.push(v);
        }
      }
    }

    if(processed != n){
      return -1; // Cycle Exist
    }

  return ans;  
  }
};