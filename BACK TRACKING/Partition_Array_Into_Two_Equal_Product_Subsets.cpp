#include <bits/stdc++.h>
using namespace std;

using ll = long double;

class Solution {
public:
  bool f(int i, ll prod, vector<int> &nums, ll target) {
    if (i == nums.size())
      return prod == target;

    // Skip
    if (f(i + 1, prod, nums, target))
      return true;

    // Take
    if (prod <= target / nums[i])
      if (f(i + 1, prod * nums[i], nums, target))
        return true;

    return false;
  }

  bool checkEqualPartitions(vector<int> &nums, long long target) {
    ll p = 1;

    for (auto x : nums)
      p *= (ll)x;

    if (sqrt(p) != target)
      return false;

    return f(0, 1, nums, target);
  }
};