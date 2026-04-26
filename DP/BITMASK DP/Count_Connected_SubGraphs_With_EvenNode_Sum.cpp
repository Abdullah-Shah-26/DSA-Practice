#include <bits/stdc++.h>
using namespace std;

// TC = O(2^N * N) | SC = O(2^N + N)

class Solution {
  public:
    //! DFS
    void dfs(int u, int &mask, int &vis, vector<int> adj[]){
      vis |= (1 << u);

      for(int v : adj[u]){
        if((mask & (1 << v)) && (!(vis & (1 << v))))
          dfs(v, mask, vis, adj);
      }
    }

    //! BFS
    void bfs(int st, int &mask, int &vis, vector<int> adj[]){
      queue<int> q;
      q.push(st);
      vis |= (1 << st);

      while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int &v : adj[u]){
          if((mask & (1 << v)) && (!(vis & (1 << v)))){
            vis |= (1 << v);
            q.push(v);
          }
        }
      }
    }


    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
    int n = nums.size();
    int N = (1 << n);
    
    // Precomputing subset sum Even/Odd
    vector<int> parity(N);
    for(int mask = 1; mask < N; mask++){
      int b = mask & -mask; // Get Last Set Bit
      int j = __builtin_ctz(b); // Idx of that bit

      parity[mask] = parity[mask ^ b] ^ nums[j]; 
    }

    vector<int> adj[n];
    
    for(auto &e : edges){
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int ans = 0;

    // Try all non-empty subsets
    for(int mask = 1; mask < N; mask++){

      if(parity[mask]) // Skip odd sum subsets
        continue;

      // start from any bit of this subset & check if its connected
      int st = __builtin_ctz(mask);
      int vis = 0; 

      dfs(st, mask, vis, adj);
    
      if(vis == mask) // Connected + EvenSum
        ans++;
    }

    return ans;
    }
};