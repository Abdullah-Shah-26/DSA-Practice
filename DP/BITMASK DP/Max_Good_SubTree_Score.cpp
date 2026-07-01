#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
  // O(N)
  void dfs(int node, vector<bool> &vis, vector<int> adj[], vector<int> &vals, vector<int> &subTreeNodes){
    if(vis[node])
      return;

    vis[node] = true;
    subTreeNodes.push_back(vals[node]);

    for(int nei : adj[node]){
      if(!vis[nei]){
        dfs(nei, vis, adj, vals, subTreeNodes);
      }
    }
  } 

  // Rejects If
  // Digit already used by previous selected number
  // Current No has repeated digit, Ex : 424
  bool canPick(int num, int mask){ // O(LogN)
    while(num > 0){
      int rem = num % 10;

      if(mask & (1 << rem))
        return false;
    
      mask |= (1 << rem);
      num /= 10;
    }
    return true;
  }

  // O(N * 1024)
  int getMaxSum(int i, int mask, vector<int> &subTreeNodes, vector<vector<int>> &dp){
    if(i >= subTreeNodes.size())
      return 0;

    if(dp[i][mask] != -1)
      return dp[i][mask];

    int skip = getMaxSum(i + 1, mask , subTreeNodes, dp);
    int take = 0;

    if(canPick(subTreeNodes[i], mask)){
      int num = subTreeNodes[i];
      int newMask = mask;

      while(num > 0){ // O(LogN)
        int rem = num % 10;
        newMask = newMask | (1 << rem);
        num /= 10;
      }

      take = subTreeNodes[i] + getMaxSum(i + 1, newMask, subTreeNodes, dp);
    }

    return dp[i][mask] = max(take, skip);
  }

  int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
    int n = vals.size();
    vector<int> adj[n];

    for(int i = 1; i < n; i++)
      adj[par[i]].push_back(i);

    int ans = 0;
    for(int i = 0; i < n; i++){ // O(N^2 * 1024)
      vector<bool> vis(n, false);
      vector<int> subTreeNodes; // Stores value of nodes in subtree rooted at each node
      dfs(i, vis, adj, vals, subTreeNodes);

      // KnapSack dp to find max sum in that subtree
      // Bitmask to mark used digits
      // (0-9) = 10 digits
      // 2^10 = 1024 masks

      vector<vector<int>> dp(subTreeNodes.size() + 1, vector<int> (1024, -1));
      ans = (ans + getMaxSum(0, 0, subTreeNodes, dp)) % MOD;
    }

    return ans;
  }
};