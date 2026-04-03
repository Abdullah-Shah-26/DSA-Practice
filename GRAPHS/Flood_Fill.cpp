#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DFS - Recursive

class Solution {
  public:
    int n,m;
    
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    void dfs(int i,int j,vector<vector<int>> &image,vector<vector<int>> &ans, int iniColor, int color){
      ans[i][j] = color;

      for(int k = 0; k < 4; k++){
        int nr = i + row[k];
        int nc = j + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == iniColor && ans[nr][nc] != color){
           dfs(nr,nc,image,ans,iniColor,color);
        }
      }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      n = image.size();
      m = image[0].size();

      vector<vector<int>> ans = image;

      int iniColor = image[sr][sc];

      dfs(sr,sc,image,ans,iniColor,color);

      return ans;
    }
};


//! BFS

class Solution {
  public:
    int n,m;
    
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    void bfs(int i,int j,vector<vector<int>> &image,vector<vector<int>> &ans, int iniColor, int color){
    
     queue<pair<int,int>> q;
     q.push({i,j});
     ans[i][j] = color;

     while(!q.empty()){
      auto [r,c] = q.front();
      q.pop();
      
      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == iniColor && ans[nr][nc] != color){
           ans[nr][nc] = color;
           q.push({nr,nc});
        }
      }
     }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      n = image.size();
      m = image[0].size();

      vector<vector<int>> ans = image;

      int iniColor = image[sr][sc];

      bfs(sr,sc,image,ans,iniColor,color);

      return ans;
    }
};

//! DFS Iterative 
class Solution {
  public:
    int n,m;
    
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    void dfsIt(int i,int j,vector<vector<int>> &image,vector<vector<int>> &ans, int iniColor, int color){
    
     stack<pair<int,int>> st;
     st.push({i,j});
     ans[i][j] = color;

     while(!st.empty()){
      auto [r,c] = st.top();
      st.pop();
      
      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == iniColor && ans[nr][nc] != color){
           ans[nr][nc] = color;
           st.push({nr,nc});
        }
      }
     }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      n = image.size();
      m = image[0].size();

      vector<vector<int>> ans = image;

      int iniColor = image[sr][sc];

      if(iniColor == color) return ans;

      dfsIt(sr,sc,image,ans,iniColor,color);

      return ans;
    }
};