//! Multisource BFS 
//! TC = O(N^2) // SC = O(N^2)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
  
    queue<pair<int,int>>q;
  
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(grid[i][j] == 1){
          q.push({i,j});
        }
      }
    }

    // Edge Case
    // No Land or No water
    if(q.empty() || q.size() == n*m){
      return -1;
    }

    int maxi = INT_MIN;
    while(!q.empty()){
      auto it = q.front();
      q.pop();
      int r = it.first;
      int c = it.second;

      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]==0){

          grid[nr][nc] = grid[r][c] + 1;
          maxi = max(grid[nr][nc], maxi);

          q.push({nr,nc});
        }
      }
    }
    return maxi == INT_MIN ? -1 : maxi - 1;
    }
};