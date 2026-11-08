#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canRemoveAll(vector<int> &types, vector<int> &colors,
                    vector<int> &groupSize) {
    stack<array<int, 3>> st; // type, color, remCnt

    int cnt = 1; // No of consecutive elements in current group

    for (int i = 1; i < types.size(); i++) {

      // Prev group ended
      if (types[i] != types[i - 1] || colors[i] != colors[i - 1]) {

        // Prev group can't be completly removed, push new group
        if (cnt % groupSize[types[i - 1]] != 0) {
          st.push({types[i - 1], colors[i - 1], cnt % groupSize[types[i - 1]]});
          cnt = 1;
        }

        // Prev group (B) disappears completely,
        // Ex : A | B B | A
        // groupSz[A] = 2
        // groupSz[B] = 2
        else {
          // If curr group (A) is same as st top merge them
          if (!st.empty() && st.top()[0] == types[i] &&
              st.top()[1] == colors[i]) {
            cnt = 1 + st.top()[2];
            st.pop();
          }

          // Ex : A | B B | C
          // St.top doesnt match cur group
          else
            cnt = 1;
        }
      } else
        cnt++;
    }

    return cnt % groupSize[types.back()] == 0 && st.empty();
  }
};