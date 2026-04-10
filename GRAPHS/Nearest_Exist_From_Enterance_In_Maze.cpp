#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

//! BFS - Level Wise

class Solution {
public:
    int nearestExit(vector<vector<char>>& mat, vector<int>& e) {
    int n = mat.size();    
    int m = mat[0].size();
    int steps = 0;

    queue<pair<int,int>> q;

    q.push({e[0], e[1]});
    mat[e[0]][e[1]] = '+';

    int row[4] = {0,0,-1,1};
    int col[4] = {1,-1,0,0};

    while(!q.empty()){
      int size = q.size();

      while(size--){
        auto [r,c] = q.front();
        q.pop();

        if((r == 0 || c == 0 || r == n-1 || c == m-1) && (r != e[0] || c != e[1])) return steps;

        for(int k = 0; k < 4; k++){
          int nr = r + row[k];
          int nc = c + col[k];

          if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] != '+'){
            mat[nr][nc] = '+'; // mark as visited
            q.push({nr,nc});
          }      
        }
      }
      steps++;
    }

    return -1;
    }
};