#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int n,m;

  bool dfs(int i, int j, vector<vector<int>> &grid){
    if(i == n-1 && j == m-1) 
      return true;

    grid[i][j] = 0; // mark as visited    

    if(i + 1 < n && grid[i + 1][j] && dfs(i + 1, j, grid)) 
      return true;

    if(j + 1 < m && grid[i][j + 1] && dfs(i, j + 1, grid)) 
      return true;

    return false; 
  }
  
  bool isPossibleToCutPath(vector<vector<int>>& grid) {
  n = grid.size();
  m = grid[0].size();

  // More than 1 completely independent path - always false (cannot cut it 1 flip)
  // else true

  // DFS x 2 times

  if(!dfs(0, 0, grid)) 
    return true; 

  grid[0][0] = 1; // Reset for another dfs

  if(!dfs(0, 0, grid)) // If its false, then 2 independent paths doesn't exist
    return true;

  return false;  
  }
};