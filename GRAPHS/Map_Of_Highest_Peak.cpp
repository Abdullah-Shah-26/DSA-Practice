#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int,int>> q;


    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == 1){
            grid[i][j] = 0;
            q.push({i,j});
        } else {
            grid[i][j] = -1; // mark as unvisited
        }
      }
    }

    int dirs[5] = {0,1,0,-1,0};

    while(!q.empty()){
      auto [r,c] = q.front(); q.pop();

      for(int k = 0; k < 4; k++){
          int nr = r + dirs[k];
          int nc = c + dirs[k+1];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == -1){
              grid[nr][nc] = grid[r][c] + 1;
              q.push({nr,nc});
          }
      }
    }

    return grid;
    }
};