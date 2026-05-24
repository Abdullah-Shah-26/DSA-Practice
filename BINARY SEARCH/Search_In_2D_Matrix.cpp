#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& mat, int target) {

    int n = mat.size();
    int m = mat[0].size();

    int l = 0;
    int r = n * m - 1;

    while(l <= r){

      int mid = (l + r) >> 1;

      int row = mid / m;
      int col = mid % m;

      if(mat[row][col] == target){
        return true;
      }
      else if(mat[row][col] < target){
        l = mid + 1;
      }
      else{
        r = mid - 1;
      }
    }

    return false;
  }
};