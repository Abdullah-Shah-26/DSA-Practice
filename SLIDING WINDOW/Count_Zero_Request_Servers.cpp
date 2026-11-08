#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> countServers(int n, vector<vector<int>> &logs, int x,
                           vector<int> &queries) {
    int m = queries.size();

    vector<int> ans(m);
    vector<pair<int, int>> timeIdx(m);

    for (int i = 0; i < m; i++)
      timeIdx[i] = {queries[i], i};

    sort(begin(timeIdx), end(timeIdx));

    // Logs are sorted based on time
    sort(begin(logs), end(logs), [&](auto &a, auto &b) { return a[1] < b[1]; });

    unordered_map<int, int> mp;

    int i = 0, j = 0;

    for (auto &[q, idx] : timeIdx) {
      int st = q - x;
      int end = q;

      // Expand
      while (j < logs.size() && logs[j][1] <= end) {
        mp[logs[j][0]]++;
        j++;
      }

      // Shrink
      while (i < logs.size() && logs[i][1] < st) {
        mp[logs[i][0]]--;

        if (mp[logs[i][0]] == 0)
          mp.erase(logs[i][0]);

        i++;
      }

      ans[idx] = n - (int)mp.size();
    }

    return ans;
  }
};