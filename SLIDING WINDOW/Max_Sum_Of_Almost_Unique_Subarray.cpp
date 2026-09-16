#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  long long maxSum(vector<int> &nums, int m, int k) {
    int n = nums.size();

    vector<ll> pref(n, 0);
    pref[0] = nums[0];

    for (int i = 1; i < n; i++)
      pref[i] = pref[i - 1] + nums[i];

    int l = 0, unique = 0;
    unordered_map<int, int> freq;

    ll sum = 0;

    for (int r = 0; r < n; r++) {
      freq[nums[r]]++;

      if (freq[nums[r]] == 1)
        unique++;

      if ((r - l + 1) > k) {
        freq[nums[l]]--;

        if (freq[nums[l]] == 0) {
          unique--;
          freq.erase(nums[l]);
        }

        l++;
      }

      if ((r - l + 1) == k && unique >= m) {
        sum = max(sum, pref[r] - (l > 0 ? pref[l - 1] : 0));
      }
    }

    return sum;
  }
};