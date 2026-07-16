#include <bits/stdc++.h>
using namespace std;

//! TC = O(N)
//! SC = O(1)

class Solution {
public:
  long long countSubarrays(std::vector<int> &nums, int k) {
    int n = static_cast<int>(nums.size());
    long long ans = 0;

    int maxi = *max_element(begin(nums), end(nums));
    int cntMaxi = 0;

    int l = 0;
    for (int r = 0; r < n; r++) {
      if (nums[r] == maxi)
        cntMaxi++;

      while (l <= r && cntMaxi >= k) {
        ans += (n - r);
        if (nums[l] == maxi)
          cntMaxi--;
        l++;
      }
    }
    
    return ans;
  }
};
