#include <bits/stdc++.h>
using namespace std;

// TC = O(N)
using ll = long long;

class Solution {
public:
  vector<ll> ans;
  vector<int> cost;
  vector<vector<int>> adj;

  vector<ll> dfs(int u, int p, int &sz){
  
    sz = 1; // Initally we have node & its cost
    vector<ll> vals = {cost[u]}; 

    for(int v : adj[u]){
      if(v == p) continue;

      int childSz;
      vector<ll> childVals = dfs(v, u, childSz);

      sz += childSz; 
      for(auto &x : childVals)
        vals.push_back(x);
    }

    sort(begin(vals), end(vals));

    if(sz < 3) // We can only place 1 coin
      ans[u] = 1; 
    else{
      // Product of Last 3 values 
      int m = vals.size();
      ll best = vals[m-1] * vals[m-2] * vals[m-3];

      // Product of First 2 -ve's * Last +ve = Overall +ve
      if(m >= 3)
        best = max(best, vals[0] * vals[1] * vals[m-1]);

      ans[u] = max(0LL, best); // If everything is -ve we place 0 coin
    }

    // Pass rest of values (First 2 & Last 3) to children
    vector<ll> keep;

    int m = vals.size();
    for(int i = 0; i < min(m, 2); i++)
      keep.push_back(vals[i]);

    for(int i = max(2, m-3); i < m; i++)
      keep.push_back(vals[i]);

    return keep;
  }

  vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
  int n = cost.size();

  this->cost = cost;

  adj.assign(n, {});
  ans.resize(n, 0);

  for(auto &e : edges){
    int u = e[0];
    int v = e[1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }      
  
  int dummy;
  dfs(0, -1, dummy);

  return ans;
  }
};