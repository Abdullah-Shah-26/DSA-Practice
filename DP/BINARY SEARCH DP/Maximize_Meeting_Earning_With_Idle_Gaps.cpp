#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll LINF = LLONG_MAX;
using P = pair<ll, ll>;

// Greedy + DP
// BS + DP does not work cause BS does find
// the compatible meetings, but it does not directly find the one maximizing the DP transition.

/*

dpj + (si - ej) + ri
si + ri + (dpj - ej)
si + ri + maxPrev

dp[i] = max(ri, ri + si + maxPrev)

maxPrev = max(dp[j] - e[j]) where e[j] <= si

Start new sequence: ri
Extend old sequence: ri + si + maxPrev

Min-heap by end time finds finished meetings.
maxPrev tracks the maximum eligible value.
*/

class Solution {
public:
  long long maxEarnings(vector<vector<int>> &meetings) {

    // Sort meetings by start time
    sort(begin(meetings), end(meetings),
         [&](auto &a, auto &b) { return a[0] < b[0]; });

    // Min heap [endj, dp[j] - end[j]]
    priority_queue<P, vector<P>, greater<P>> pq;

    // Stores dp[j] - endj
    ll maxPrev = -LINF;
    ll maxGain = 0;

    for (auto &m : meetings) {
      ll st = m[0];
      ll end = m[1];
      ll rev = m[2]; // revenue

      // Removing meetings that are finished
      while (!pq.empty() && pq.top().first <= st) {
        maxPrev = max(maxPrev, pq.top().second);
        pq.pop();
      }

      // Start new meeting
      ll curDp = rev;

      // Extend prev meetings
      if (maxPrev != -LINF) {
        curDp = max(curDp, rev + st + maxPrev);
      }

      maxGain = max(maxGain, curDp);

      pq.push({end, curDp - end});
    }

    return maxGain;
  }
};