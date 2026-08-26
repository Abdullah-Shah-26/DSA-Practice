#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  vector<long long> distance(vector<int> &nums) {
    int n = nums.size();

    unordered_map<ll, vector<int>> mp;

    vector<ll> ans(n, 0);

    for (int i = 0; i < n; i++)
      mp[nums[i]].push_back(i);

    for (auto &[value, pos] : mp) {
      int m = pos.size();

      vector<ll> pref(m);

      pref[0] = pos[0];

      for (int i = 1; i < m; i++)
        pref[i] = pref[i - 1] + pos[i];

      ll totalSum = pref[m - 1];

      for (int i = 0; i < m; i++) {
        int idx = pos[i];

        ll leftCnt = i;
        ll leftSum = (i > 0 ? pref[i - 1] : 0);

        ll rightCnt = m - i - 1;
        ll rightSum = totalSum - pref[i];

        ll left = leftCnt * idx - leftSum;
        ll right = rightSum - rightCnt * idx;

        ans[idx] = left + right;
      }
    }

    return ans;
  }
};