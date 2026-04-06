#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS + Binary Search
//* TC = O(n*m*Log(maxDiff)) = n*m*Log(1e7)     ||    SC = O(N*M)

class Solution {
public:
    int n, m;
    int row[4] = {0, 0, 1, -1};
    int col[4] = {1, -1, 0, 0};

    bool canReach(int maxEffort, vector<vector<int>> &mat){
    vector<vector<bool>> vis(n, vector<bool> (m, 0));
    queue<tuple<int,int>> q;

    q.push({0,0});
    vis[0][0] = 1;

    while(!q.empty()){
      auto [r,c] = q.front();
      q.pop();

      if(r == n-1 && c == m-1) return true;

      for(int k = 0; k < 4; k++){
        int nr = r + row[k];
        int nc = c + col[k];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]){
          int diff = abs(mat[nr][nc] - mat[r][c]);

          if(diff <= maxEffort){
            vis[nr][nc] = 1;
            q.push({nr,nc});
          }
        }
      }
    }
    return false;
    }

    int minimumEffortPath(vector<vector<int>>& mat) {
    n = mat.size();
    m = mat[0].size();

    int low = 0, high = 0;

    for(auto &row : mat){
      for(auto &x : row){
        high = max(x, high); // Max - Difference
      }
    }

    while(low <= high){
      int mid = (low + high)/2;

      if(canReach(mid, mat)) 
        high = mid - 1;
      else 
        low = mid + 1;
    }

    return low;
    }
};