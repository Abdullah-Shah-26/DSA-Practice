#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//* BFS - TC = O(V + E)  ||   SC = O(V)

class Solution {
public:
    int row[8] = {-1,-1,-1,1,1,1,0,0};
    int col[8] = {-1,0,1,-1,0,1,1,-1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

    grid[0][0] = 1;
    queue<pair<int,int>> q;
    q.push({0,0});

    int level = 1;

    while(!q.empty()){
      int size = q.size();

      while(size--){
        auto [r,c] = q.front();
        q.pop();

        if(r == n-1 && c == m-1) return level;

        for(int k = 0; k < 8; k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 1){
            grid[nr][nc] = 1;
            q.push({nr,nc});
          }
        }
      }

      level++;
    }

    if(grid[n-1][m-1]) return level;

    return -1;     
    }
};