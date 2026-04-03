#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! DFS MultiSource + Relaxation - TLE 
//* TC = O(N * M)^2

class Solution {
  public:
    int n,m;
  
    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0};
  
    void dfs(int i,int j, vector<vector<int>> &dist, vector<vector<int>> &grid){
        for(int k = 0; k < 4; k++){
            int nr = i + row[k];
            int nc = j + col[k];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0){
                if(dist[i][j] + 1 < dist[nr][nc]){
                    dist[nr][nc] = dist[i][j] + 1;
                    dfs(nr,nc,dist,grid);
                }
            }
        }
    }
    
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    
    vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
         if(grid[i][j] == 1){
             dist[i][j] = 0;
             dfs(i,j,dist,grid);
         }   
        }
    }
    
    return dist;
    }
};

//! BFS Multi Source
//* TC = O(N*M)  |||  SC = O(N*M) 

class Solution {
  public:
    int n,m;
    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0};
  
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    
    vector<vector<int>> dist(n, vector<int> (m, -1));
    
    queue<pair<int,int>> q;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
         if(grid[i][j] == 1){
             dist[i][j] = 0;
             q.push({i,j});
          }   
       }
    }
    
    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();
        
        for(int k = 0; k < 4; k++){
            int nr = i + row[k];
            int nc = j + col[k];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1){
                dist[nr][nc] = dist[i][j] + 1;
                q.push({nr,nc});
            }
        }
    }
    
    return dist;
    }
};