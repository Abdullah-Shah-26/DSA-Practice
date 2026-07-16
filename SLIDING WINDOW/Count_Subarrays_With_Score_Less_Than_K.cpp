#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, long long k) {
    int n = nums.size();
    long long sum = 0, score = 0, count = 0;

    int l = 0;
    for (int r = 0; r < n; r++) {
      sum += nums[r];
      score = sum * (r - l + 1); 

      while (score >= k && l <= r) {
        sum -= nums[l];
        l++;
        score = sum * (r - l + 1);
      }

      count += (r - l + 1);
    }
    return count;
  }
};