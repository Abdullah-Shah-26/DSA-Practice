#include <bits/stdc++.h>
using namespace std;

// Greedy + Math

class Solution {
public:
  int minOperations(vector<vector<int>>& grid, int x) {
  int n = grid.size();
  int m = grid[0].size();

  vector<int> arr(n * m, 0);

  int i = 0;
  for(auto &row : grid){
    for(int num : row){
      arr[i] = num;
      i++;
    }
  }    

  int MOD = arr[0] % x;
  for(int num : arr){
    if(num % x != MOD)
      return -1;
  } 

  sort(begin(arr), end(arr));

  int median = arr[(n * m)/2];
  int ops = 0;

  for(int num : arr)
    ops += abs(num - median);

  return ops/x;
  }
};