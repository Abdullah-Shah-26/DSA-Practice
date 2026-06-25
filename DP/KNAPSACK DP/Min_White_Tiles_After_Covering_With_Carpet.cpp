#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int dp[1001][1001];

  int minWhiteTiles(int i, int carpetsLeft, string &floor, int carpetLen){
    if(i >= floor.size()) return 0;
    
    int &ans = dp[i][carpetsLeft];
    
    if(ans != -1) return ans;

    // Skip
    ans = ((floor[i] == '1') ? 1 : 0) + minWhiteTiles(i + 1, carpetsLeft, floor, carpetLen);

    // Take
    if(carpetsLeft > 0)
      ans = min(ans, minWhiteTiles(i + carpetLen, carpetsLeft - 1, floor, carpetLen));

    return ans;
  }

  int minimumWhiteTiles(string floor, int carpetsLeft, int carpetLen) {
    memset(dp, -1, sizeof(dp));
    return minWhiteTiles(0, carpetsLeft, floor, carpetLen);
  }
};