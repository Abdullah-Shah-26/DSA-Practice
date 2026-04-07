#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! In All 
//* TC = O(N * M) || SC = O(N*M)

//! DFS - Recursive

class Solution {
public:
    int n,m;
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    void dfs(int i,int j,vector<vector<char>> &grid){
      grid[i][j] = '0';

      for(int k = 0; k < 4; k++){
        int nr = i + row[k];
        int nc = j + col[k];

        if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == '0') continue;

        dfs(nr, nc, grid); 
      }
    }

    int numIslands(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int comp = 0;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == '1'){
          comp++;
          dfs(i,j,grid);
        }
      }
    }    

    return comp;
    }
};


//! BFS

class Solution {
public:
    int n,m;
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    void bfs(int i,int j,vector<vector<char>>& grid){
      queue<pair<int,int>> q;
      q.push({i,j});
      grid[i][j] = '0';

      while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();

        for(int k = 0;k < 4;k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] == '0') continue;

          grid[nr][nc] = '0';
          q.push({nr,nc});
        }
      }
    }

    int numIslands(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int comp = 0;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == '1'){
          comp++;
          bfs(i,j,grid);
        }
      }
    }    

    return comp;
    }
};


//! DFS Iterative
class Solution {
public:
    int n,m;
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    void dfsIt(int i, int j, vector<vector<char>> &grid){
      stack<pair<int,int>> st;
      st.push({i,j});

      grid[i][j] = '0';

      while(!st.empty()){
        auto [r, c] = st.top();
        st.pop();

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] == '0') continue;

          grid[nr][nc] = '0';
          st.push({nr,nc});          
        }
      }
    }

    int numIslands(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int comp = 0;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == '1'){
          comp++;
          dfsIt(i,j,grid);
        }
      }
    }    

    return comp;
    }
};