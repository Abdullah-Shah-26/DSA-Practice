//! 0/1 BFS
//! E = (4 * N * M)   V = (N * M)
//! TC = (V + E)
//! SC = O(V)
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
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int n = grid.size();
    int m = grid[0].size();

    // Min No of Unsafe Cells to reach (i,j)
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    
    deque<pair<int,int>> dq;
    dq.push_back({0,0});
    dist[0][0] = grid[0][0];

    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0};

    while(!dq.empty()){
      auto it = dq.front();
      dq.pop_front();

      int r = it.first;
      int c = it.second;

      if(r == n-1 && c == m-1){
        return dist[r][c] <= health - 1;
      }

      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m){

          int wt = grid[nr][nc];

          if(dist[r][c] + wt < dist[nr][nc]){
            dist[nr][nc] = wt + dist[r][c];

            if(wt == 0){
              dq.push_front({nr, nc});
            } else {
              dq.push_back({nr, nc});
            }
          }
        }
      }
    }
    return false;
    }
};