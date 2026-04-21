#include <bits/stdc++.h>
using namespace std;

//* BFS
class Solution {
  public:
    int n,m;
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    void bfs(int si, int sj, vector<vector<int>> &grid){

      queue<pair<int,int>> q;
      q.push({si,sj});
      grid[si][sj] = 0;

      while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
            grid[nr][nc]  = 0;
            q.push({nr, nc});
          }
        }
      }
    }

    int numEnclaves(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();

    int cnt = 0;

    for(int j = 0; j < m; j++){
      if(grid[0][j] == 1){
        bfs(0, j, grid);
      }

      if(grid[n-1][j] == 1){
        bfs(n-1, j, grid);
      }
    }

    for(int i = 0; i < n; i++){
      if(grid[i][0] == 1){
        bfs(i, 0, grid);
      }

      if(grid[i][m-1] == 1){
        bfs(i, m-1, grid);
      }
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == 1){
          cnt++;
        }
      }
    }

    return cnt;
    }
};

//* DFS

class Solution {
  public:
    int n,m;
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    void dfs(int i, int j, vector<vector<int>> &grid){
      grid[i][j] = 0;

      for(int k = 0; k < 4; k++){
        int nr = i + row[k];
        int nc = j + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
          dfs(nr, nc, grid);
        }
      }
    }

    int numEnclaves(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();

    int cnt = 0;

   for(int j = 0; j < m; j++){
      if(grid[0][j] == 1)
        dfs(0, j, grid);

      if(grid[n-1][j] == 1)
        dfs(n-1, j, grid);
   }

   for(int i = 0; i < n; i++){
    if(grid[i][0] == 1)
      dfs(i, 0, grid);

    if(grid[i][m-1] == 1)
      dfs(i, m-1, grid);
   }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == 1){
          cnt++;
        }
      }
    }

    return cnt;
    }
};