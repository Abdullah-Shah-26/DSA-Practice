#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  long long maxSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();

    vector<ll> pref(n, 0);
    pref[0] = nums[0];

    for (int i = 1; i < n; i++)
      pref[i] = pref[i - 1] + nums[i];

    ll maxSum = LLONG_MIN;

    for (int st = 0; st < k; st++) {
      ll curSum = 0;

      int i = st;

      while (i < n && i + k - 1 < n) {
        int j = i + k - 1;

        ll subSum = pref[j] - ((i > 0) ? pref[i - 1] : 0);

        // Start fresh subarr of len k (or) Extend prev block which has len as multiple of k
        curSum = max(subSum, subSum + curSum);

        maxSum = max(maxSum, curSum);

        i += k;
      }
    }

    return maxSum;
  }
};