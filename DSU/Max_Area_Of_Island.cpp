#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DFS ----------------------------------------------------
//* TC = O(N * M)
//* SC = O(N * M)

class Solution {
  public:
    int n,m;

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    int dfs(int i,int j,vector<vector<int>> &grid){
      grid[i][j] = 0;
      int cnt = 1;

      for(int k = 0; k < 4; k++){
        int nr = i + row[k];
        int nc = j + col[k];

        if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc]==0) continue;
          
        cnt += dfs(nr, nc, grid);
      }

      return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
      n = grid.size();
      m = grid[0].size();
      int maxCnt = 0;

      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          if(grid[i][j] == 1){
            maxCnt = max(maxCnt, dfs(i, j, grid));
          }
        }
      }

      return maxCnt;
    }
};

//! BFS -----------------------------------------------------
//* Same TC & SC except without recursion overhead

class Solution {
public:
  int n,m;
    
  int row[4] = {0,0,-1,1};
  int col[4] = {1,-1,0,0};

  int bfs(int i,int j, vector<vector<int>> &grid){
    queue<pair<int,int>>q;
    q.push({i,j});
    int area = 1;
    grid[i][j] = 0;

    while(!q.empty()){
      auto [r,c] = q.front();
      q.pop();
      
      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
          grid[nr][nc] = 0; // mark as visited
          q.push({nr,nc});
          area++;
        }
      }
    }
    return area;
  }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();

    int ans = 0;

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        if(grid[i][j] == 1)
          ans = max(ans, bfs(i, j, grid));
              
    return ans;    
    }
};

//! DSU -----------------------------------------------------------------
//* Unnecessary Complicated Here

//! 8 directions 
class Solution {
  public:
    
    int n,m;
        
    int row[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int col[8] = {-1, 0, 1,-1, 1,-1, 0, 1};
    
    int dfs(int i,int j, vector<vector<int>> &grid){
        int cnt = 1;
        grid[i][j] = 0;
        
        for(int k = 0; k < 8; k++){
            int nr = i + row[k];
            int nc = j + col[k];
            
            if(nr < 0 || nr >= n || n < 0 || nc >= m || grid[nr][nc] == 0) continue;
            
            cnt += dfs(nr, nc, grid);
        }
        
        return cnt;
    }
    
    // Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        n = grid.size();
        m = grid[0].size();
        int maxCnt = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0;j < m; j++){
                if(grid[i][j] == 1){
                    maxCnt = max(maxCnt, dfs(i,j,grid));                    
                }
            }
        }
        
        return maxCnt;
    }
};  