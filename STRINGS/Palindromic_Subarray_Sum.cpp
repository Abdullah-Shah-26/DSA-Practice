#include <bits/stdc++.h>
using namespace std;

// Manacher + Prefix Sum
// TC = O(N) | SC = O(N)

using ll = long long;

class Solution {
public:
  vector<ll> transform(const vector<int> &nums) {
    // Since this isn't a string we use below sentinels instead of 
    const ll left = -2; // ^
    const ll sep = -1; // #
    const ll right = -3; // $

    vector<ll> t;

    t.push_back(left);
    t.push_back(sep);

    for (int x : nums) {
      t.push_back(x);
      t.push_back(sep);
    }

    t.push_back(right);

    return t;
  }

  vector<int> manacher(vector<ll> &t) {
    int n = t.size();

    vector<int> p(n);

    int center = 0;
    int right = 0;

    for (int i = 1; i < n - 1; i++) {
      int mirror = 2 * center - i;

      if (i < right)
        p[i] = min(p[mirror], right - i);

      while (t[i + p[i] + 1] == t[i - p[i] - 1])
        p[i]++;

      if (i + p[i] > right) {
        center = i;
        right = i + p[i];
      }
    }

    return p;
  }

  long long getSum(vector<int> &nums) {
    int n = nums.size();

    vector<ll> pref(n + 1, 0);

    for (int i = 1; i <= n; i++)
      pref[i] = pref[i - 1] + nums[i - 1];

    auto getSum = [&](int L, int R) { return pref[R + 1] - pref[L]; };

    vector<ll> t = transform(nums);
    vector<int> p = manacher(t);

    ll ans = 0;

    // 1 -> p.size()-1
    // Since first & last are sentinels guarding boundary
    for (int i = 1; i < p.size() - 1; i++) {
      if (p[i] == 0)
        continue;

      int L = (i - p[i]) / 2;
      int R = (i + p[i]) / 2 - 1;

      if (L <= R)
        ans = max(ans, getSum(L, R));
    }

    return ans;
  }
};