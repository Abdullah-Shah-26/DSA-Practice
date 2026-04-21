#include <bits/stdc++.h>
using namespace std;

//* DFS
class Solution {
  public:
    int n,m;

    bool dfs(int i, int j, vector<vector<int>> &grid){
      
      if(i < 0 || i >= n || j < 0 ||  j >= m)
        return 0; // We meet boundary

      if(grid[i][j] == 1)
        return 1; 

      grid[i][j] = 1;
      int up = dfs(i-1, j, grid);
      int down = dfs(i+1, j, grid);
      int left = dfs(i, j-1, grid);
      int right = dfs(i, j+1, grid);

      return up & down & left & right; 
    }

    int closedIsland(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();

    int cnt = 0;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == 0){
          cnt += dfs(i, j, grid);
        }
      }
    }

    return cnt;
    }
};

//* BFS

class Solution {
  public:
    int n,m;
    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0}; 

    bool bfs(int si, int sj, vector<vector<int>> &grid){
      queue<pair<int,int>> q;
      q.push({si,sj});
      grid[si][sj] = 1;

      bool closed = true;

      while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();

        if(r == 0 || r == n-1 || c == 0 || c == m-1)
          closed = false;

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >=0 && nc < m && grid[nr][nc] == 0){
          q.push({nr,nc});
          grid[nr][nc] = 1;
        }
      }
    }

      return closed;
  }

    int closedIsland(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int cnt = 0;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == 0){
          cnt += bfs(i, j, grid);
        }
      }
    }    

    return cnt;
    }
};