#include <bits/stdc++.h>
using namespace std;

// DFS From Each Cell : TC = O(N*M)^2 - TLE 

class Solution {
  public:
  int n,m;
  int row[4] = {0,0,1,-1};
  int col[4] = {1,-1,0,0};

  bool dfsPacific(int r, int c, vector<vector<int>> &heights, vector<vector<bool>> &vis) {
    if(r == 0 || c == 0) return true;

    vis[r][c] = 1;
    for(int k = 0; k < 4; k++){
      int nr = r + row[k];
      int nc = c + col[k];

      if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
        if(heights[r][c] >= heights[nr][nc]){
          if(dfsPacific(nr, nc, heights, vis))
            return true;
        }
      }
    }
    return false;
  }

  bool dfsAtlantic(int r, int c, vector<vector<int>> &heights, vector<vector<bool>> &vis) {
    if(r == n-1 || c == m-1) return true;

    vis[r][c] = 1;
    for(int k = 0; k < 4; k++){
      int nr = r + row[k];
      int nc = c + col[k];

      if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
        if(heights[r][c] >= heights[nr][nc]){
          if(dfsAtlantic(nr, nc, heights, vis)){
            return true;
          }
        }
      }
    }
    return false;
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    n = heights.size();
    m = heights[0].size();

    vector<vector<int>> ans;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        bool pac = dfsPacific(i, j, heights, vis);

        vis.assign(n, vector<bool> (m, 0));
        bool atl = dfsAtlantic(i, j, heights, vis);

        if(pac && atl){
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }
};

// Optimal DFS - Run From Borders Of Pacific & Atlantic Ocean
// TC = O(N * M) | SC = O(N * M)

class Solution {
public:
    int n, m;
    int row[4] = {0, 0, -1, 1};
    int col[4] = {1, -1, 0, 0};

    void dfs(int r, int c, vector<vector<bool>> &vis, vector<vector<int>> &heights){
      vis[r][c] = 1;

      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
          if(heights[nr][nc] >= heights[r][c]){
            dfs(nr, nc, vis, heights);
          }
        }
      }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    n = heights.size();
    m = heights[0].size();

    vector<vector<bool>> pac(n, vector<bool> (m, 0));
    vector<vector<bool>> atl(n, vector<bool> (m, 0));

    // Avoid re-running dfs on already vis cells
    for(int i = 0; i < n; i++){
      if(!pac[i][0]) dfs(i, 0, pac, heights);
      if(!atl[i][m-1]) dfs(i, m-1, atl, heights);
    }

    for(int j = 0; j < m; j++){
      if(!pac[0][j]) dfs(0, j, pac, heights);
      if(!atl[n-1][j]) dfs(n-1, j, atl, heights);
    }

    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(pac[i][j] && atl[i][j]){
          ans.push_back({i, j});
        }
      }
    }
    
    return ans;
    }
};