#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
    // TC = O(N)
    // SC = O(N)

    // Stores Value(idx) -> {Node, Depth}
    vector<pair<int,int>> last = vector<pair<int,int>>(51, {-1,-1});

    void dfs(int node, int parent, int depth, vector<int> &nums,  vector<int> &ans, vector<vector<int>> &adj){

    int bestDepth = -1;
    int bestNode = -1;

    // Finding Closest Coprime Ancestor
    for(int v = 1; v <= 50; v++){
      if(last[v].first == -1) continue;

      if(__gcd(nums[node], v) == 1){
        if(last[v].second > bestDepth){
          bestNode = last[v].first;
          bestDepth = last[v].second;
        }
      }
    }
    ans[node] = bestNode;

    auto prev = last[nums[node]];    
    
    // Put CurrNode in table
    last[nums[node]] = {node, depth};

    // DFS for children
    for(auto child : adj[node]){
      if(child == parent) continue;

      dfs(child, node, depth + 1, nums, ans, adj );
    }
    // After finishing subtree, restore its value // Backtracking
    last[nums[node]] = prev;

    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {

    int n = nums.size();
    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }  

    vector<int>ans(n, -1);
    // node, parent, depth
    dfs(0, -1, 0, nums, ans, adj);

    return ans;
    }
};

//!---------------------------------------------------------------------------
// Reduce GCD Checks by precomputing coprimes

class Solution {
public:
    // TC = O(N)
    // SC = O(N)

    // Stores Value(idx) -> {Node, Depth}
    vector<pair<int,int>> last = vector<pair<int,int>>(51, {-1,-1});
    vector<vector<int>>coprime = vector<vector<int>>(51);

    void dfs(int node, int parent, int depth, vector<int> &nums,  vector<int> &ans, vector<vector<int>> &adj){

    int bestDepth = -1;
    int bestNode = -1;

    // Finding Closest Coprime Ancestor
    for(int v : coprime[nums[node]]){
      if(last[v].first == -1) continue;

        if(last[v].second > bestDepth){
          bestNode = last[v].first;
          bestDepth = last[v].second;
        }
      
    }
    ans[node] = bestNode;

    auto prev = last[nums[node]];    
    
    // Put CurrNode in table
    last[nums[node]] = {node, depth};

    // DFS for children
    for(auto child : adj[node]){
      if(child == parent) continue;

      dfs(child, node, depth + 1, nums, ans, adj );
    }
    // After finishing subtree, restore its value // Backtracking
    last[nums[node]] = prev;

    }

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {

    int n = nums.size();
    vector<vector<int>> adj(n);

    for(auto &e : edges){
      int u = e[0];
      int v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }  

    vector<int>ans(n, -1);

    // Precompute Coprimes 
    for(int i = 1; i <= 50; i++){
      for(int j = 1; j <= 50; j++){
        if(__gcd(i, j) == 1){
          coprime[i].push_back(j);
        }
      }
    }

    // node, parent, depth
    dfs(0, -1, 0, nums, ans, adj);

    return ans;
    }
};