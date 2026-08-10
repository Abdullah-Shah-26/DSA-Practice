#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// TC = O(N * LogM * Log(Range of product))

class Solution {
public:
  // Count how many b in nums2 satisfy:
  // a * b <= x
  ll cntForA(vector<int> &nums2, ll a, ll x) {
    int n = nums2.size();

    // a = 0
    if (a == 0)
      return x >= 0 ? n : 0;

    // a > 0
    // Products increase.
    // Valid elements form a PREFIX:
    //
    // [valid valid valid invalid invalid]
    //
    // Find first invalid position.
    if (a > 0) {
      int low = 0, high = n - 1;
      int ans = n; // If no invalid element exists.

      while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a * (ll)nums2[mid] <= x) {
          // mid is valid.
          // First invalid must be to the right.
          low = mid + 1;
        } else {
          // mid is invalid.
          // This could be the first invalid.
          ans = mid;
          high = mid - 1;
        }
      }

      // [0 ... ans-1] are valid.
      return ans;
    }

    // a < 0
    // Products decrease.
    // Valid elements form a SUFFIX:
    //
    // [invalid invalid valid valid valid]
    //
    // Find first valid position.
    else {
      int low = 0, high = n - 1;
      int ans = n; // If no valid element exists.

      while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a * (ll)nums2[mid] <= x) {
          // mid is valid.
          // We want an earlier valid position.
          ans = mid;
          high = mid - 1;
        } else {
          // mid is invalid.
          // Valid elements must be to the right.
          low = mid + 1;
        }
      }

      // [ans ... n-1] are valid.
      return n - ans;
    }
  }

  // Count all pairs whose product <= x.
  ll cntProducts(vector<int> &nums1, vector<int> &nums2, ll x) {

    ll cnt = 0;

    for (ll a : nums1)
      cnt += cntForA(nums2, a, x);

    return cnt;
  }

  long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2,
                               long long k) {

    ll low = -10000000000LL;
    ll high = 10000000000LL;
    ll ans = 10000000000LL;

    while (low <= high) {

      ll mid = low + (high - low) / 2;

      // How many products are <= mid?
      ll cnt = cntProducts(nums1, nums2, mid);

      if (cnt >= k) {
        // mid could be the answer.
        ans = mid;
        high = mid - 1;
      } else {
        // Not enough products <= mid.
        // Answer must be larger.
        low = mid + 1;
      }
    }

    return ans;
  }
};