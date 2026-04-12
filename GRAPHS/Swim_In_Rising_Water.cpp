#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Modified Dijkstra
//* TC = O(E Log V)  | SC = O(N^2)  V = N^2

class Solution {
public:
    typedef tuple<int,int,int> T;

    int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();

    vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
    priority_queue<T, vector<T>, greater<T>> pq;

    pq.push({grid[0][0], 0, 0});
    dist[0][0] = grid[0][0];

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    while(!pq.empty()){
      auto [cost, r, c] = pq.top();
      pq.pop();
      
      // Pruning 
      if(cost > dist[r][c])
        continue;

      if(r == n-1 && c == n-1){
        return cost;
      }

      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < n){
        
        int newCost = max(cost, grid[nr][nc]);

        if(newCost < dist[nr][nc]){
          dist[nr][nc] = newCost;
          pq.push({newCost, nr, nc});
        }
        }
      }
    }
    return -1;
    }
};

