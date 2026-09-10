#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minAbsoluteDifference(vector<int> &nums, int x) {
    int n = nums.size();
    int ans = 1e9;

    set<int> st;

    for (int i = 0; i < n; i++) {

      int j = i - x;

      if (j >= 0)
        st.insert(nums[j]);

      auto it = st.lower_bound(nums[i]);

      if (it != st.end())
        ans = min(ans, abs(nums[i] - *it));

      if (it != st.begin()) {
        it--;
        ans = min(ans, abs(nums[i] - *it));
      }
    }

    return ans;
  }
};