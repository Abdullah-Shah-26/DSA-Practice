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
    //! Multi Source BFS + BitMasking
    //! TC = O(n * 2^n)
    //! SC = O(n * 2^n)
    int shortestPathLength(vector<vector<int>>& adj) {
    // max nodes = 12
    // states = 2^12 = 4096
    int n = adj.size();
    int finalMask = (1 << n)-1; 
  
    bool vis[n][1 << n];
    memset(vis, 0, sizeof(vis));
    queue<tuple<int,int>>q; // node,mask

    for(int i = 0; i < n; i++){
      int mask = (1 << i);
      q.push({i, mask});
      vis[i][mask] = 1;
    }
    int steps = 0;

    while(!q.empty()){
      int sz = q.size();

      while(sz--){
        auto [node, mask] = q.front();
        q.pop();

        if(finalMask == mask){
          return steps;
        }

        for(auto nei : adj[node]){
          int newMask = mask | (1 << nei);

          if(vis[nei][newMask]) continue;

          vis[nei][newMask] = 1;
          q.push({nei, newMask});
        }
       
      }
      steps++; 
    }
    return steps;
   }
};