#include <bits/stdc++.h>
using namespace std;

// TopDown DP (Memoization)
class Solution {
  public:
    vector<int> dp;
    int dfs(int i, vector<int> adj[], vector<int> &quiet){
      int quietest = i; // assuming

      if(dp[i] != -1) return dp[i];

      for(int &nei : adj[i]){
        int candidate = dfs(nei, adj, quiet);

        if(quiet[candidate] < quiet[quietest]){
          quietest = candidate;
        }
      }

      return dp[i] = quietest;
    }

    vector<int> loudAndRich(vector<vector<int>>& edges, vector<int>& quiet) {
    int n = quiet.size();

    vector<int> adj[n];

    for(auto &e : edges){
      int u = e[0];
      int v = e[1]; 

      adj[v].push_back(u);
    }    

    vector<int> ans(n);
    dp.assign(n, -1);
    for(int i = 0; i < n; i++){
      ans[i] = dfs(i, adj, quiet);
    }

    return ans;
    }
};

//! Bottom Up DP
// TC = O(V + E) | SC = O(V + E)e

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& edges, vector<int>& quiet) {
    // DP on DAG
    int n = quiet.size();

    vector<int> indeg(n, 0);
    vector<int> adj[n];

    for(auto &e : edges){
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
    
    // ans[i] = queitest richer/equal person for i
    vector<int> ans(n, 0);
    iota(ans.begin(), ans.end(), 0);

    while(!q.empty()){
      int u = q.front();
      q.pop();

      for(int v : adj[u]){
        // Like dp[v] = better(dp[u], dp[v])
        if(quiet[ans[u]] < quiet[ans[v]]){
          ans[v] = ans[u];
        }

        indeg[v]--;
        
        if(indeg[v] == 0){
          q.push(v);
        }
      }
    }
    return ans; 
    }
};