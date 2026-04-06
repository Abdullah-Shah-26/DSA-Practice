#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! Dijkstra 
//* TC = O(N*M)Log(N*M)  ||   SC = O(N*M)

class Solution {
public:
    typedef tuple<int,int,int> T;

    int minimumEffortPath(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    int row[4] = {0,0,1,-1};
    int col[4] = {1,-1,0,0};

    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0,0,0});

    vector<vector<int>> dist(n, vector<int> (m,INT_MAX));

    dist[0][0] = 0;

    while(!pq.empty()){
      auto [diff, r, c] = pq.top();
      pq.pop();

      if(r == n-1 && c == m-1) return dist[r][c];

      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m){
          int newEffort = max(diff, abs(mat[nr][nc] - mat[r][c]));

          if(newEffort < dist[nr][nc]){
            dist[nr][nc] = newEffort;
            pq.push({newEffort, nr, nc});
          }
        }
      }
    }

    return dist[n-1][m-1];
    }
};