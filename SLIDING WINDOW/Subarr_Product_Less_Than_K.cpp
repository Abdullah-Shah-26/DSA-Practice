#include <bits/stdc++.h>
using namespace std;

class Solution {
public: // TC = O(n^2)
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int n = nums.size();
    int total = 0;
    for (int i = 0; i < n; i++) {
      long long product = 1;
      for (int j = i; j < n; j++) {
        if (product < INT_MAX)
          product *= nums[j];
        if (product < k)
          total++;
      }
    }
    return total;
  }
};

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int product = 1, start = 0, end = 0, n = nums.size();
    int count = 0;
    while (end < n) {
      product *= nums[end];

      while (product >= k && start <= end) {
        product /= nums[start];
        start++;
      }

      count += end - start + 1;
      end++;
    }
    return count;
  }
};