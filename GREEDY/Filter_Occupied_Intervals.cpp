#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> filterOccupiedIntervals(vector<vector<int>> &occInt,
                                              int fs, int fe) {
    sort(begin(occInt), end(occInt));

    vector<vector<int>> merged;
    merged.push_back(occInt.front());

    for (int i = 1; i < occInt.size(); i++) {
      auto &last = merged.back();
      auto &cur = occInt[i];

      if (last[1] >= cur[0] - 1)        // Overlap according to question
        last[1] = max(last[1], cur[1]); // Merge
      else
        merged.push_back(cur);
    }

    vector<vector<int>> ans;
    for (auto &it : merged) {
      int l = it[0];
      int r = it[1];

      if (fs > r || fe < l) // No overlap with free slot
        ans.push_back({l, r});

      else if (fs > l && fe < r) { // Divides interval into 2
        ans.push_back({l, fs - 1});
        ans.push_back({fe + 1, r});
      }

      else if (fs > l && fe >= r) // Remove suffix
        ans.push_back({l, fs - 1});

      else if (fs <= l && fe < r) // Remove prefix
        ans.push_back({fe + 1, r});
    }

    return ans;
  }
};