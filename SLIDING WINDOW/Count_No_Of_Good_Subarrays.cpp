#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  long long countGood(vector<int> &nums, int k) {
    int n = nums.size();

    ll ans = 0;
    ll pairs = 0;

    unordered_map<ll, ll> mp;

    int l = 0;

    for (int r = 0; r < n; r++) {
      pairs += mp[nums[r]];
      mp[nums[r]]++;

      while (pairs >= k) {
        ans += (n - r);
        mp[nums[l]]--;
        pairs -= mp[nums[l]];
        l++;
      }
    }

    return ans;
  }
};