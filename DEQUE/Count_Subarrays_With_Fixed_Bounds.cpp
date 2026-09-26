#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    int n = nums.size();
    ll cnt = 0, left = 0;

    deque<int> mn, mx;

    for (int i = 0; i < n; i++) {
      if (nums[i] < minK || nums[i] > maxK) {
        mn.clear();
        mx.clear();
        left = i + 1;
        continue;
      }

      while (!mn.empty() && nums[i] <= nums[mn.back()])
        mn.pop_back();

      while (!mx.empty() && nums[i] >= nums[mx.back()])
        mx.pop_back();

      mn.push_back(i);
      mx.push_back(i);

      if (nums[mn.front()] == minK && nums[mx.front()] == maxK) {
        ll st = min(mn.front(), mx.front());

        // No of valid start points for this subarray
        cnt += (st - left + 1);
      }
    }

    return cnt;
  }
};