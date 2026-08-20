#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int r, c;
  int dp[10][1 << 8];

  // We are placing students row by row satisfying all conditions
  bool check(int curMask, int prevMask, vector<vector<char>> &seats, int curRow){
    int prevBit = 0;

    for(int col = 0; col < c; col++){
      
      if(!((1 << col) & curMask)){
        prevBit = 0;
        continue;
      }

      if(seats[curRow][col] == '#' || prevBit) // There shouldn't be anyone adjacent 
        return false;

      if((1 << (col + 1)) & prevMask) // There cannot be guy towards upper right diagonal
        return false;

      if(col > 0 && ((1 << (col - 1)) & prevMask)) // There cannot be guy towards upper left diagonal
        return false;

      prevBit = 1;
    }

    return true;
  }

  int solve(int curRow, int prevMask, vector<vector<char>> &seats){
    if(curRow >= r)
      return 0;

    if(dp[curRow][prevMask] != -1)
      return dp[curRow][prevMask];
  
    int ans = 0;

    for(int i = 0; i < (1 << c); i++){
      int curMask = i;
      if(check(curMask, prevMask, seats, curRow))
        ans = max(ans, __builtin_popcount(curMask) + solve(curRow + 1, curMask, seats));
    }

    return dp[curRow][prevMask] = ans;
  }

  int maxStudents(vector<vector<char>>& seats) {
    r = seats.size();
    c = seats[0].size();

    memset(dp, -1, sizeof(dp));

    int ans = solve(0, 0, seats);

    return ans;       
  }
};