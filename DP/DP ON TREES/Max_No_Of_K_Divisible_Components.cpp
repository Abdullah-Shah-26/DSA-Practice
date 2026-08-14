#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  int cnt;
  vector<vector<int>> adj;

  int dfs(int u, int p, int k, vector<int> &values){
    ll sum = values[u];

    for(int v : adj[u]){
      if(u != p){
        sum += dfs(v, u, k, values);
      }
    }

    sum %= k;

    if(sum == 0)
      cnt++;

    return sum;
  }

  int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k){
    adj.resize(n);

    for(auto e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    cnt = 0; 

    dfs(0, -1, k, values);

    return cnt;
  }
};