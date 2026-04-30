#include <bits/stdc++.h>
using namespace std;

// TC = O(MN Log(MN)) + MN
// SC = MN

class Solution {
  public:
    // If the lowest boundary is not letting water escape, no one will
    // Delegate boundary's work to its nei in all conditions

    typedef tuple<int,int,int> T;
    int trapRainWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    vector<vector<bool>> vis(n, vector<bool> (m, 0));
    priority_queue<T, vector<T>, greater<T>> pq;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(i == 0 || i == n-1 || j == 0 || j == m-1){
          pq.push({grid[i][j], i, j});
          vis[i][j] = 1;
        }
      }
    }

    int water = 0;

    while(!pq.empty()){
      auto [boundary, r, c] = pq.top();
      pq.pop();

      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
          int nei = grid[nr][nc];
          vis[nr][nc] = 1;          

          if(nei < boundary){ // Can Store water in this nei cell
            water += boundary - nei; // The new bound = ht of nei + water stored in it
            pq.push({nei + (boundary-nei), nr, nc});
          }
          else if(nei == boundary){
            pq.push({nei, nr, nc});
          }
          else{ // nei > boundary
            pq.push({nei, nr, nc});
          }
        }
      }
    }

    return water;
    }
};