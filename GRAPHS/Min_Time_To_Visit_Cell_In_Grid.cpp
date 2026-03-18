#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// E = (4 * n * m)    V = n * m
//! TC = O(E log V)
//! SC = O(V)
class Solution {
public:
    # define P pair<int, pair<int,int>>
    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0};

    int minimumTime(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Edge Case
    if(grid[0][1] > 1 && grid[1][0] > 1){
      return -1;
    }    

    priority_queue<P, vector<P>, greater<P>>pq;
    vector<vector<int>> result(m, vector<int>(n, 1e9));
    result[0][0] = 0;
    pq.push({0, {0, 0}});

    
    while(!pq.empty()){
      auto it = pq.top();
      pq.pop();
      int time = it.first;
      int r = it.second.first;
      int c = it.second.second;

      if(time > result[r][c]){
        continue;
      }

      if(r == m-1 && c == n-1){
        return time;
      }

      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < m && nc >= 0 && nc < n){
          int newTime = time + 1;

          if(newTime < grid[nr][nc]){
            int diff = grid[nr][nc] - newTime; // Attempt to move

            if(diff & 1){
              newTime = grid[nr][nc] + 1;
            }
            else {
              newTime = grid[nr][nc];
            }
          }

          if(newTime < result[nr][nc]){
            result[nr][nc] = newTime;
            pq.push({newTime, {nr, nc}});
          }
          }
        }
      }
    
    return -1; 
    }
};