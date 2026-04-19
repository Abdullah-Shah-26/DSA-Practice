#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int n,m;

    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0};

    void dfs(int i, int j, vector<vector<int>> &mat){
      mat[i][j] = 1;

      for(int k = 0; k < 4; k++){
        int nr = i + row[k];
        int nc = j + col[k];

        if(nr >= 0 && nr < n*3 && nc >= 0 && nc < m*3 && mat[nr][nc] == 0)
          dfs(nr, nc, mat);
      }
    }

    int regionsBySlashes(vector<string>& grid) {
    n = grid.size();
    m = grid[0].size();

    // Convert to 3x3 - matrix
    vector<vector<int>> mat(n*3, vector<int> (m*3,0));

    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        
        if(grid[i][j] == '/'){
          mat[i*3 + 0][j*3 + 2] = 1; 
          mat[i*3 + 1][j*3 + 1] = 1;
          mat[i*3 + 2][j*3 + 0] = 1;
        }
        else if(grid[i][j] == '\\'){
          mat[i*3 + 0][j*3 + 0] = 1;
          mat[i*3 + 1][j*3 + 1] = 1;
          mat[i*3 + 2][j*3 + 2] = 1;
        }

      }
    }

    int components = 0;

    for(int i = 0; i < n*3; i++){
      for(int j = 0; j < m*3; j++){
        if(mat[i][j] == 0){
          components++;
          dfs(i, j, mat);
        }
      }
    }

    return components;                                      
    }
};