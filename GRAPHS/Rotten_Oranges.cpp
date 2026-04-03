#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS Multi-Source

class Solution {
  public:
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    int orangesRotting(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();

      queue<pair<int,int>> q;

      int fresh = 0;

      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

          if(grid[i][j] == 1) fresh++;
          
          if(grid[i][j] == 2){
            q.push({i,j});
          }
        }
      } 

      int t = 0;
      while(!q.empty()){
        int sz = q.size();
        bool spread = 0;

        while(sz--){
          auto [r,c] = q.front();
          q.pop();

          for(int k = 0; k < 4; k++){
            int nr = r + row[k];
            int nc = c + col[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
              spread = 1;
              fresh--;
              grid[nr][nc] = 2;
              q.push({nr,nc});
            }
          }
        }

        if(spread) t++;
      }

      return fresh != 0 ? -1 : t;
    }
};