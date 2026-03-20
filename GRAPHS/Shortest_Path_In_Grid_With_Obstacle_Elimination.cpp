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
    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0};

    int shortestPath(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    if(k >= n + m - 2) return n + m - 2;
    vector<vector<int>> vis(n, vector<int>(m, -1));
    queue<tuple<int,int,int>> q; // {r,c,k}
    q.push({0,0,k});
   
    vis[0][0] = k;

    int steps = 0;
    while(!q.empty()){
      int sz = q.size();

      while(sz--){
        auto [r,c,K] = q.front();
        q.pop();

        if(r == n-1 && c == m-1){
          return steps;
        }

        for(int i = 0; i < 4; i++){
          int nr = r + row[i];
          int nc = c + col[i];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m){
            int newK = K - grid[nr][nc];

            if(newK  < 0) continue;

            if(vis[nr][nc] >= newK) continue;
         
              vis[nr][nc] = newK;
              q.push({nr, nc, newK});
           
          }
        }
      }
      steps++;
    } 
    return -1;  
    }
};