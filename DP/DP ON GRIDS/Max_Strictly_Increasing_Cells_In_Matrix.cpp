#include <bits/stdc++.h>
using namespace std;

// TC = O(M * N * Log(M*N))

class Solution {
public:
  int maxIncreasingCells(vector<vector<int>>& mat) {
  int m = mat.size();
  int n = mat[0].size();

  // Increasing order
  map<int, vector<pair<int,int>>> mp; // [value] - ((r1,c1), (r2,c2), ...)

  for(int i = 0; i < m; i++)  
    for(int j = 0; j < n; j++)
      mp[mat[i][j]].push_back({i, j});

  // Stores maxLen of increasing path ending at [i,j]
  vector<vector<int>> dp(m, vector<int> (n, 0)); 

  // Best dp val seen so far in each row & col
  vector<int> rowMaxScore(m, 0);
  vector<int> colMaxScore(n, 0);

  for(auto &[val, pos] : mp){
    // Handling duplicates together
    for(auto &[i,j] : pos)
      dp[i][j] = max(rowMaxScore[i], colMaxScore[j]) + 1;

    for(auto &[i,j] : pos){
      rowMaxScore[i] = max(rowMaxScore[i], dp[i][j]);
      colMaxScore[j] = max(colMaxScore[j], dp[i][j]);
    }
  }

  return *max_element(begin(rowMaxScore), end(rowMaxScore));
  }
};