#include <bits/stdc++.h>
using namespace std;

// Good Problem : 

class Solution {
public:
  int n;
  int dp[2001][2001];
  unordered_map<int, int> mp; // stone[i], i

  bool f(int curStoneIdx, int prevJump, vector<int> &stones) {
    if (curStoneIdx == n - 1)
      return true;

    if (dp[curStoneIdx][prevJump] != -1)
      return dp[curStoneIdx][prevJump];

    bool ans = false;

    for (int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++) {
      if (nextJump > 0) { // Since we need to jump forward
        int nextStone = stones[curStoneIdx] + nextJump;

        if (mp.find(nextStone) != mp.end()) {
          ans |= f(mp[nextStone], nextJump, stones);
        }
      }
    }

    return dp[curStoneIdx][prevJump] = ans;
  }

  bool canCross(vector<int> &stones) {
    n = stones.size();

    if (stones[1] != 1)
      return false;

    for (int i = 0; i < n; i++)
      mp[stones[i]] = i;

    memset(dp, -1, sizeof(dp));

    return f(mp[0], 0, stones);
  }
};