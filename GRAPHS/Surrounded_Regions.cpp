#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DFS Recursive

class Solution {
public:
    int n,m;
    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0};
    
    void dfs(int i,int j,vector<vector<char>> &mat, vector<vector<bool>> &vis){
      vis[i][j] = 1;

      for(int k = 0; k < 4; k++){
        int nr = i + row[k];
        int nc = j + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mat[nr][nc] == 'O'){
          dfs(nr,nc,mat,vis);
        }
      }
    }

    void solve(vector<vector<char>>& mat) {
    n = mat.size();
    m = mat[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,0));

    for(int j = 0; j < m; j++){
      // First Row
      if(!vis[0][j] && mat[0][j] == 'O') dfs(0,j,mat,vis);
      // Last Row
      if(!vis[n-1][j] && mat[n-1][j] == 'O') dfs(n-1,j,mat,vis);
    }

    for(int i = 0; i < n; i++){
      // First Col
      if(!vis[i][0] && mat[i][0] == 'O') dfs(i,0,mat,vis);
      // Last Col
      if(!vis[i][m-1] && mat[i][m-1] == 'O') dfs(i,m-1,mat,vis);
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(!vis[i][j] && mat[i][j] == 'O'){
          mat[i][j] = 'X';
        }
      }
    }
    }
};

//! DFS - Iterative

class Solution {
public:
    int n,m;
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    // Iterative DFS
    void dfs(int i,int j, vector<vector<bool>> &vis, vector<vector<char>> &mat){
      
      vis[i][j] = 1;
      stack<pair<int,int>> st;
      st.push({i,j});

      while(!st.empty()){
        auto [r,c] = st.top();
        st.pop();

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mat[nr][nc] == 'O'){
            vis[nr][nc] = 1;
            st.push({nr,nc});
          }
        }
      }
    }

    void solve(vector<vector<char>>& mat) {
    n = mat.size();    
    m = mat[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    for(int j = 0; j < m; j++){
      // First Row
      if(!vis[0][j] && mat[0][j] == 'O') dfs(0,j,vis,mat);
      // Last Row
      if(!vis[n-1][j] && mat[n-1][j] == 'O') dfs(n-1,j,vis,mat);
    }

    for(int i = 0; i < n; i++){
      // First Col
      if(!vis[i][0] && mat[i][0] == 'O') dfs(i,0,vis,mat);
      // Last Col
      if(!vis[i][m-1] && mat[i][m-1] == 'O') dfs(i,m-1,vis,mat);
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(mat[i][j] == 'O' && !vis[i][j]){
          mat[i][j] = 'X';
        }
      }
    }
  }
};

//! Without Extra Space

class Solution {
public:
    int n,m;
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    // Iterative DFS
    void dfs(int i,int j,vector<vector<char>> &mat){
      
      mat[i][j] = '#';
      stack<pair<int,int>> st;
      st.push({i,j});

      while(!st.empty()){
        auto [r,c] = st.top();
        st.pop();

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == 'O'){
            mat[nr][nc] = '#';
            st.push({nr,nc});
          }
        }
      }
    }

    void solve(vector<vector<char>>& mat) {
    n = mat.size();    
    m = mat[0].size();

    for(int j = 0; j < m; j++){
      // First Row
      if(mat[0][j] == 'O') dfs(0,j,mat);
      // Last Row
      if(mat[n-1][j] == 'O') dfs(n-1,j,mat);
    }

    for(int i = 0; i < n; i++){
      // First Col
      if(mat[i][0] == 'O') dfs(i,0,mat);
      // Last Col
      if(mat[i][m-1] == 'O') dfs(i,m-1,mat);
    }

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(mat[i][j] == 'O'){
          mat[i][j] = 'X';
        }
        else if(mat[i][j] == '#'){
          mat[i][j] = 'O';
        }
      }
    }
  }
};