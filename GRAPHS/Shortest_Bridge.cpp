#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Multi Source BFS
class Solution {
public:
    int n;
    int m;

    void dfs(int r, int c, vector<vector<int>> &grid, queue<pair<int,int>> &q){
    
    // Invalid Checks
    if(r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != 1) return;

    // Mark as visited
    grid[r][c] = 2;

    // For BFS
    q.push({r, c});

    dfs(r+1,c,grid,q);
    dfs(r-1,c,grid,q);
    dfs(r,c+1,grid,q);
    dfs(r,c-1,grid,q);
    }

    int shortestBridge(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();

    queue<pair<int,int>>q;

    bool found = false;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == 1){
          found = true;
          dfs(i, j, grid, q);
          break;
        }
      }
      if(found){
        break;
      }
    }
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    int steps = 0;

    while(!q.empty()){
      int sz = q.size();

      while(sz--){
        auto it = q.front();
        q.pop();
        int r = it.first;
        int c = it.second;

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 2){
            if(grid[nr][nc] == 1){
              return steps;
            }

            if(grid[nr][nc] == 0){
              grid[nr][nc] = 2;
              q.push({nr,nc});
            }
          }
        }
      }
      steps++;
    }
    return -1;
    }
};

//! MULTI-SOURCE BFS + ITERATIVE DFS
// TODO : Find 1 island, apply dfs & mark that whole group of island as visited and put in q

class Solution {
public:
    int n;
    int m;

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    void dfsIterative(int r, int c, vector<vector<int>> &grid, queue<pair<int,int>> &q){
      stack<pair<int,int>>st;
      st.push({r,c});

      while(!st.empty()){
        auto it = st.top();
        st.pop();

        int r = it.first;
        int c = it.second;

        // Invalid check
        if(r < 0  || r >= n || c < 0 || c >= m || grid[r][c] != 1){
          continue;
        }

        // mark visited
        grid[r][c] = 2;

        // push in q for MultiSource bfs
        q.push({r, c});

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];
          
          if(nr >= 0 && nr < n && nc >= 0 && nc < m)
    st.push({nr,nc});
        }
      }
    }

    int shortestBridge(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();

    queue<pair<int,int>>q;

    bool found = false;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == 1){
          found = true;
          dfsIterative(i, j, grid, q);
          break;
        }
      }
      if(found){
        break;
      }
    }
   

    int steps = 0;

    while(!q.empty()){
      int sz = q.size();

      while(sz--){
        auto it = q.front();
        q.pop();
        int r = it.first;
        int c = it.second;

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 2){
            if(grid[nr][nc] == 1){
              return steps;
            }

            if(grid[nr][nc] == 0){
              grid[nr][nc] = 2;
              q.push({nr,nc});
            }
          }
        }
      }
      steps++;
    }
    return -1;
    }
};