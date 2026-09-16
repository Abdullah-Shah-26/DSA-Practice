#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int> &nums) {
    
    int n = nums.size();
    int sum = accumulate(begin(nums), end(nums), 0);
    int Lsum = 0;

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
      int Rsum = sum - Lsum - nums[i];

      int Lcnt = i;
      int Rcnt = n - i - 1;

      int L = (Lcnt * nums[i]) - Lsum;
      int R = Rsum - Rcnt * nums[i];

      ans[i] = L + R;

      Lsum += nums[i];
    }

    return ans;
  }
};