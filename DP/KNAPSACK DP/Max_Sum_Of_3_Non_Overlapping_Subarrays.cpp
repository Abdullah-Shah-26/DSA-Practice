#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class Solution {
public:
  inline static const int N = 20005;
  int n, k;
  vector<int> pref;
  vector<int> ans;
  int dp[N][4];

  int findMaxSum(int i, int cnt, vector<int> &a) {
    if (cnt == 0)
      return 0;

    // We don't have enough elements to form req subarrays
    if (n - i < cnt * k)
      return -INF;

    if (dp[i][cnt] != -1)
      return dp[i][cnt];

    int takeI = pref[i + k] - pref[i] + findMaxSum(i + k, cnt - 1, a);
    int skipI = findMaxSum(i + 1, cnt, a);

    return dp[i][cnt] = max(takeI, skipI);
  }

  void solve(int i, int cnt, vector<int> &a) {
    if (cnt == 0)
      return;

    if (n - i < cnt * k)
      return;

    // Max sum if we select subarr starting at I
    int takeI = pref[i + k] - pref[i] + findMaxSum(i + k, cnt - 1, a);

    // Max sum if we ignore I & start at I + 1
    int skipI = findMaxSum(i + 1, cnt, a);

    if (takeI >= skipI) {
      ans.push_back(i);
      solve(i + k, cnt - 1, a);
    } else
      solve(i + 1, cnt, a);
  }

  vector<int> maxSumOfThreeSubarrays(vector<int> &a, int K) {
    n = a.size();
    k = K;

    pref.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
      pref[i] = pref[i - 1] + a[i - 1];

    memset(dp, -1, sizeof(dp));
    solve(0, 3, a);

    return ans;
  }
};