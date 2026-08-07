#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

class Solution {
public:
  vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries) {
    int n = intervals.size();
    int m = queries.size();

    vector<pair<int, int>> qry; // query, position
    vector<int> ans(m, -1);

    for (int i = 0; i < m; i++) {
      int x = queries[i];
      qry.push_back({x, i});
    }

    sort(begin(qry), end(qry));
    sort(begin(intervals), end(intervals));

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    int j = 0;

    for (int i = 0; i < m; i++) {
      auto [q, idx] = qry[i];

      // Insert all intervals where q >= l
      while (j < n && q >= intervals[j][0]) {
        int l = intervals[j][0];
        int r = intervals[j][1];

        pq.push({r - l + 1, r});

        j++;
      }

      // Remove invalid intervals
      while (!pq.empty() && pq.top().second < q)
        pq.pop();

      if (!pq.empty())
        ans[idx] = pq.top().first;
    }

    return ans;
  }
};