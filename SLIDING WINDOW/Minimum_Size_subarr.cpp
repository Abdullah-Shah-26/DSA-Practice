#include <bits/stdc++.h>
using namespace std;

// TC = O(n ^ 2)

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    int minsize = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j];
        if (sum >= target) {
          minsize = min(minsize, j - i + 1);
          break;
        }
      }
    }

    return minsize == INT_MAX ? 0 : minsize;
  }
};

// TC = O(n) SC = O(1)

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {

    int n = nums.size();
    int sum = 0, st = 0, end = 0, total = INT_MAX;

    while (end < n) {
      sum += nums[end];

      while (sum >= target) {
        total = min(total, end - st + 1);
        // decrease the window size
        sum -= nums[st];
        st++;
      }
      end++; // if sum < target increase the window size
    }

    // handles the edge case
    return total == INT_MAX ? 0 : total;
  }
};