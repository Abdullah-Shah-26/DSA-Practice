#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

class Solution {
public:
  vector<vector<int>> dp;

  int cntWalls(vector<int> &walls, int L, int R) {
    auto lb = lower_bound(begin(walls), end(walls), L);
    auto ub = upper_bound(begin(walls), end(walls), R);

    return ub - lb;
  }

  int solve(vector<int> &walls, vector<P> &roboDist, vector<P> &range, int i,
            int prevDir) {
    if (i == roboDist.size())
      return 0;

    if (dp[i][prevDir] != -1)
      return dp[i][prevDir];

    auto [L, R] = range[i];
    auto [pos, d] = roboDist[i];

    int leftSt = L;

    if (prevDir == 1) { // Prev robot fired in right direction
      leftSt = max(leftSt, range[i - 1].first + 1);
    }

    int leftTake =
        cntWalls(walls, leftSt, pos) + solve(walls, roboDist, range, i + 1, 0);
    int rightTake =
        cntWalls(walls, pos, R) + solve(walls, roboDist, range, i + 1, 1);

    return dp[i][prevDir] = max(leftTake, rightTake);
  }

  int maxWalls(vector<int> &robots, vector<int> &distance, vector<int> &walls) {
    int n = robots.size();

    vector<P> roboDist(n);

    for (int i = 0; i < n; i++)
      roboDist[i] = {robots[i], distance[i]};

    sort(begin(roboDist), end(roboDist));
    sort(begin(walls), end(walls));

    vector<P> range(n);

    for (int i = 0; i < n; i++) {
      auto [pos, d] = roboDist[i];

      int left = (i == 0) ? 1 : roboDist[i - 1].first + 1;
      int right = (i == n - 1) ? 1e9 : roboDist[i + 1].first - 1;

      int L = max(left, pos - d);
      int R = min(right, pos + d);

      range[i] = {L, R};
    }

    // prev = 0 (previous robot hit in left direction)
    // prev = 1 (previous robot hit in right direction)

    dp.resize(n + 1, vector<int>(2, -1));

    return solve(walls, roboDist, range, 0, 0);
  }
};