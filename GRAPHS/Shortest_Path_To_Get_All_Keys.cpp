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
    // BFS + BitMasking
    //! TC = O(N * M)
    //! SC = O(N * M * (2 ^ K)) 
    int shortestPathAllKeys(vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0};

    int stRow = -1, stCol = -1;
    int finalMask = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(islower(grid[i][j])){
          finalMask |= (1 << (grid[i][j] - 'a'));
        }
        if(grid[i][j] == '@'){
          stRow = i;
          stCol = j;
        }
      }
    }
    // 6 keys - 2^6 = 64 states
    bool vis[31][31][64];
    memset(vis, 0, sizeof(vis));
    /*
    int finalMask = (1 << totalKeys) - 1; 
    only works if keys are contiguous : Ex : abc 
    */
    queue<tuple<int,int,int>>q;
    q.push({stRow,stCol,0});
    vis[stRow][stCol][0] = 1;

    int steps = 0;

    while(!q.empty()){
      int sz = q.size();
      while(sz--){
        auto [r,c,mask] = q.front();
        q.pop();

        if(mask == finalMask){
          return steps;
        }

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];
          int newMask = mask;

          if(nr >= 0 && nr < n && nc >= 0 && nc < m){
          
          // wall check
          if(grid[nr][nc] == '#') continue;

          // Lock Check
          if(isupper(grid[nr][nc]) && !(newMask & (1 << (grid[nr][nc] - 'A'))))
            continue;
          
          // Key Check
          if(islower(grid[nr][nc])){
            newMask |= (1 << (grid[nr][nc] - 'a'));
          }

          // Vis Check
          if(vis[nr][nc][newMask]) continue;

          // Mark Visited
          vis[nr][nc][newMask] = 1;

          q.push({nr, nc, newMask});
          }
        }
      }
      steps++;
    }
    return -1;
    }
};