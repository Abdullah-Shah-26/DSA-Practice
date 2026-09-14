#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPali(int n) {
    string s = to_string(n);
    string r = s;

    reverse(r.begin(), r.end());

    return r == s;
  }

  long long minOperations(vector<int> &nums) {
    sort(begin(nums), end(nums));

    int n = nums.size();
    int median;

    if (n & 1)
      median = nums[n / 2];
    else
      median = (nums[n / 2 - 1] + nums[n / 2]) / 2;

    int temp1 = median;
    int temp2 = median;

    while (!isPali(temp1))
      temp1++;

    while (!isPali(temp2))
      temp2--;

    long long cost1 = 0, cost2 = 0;

    for (int x : nums) {
      cost1 += abs(x - temp1);
      cost2 += abs(x - temp2);
    }

    return min(cost1, cost2);
  }
};