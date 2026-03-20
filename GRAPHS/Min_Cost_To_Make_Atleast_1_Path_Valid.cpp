#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! 0/1 BFS
//! TC =  O(V + E)
//! SC =  O(V + E)
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int row[5] = {0, 0, 0, 1, -1};
    int col[5] = {0, 1, -1, 0, 0};

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    dist[0][0] = 0;
    deque<pair<int,int>>dq;
    dq.push_back({0,0});

    while(!dq.empty()){
      auto it = dq.front();
      dq.pop_front();

      int r = it.first;
      int c = it.second;

      if(r == n-1 && c == m-1) return dist[r][c];

      for(int dir = 1; dir < 5; dir++){
        int nr = r + row[dir];
        int nc = c + col[dir];

        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

        int cost = 0;
        if(grid[r][c] == dir){
          cost = 0;
        } else {
          cost = 1;
        }

        if(dist[r][c] + cost < dist[nr][nc]){
          dist[nr][nc] = dist[r][c] + cost;

          if(cost == 1){
            dq.push_back({nr,nc});
          }
          else {
            dq.push_front({nr,nc});
          }
        }
      }
    }
    return dist[n-1][m-1];
    }
};