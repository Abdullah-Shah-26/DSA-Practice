#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T>
using oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using pll = pair<ll, ll>;

/*
(even / odd) = (a / b)
(x / y) = (a / b)

*/

class Solution {
public:
  long long countRatioSubarrays(vector<int> &nums, int a, int b) {
    int n = nums.size();

    // Storing pair [value, idx] so that we can store duplicates too
    oset<pll> s;
    s.insert({0, 0});

    ll ans = 0;
    ll x = 0, y = 0;

    for (int i = 1; i <= n; i++) {
      if (nums[i - 1] & 1)
        y++;
      else
        x++;

      ll v = b * x - a * y;

      // Total - strictly smaller = equal or greater
      ans += (i - s.order_of_key({v, -1}));
      s.insert({v, i});
    }

    return ans;
  }
};