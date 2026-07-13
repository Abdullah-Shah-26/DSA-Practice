#include <bits/stdc++.h>
using namespace std;

// BFS

class Solution {
public:
  int minimumJumps(vector<int> &forbidden, int a, int b, int x) {

    unordered_set<int> st(begin(forbidden), end(forbidden));
    vector<vector<int>> vis(
        6001,
        vector<int>(2, -1)); // Also stores min steps to reach pos i via jump j
    queue<pair<int, int>> q;

    // pos, jump
    // 0 = past jump was forward
    // 1 = past jump was backward, can't take 2 consecutive backward jumps

    q.push({0, 0});
    vis[0][0] = 0;

    while (!q.empty()) {
      auto [pos, dir] = q.front();
      q.pop();

      int steps = vis[pos][dir];

      if (pos == x)
        return steps;

      int nextPos = pos + a; // Next position via Forward jump

      if (nextPos < 6001 && !st.count(nextPos) && vis[nextPos][0] == -1) {
        vis[nextPos][0] = steps + 1;
        q.push({nextPos, 0});
      }

      nextPos = pos - b; // Next position via Backward jump

      if (dir == 0 && nextPos >= 0 && !st.count(nextPos) &&
          vis[nextPos][1] == -1) {
        vis[nextPos][1] = steps + 1;
        q.push({nextPos, 1});
      }
    }

    return -1;
  }
};