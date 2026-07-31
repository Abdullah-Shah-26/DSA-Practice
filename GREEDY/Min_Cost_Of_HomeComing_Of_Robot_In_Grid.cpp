#include <bits/stdc++.h>
using namespace std;

// TC = O(N + M)

class Solution {
public:
  int minCost(vector<int> &startPos, vector<int> &homePos,
              vector<int> &rowCosts, vector<int> &colCosts) {

    int r1 = startPos[0];
    int c1 = startPos[1];

    int r2 = homePos[0];
    int c2 = homePos[1];

    int ans = 0;

    // Avoid unnecessary moves & only moves in the direction of home

    if (r1 <= r2) { // Move down
      for (int r = r1 + 1; r <= r2; r++) {
        ans += rowCosts[r];
      }
    } else { // Move up
      for (int r = r1 - 1; r >= r2; r--) {
        ans += rowCosts[r];
      }
    }

    if (c1 <= c2) { // Move right
      for (int c = c1 + 1; c <= c2; c++) {
        ans += colCosts[c];
      }
    } else { // Move left
      for (int c = c1 - 1; c >= c2; c--) {
        ans += colCosts[c];
      }
    }

    return ans;
  }
};