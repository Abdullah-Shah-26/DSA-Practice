#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Bottom - Up
class Solution {
public:

  // Dimension Compression :
  // Total moves = k
  // r1 + c1 == r2 + c2 == k
  // c1 = k - r1
  // c2 = k - r2

  int n;
  int cherryPickup(vector<vector<int>>& grid) {
    n = grid.size();    

    vector<vector<vector<int>>> dp(2*n + 1, vector<vector<int>> (n + 1, vector<int> (n + 1, -INF)));

    // Base Case : 
    dp[2*n-2][n-1][n-1] = grid[n-1][n-1];

    for(int k = 2*n-2; k >= 0; k--){
      for(int r1 = n-1; r1 >= 0; r1--){
        for(int r2 = n-1; r2 >= 0; r2--){
          int c1 = k - r1, c2 = k - r2;
          if(c1 < 0 || c2 < 0 || c1 >= n || c2 >= n) continue;
          if(grid[r1][c1] == -1 || grid[r2][c2] == -1)  continue;          
          if(r1 == n-1 && c1 == n-1) continue;

          int gain = 0;
          if(r1 == r2 && c1 == c2)
            gain = grid[r1][c1];
          else
            gain = grid[r1][c1] + grid[r2][c2];

          int best = max({
            dp[k + 1][r1 + 1][r2 + 1],
            dp[k + 1][r1 + 1][r2],
            dp[k + 1][r1][r2 + 1],
            dp[k + 1][r1][r2]
          });

          if(best == -INF)  
            dp[k][r1][r2] = -INF;
          else
            dp[k][r1][r2] = best + gain;
        }
      }
    }

    int res = dp[0][0][0];
    return res == -INF ? 0 : res;
  }
};

// Space - TC = O(N^2)

const int INF = 1e9;
class Solution {
public:
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();    

    if(grid[n-1][n-1] == -1) return 0;  

    vector<vector<int>> next(n + 1, vector<int> (n + 1, -INF));

    // Base Case : 
    next[n-1][n-1] = grid[n-1][n-1];

    // 2n-2 is base case, in rolling dp, loop after base case
    for(int k = 2*n-3; k >= 0; k--){
      vector<vector<int>> cur(n + 1, vector<int> (n + 1, -INF));

      for(int r1 = n-1; r1 >= 0; r1--){
        for(int r2 = n-1; r2 >= 0; r2--){

          int c1 = k - r1, c2 = k - r2;
          
          if(c1 < 0 || c2 < 0 || c1 >= n || c2 >= n) continue;
          if(grid[r1][c1] == -1 || grid[r2][c2] == -1)  continue;          
          if(r1 == n-1 && c1 == n-1) continue;

          int gain = 0;
          if(r1 == r2 && c1 == c2)
            gain = grid[r1][c1];
          else
            gain = grid[r1][c1] + grid[r2][c2];

          int best = max({
            next[r1 + 1][r2 + 1],
            next[r1 + 1][r2],
            next[r1][r2 + 1],
            next[r1][r2]
          });

          if(best == -INF)  
            cur[r1][r2] = -INF;
          else
            cur[r1][r2] = best + gain;
        }
      }
    next = cur;
    }

    int res = next[0][0];
    return res == -INF ? 0 : res;
  }
};