#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// TC = O(N) | SC = O(N)

// Monotonic Deque

class Solution {
public:
  int shortestSubarray(vector<int> &nums, int k) {
    int n = nums.size();

    // Stores idx in monotonic inc order of cumSum
    deque<int> dq;

    vector<long long> cumSum(n, 0);

    int minLen = 1e9;

    for (int j = 0; j < n; j++) {
      if (j == 0)
        cumSum[j] = nums[j];
      else
        cumSum[j] = cumSum[j - 1] + nums[j];

      if (cumSum[j] >= k) {
        minLen = min(minLen, j + 1);
      }

      // Shrink Window until valid
      while (!dq.empty() && cumSum[j] - cumSum[dq.front()] >= k) {
        minLen = min(minLen, j - dq.front());
        dq.pop_front();
      }

      // Maintain Monotonic nature
      while (!dq.empty() && cumSum[j] <= cumSum[dq.back()]) {
        dq.pop_back();
      }

      dq.push_back(j);
    }

    return minLen == 1e9 ? -1 : minLen;
  }
};