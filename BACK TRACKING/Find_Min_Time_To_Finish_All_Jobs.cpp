#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int ans = INT_MAX;

  void solve(int i, vector<int> &jobs, vector<int> &worker) {
    if (i == jobs.size()) {
      ans = min(ans, *max_element(begin(worker), end(worker)));
      return;
    }

    for (int w = 0; w < worker.size(); w++) {
      if (w > 0 && worker[w] == worker[w - 1])
        continue;

      if (worker[w] + jobs[i] >= ans)
        continue;

      worker[w] += jobs[i];

      solve(i + 1, jobs, worker);

      worker[w] -= jobs[i];
    }
  }

  int minimumTimeRequired(vector<int> &jobs, int k) {
    vector<int> worker(k, 0);

    sort(begin(jobs), end(jobs), greater<int>());

    solve(0, jobs, worker);

    return ans;
  }
};