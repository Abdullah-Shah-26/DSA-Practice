#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

class Solution {
public:
  int countPartitions(vector<int> &nums, int k) {
    int n = nums.size();

    // dp[i] = No of ways to partition first i elements
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    deque<int> mx, mn;
    ll sum = 0;

    int l = 0;
    for (int r = 0; r < n; r++) {
      while (!mx.empty() && nums[mx.back()] <= nums[r])
        mx.pop_back();

      while (!mn.empty() && nums[mn.back()] >= nums[r])
        mn.pop_back();

      mx.push_back(r);
      mn.push_back(r);

      while (nums[mx.front()] - nums[mn.front()] > k) {
        if (mx.front() == l)
          mx.pop_front();

        if (mn.front() == l)
          mn.pop_front();

        sum = (sum - dp[l] + MOD) % MOD;

        l++;
      }

      sum = (sum + dp[r]) % MOD;
      dp[r + 1] = sum;
    }

    return dp[n];
  }
};