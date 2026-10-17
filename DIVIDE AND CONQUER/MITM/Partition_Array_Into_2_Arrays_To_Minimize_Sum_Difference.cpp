#include <bits/stdc++.h>
using namespace std;

/*
sumA + sumB = S
sumB = S - sumA

Minimize absolute difference between sums of A and B.

abs(sumA - sumB)
= abs(sumA - (S - sumA))
= abs(2 * sumA - S)
= abs(S - 2 * sumA)
*/

class Solution {
public:
  int minimumDifference(vector<int> &nums) {
    int N = nums.size();
    int n1 = N / 2;
    int n2 = N - n1;

    vector<vector<int>> L(n1 + 1), R(n2 + 1);

    for (int mask = 0; mask < (1 << n1); mask++) {
      int sum = 0;
      int cnt = 0;

      for (int i = 0; i < n1; i++) {
        if (mask & (1 << i)) {
          sum += nums[i];
          cnt++;
        }
      }

      L[cnt].push_back(sum);
    }

    for (int mask = 0; mask < (1 << n2); mask++) {
      int sum = 0;
      int cnt = 0;

      for (int i = 0; i < n2; i++) {
        if (mask & (1 << i)) {
          sum += nums[i + n1];
          cnt++;
        }
      }

      R[cnt].push_back(sum);
    }

    int ans = INT_MAX;
    int total = accumulate(begin(nums), end(nums), 0);

    for (int cnt = 0; cnt <= n2; cnt++) {
      auto &v = R[cnt];
      sort(begin(v), end(v));
    }

    for (int l = 0; l <= n1; l++) {

      for (int leftSubSum : L[l]) {

        auto &v = R[N / 2 - l];

        int targetSum = total / 2 - leftSubSum;

        auto it = lower_bound(begin(v), end(v), targetSum);

        if (it != v.end()) {
          int rightSubSum = *it;

          int selectedSum = leftSubSum + rightSubSum;

          ans = min(ans, abs(total - 2 * selectedSum));
        }

        if (it != v.begin()) {
          --it;

          int rightSubSum = *it;

          int selectedSum = leftSubSum + rightSubSum;

          ans = min(ans, abs(total - 2 * selectedSum));
        }
      }
    }

    return ans;
  }
};