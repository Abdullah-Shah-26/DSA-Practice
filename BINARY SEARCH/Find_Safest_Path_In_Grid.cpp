#include <bits/stdc++.h>
using namespace std;

// Binary Search + BFS

class Solution {
public:
  int n;
  int row[4] = {0,0,-1,1};
  int col[4] = {1,-1,0,0};

  bool check(vector<vector<int>> &dist, int safeFactor){
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n, vector<bool> (n, false));

    q.push({0,0});
    vis[0][0] = true;

    if(dist[0][0] < safeFactor)
      return false;

    while(!q.empty()){
      auto [i, j] = q.front();
      q.pop();

      if(i == n-1 && j == n-1)
        return true;

      for(int k = 0; k < 4; k++){
        int ni = i + row[k];
        int nj = j + col[k];

        if(ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj]){
          if(dist[ni][nj] >= safeFactor){
             q.push({ni, nj});
             vis[ni][nj] = true;
          }
        }
      }
    }
    return false;
  }

  int maximumSafenessFactor(vector<vector<int>>& grid) {
    n = grid.size();

    // Precomputing nearest dist from thief
    vector<vector<int>> dist(n, vector<int> (n, -1));   
    vector<vector<bool>> vis(n, vector<bool> (n, false));
    queue<pair<int,int>> q;

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(grid[i][j] == 1){
          q.push({i, j});
          vis[i][j] = true;
        }
      }
    }

    int level = 0;
    while(!q.empty()){
      int sz = q.size();

      while(sz--){
        auto [i, j] = q.front();
        q.pop();

        dist[i][j] = level;

        for(int k = 0; k < 4; k++){
          int ni = i + row[k];
          int nj = j + col[k];

          if(ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj]){
            vis[ni][nj] = 1;
            q.push({ni, nj});
          }
        }
      }
      level++;
    }

    int l = 0, r = 400;
    int ans = 0;

    while(l <= r){
      int mid = (l + r) >> 1;

      if(check(dist, mid)){
        ans = mid;
        l = mid + 1; 
      }
      else{
        r = mid - 1; 
      }
    }

    return ans;
  }
};