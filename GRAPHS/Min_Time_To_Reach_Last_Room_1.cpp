#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

// #define P pair<int,pair<int,int>>
typedef pair<int, pair<int,int>> P;
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>dist(n, vector<int>(m, INT_MAX));

    priority_queue<P, vector<P>, greater<P>> pq;
    
    dist[0][0] = 0;

    int row[4] = {1,0,-1,0};
    int col[4] = {0,1,0,-1};

    pq.push({0, {0,0}});

    while(!pq.empty()){
     auto it  = pq.top();
     pq.pop();

     int curTime = it.first;
     int r = it.second.first;
     int c = it.second.second; 

    // Remove Stale Entry
     if(curTime > dist[r][c]) continue;

     if(r == n-1 && c == m-1){
      return dist[r][c];
     }
  
     for(int k = 0; k < 4; k++){
      int nr = r + row[k];
      int nc = c + col[k];

      if(nr >= 0 && nr < n && nc >= 0 && nc < m){
        int wtTime = max(grid[nr][nc] - curTime, 0);
        int arrivalTime = curTime + wtTime + 1;

        if(arrivalTime < dist[nr][nc]){
          dist[nr][nc] = arrivalTime;

          pq.push({arrivalTime, {nr, nc}});
        }
      }
     }
    }
    return -1;
    }
};