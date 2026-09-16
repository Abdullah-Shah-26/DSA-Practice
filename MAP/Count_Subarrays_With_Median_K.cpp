#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    // Finding position of k
    int pos = find(begin(nums), end(nums), k) - begin(nums);

    // L = left sum
    unordered_map<int, int> m;

    // Empty left part
    m[0] = 1;

    int L = 0;

    for (int i = pos - 1; i >= 0; i--) {
      if (nums[i] < k)
        L -= 1;
      else
        L += 1;

      m[L]++;
    }

    int ans = 0;
    int R = 0; // Right sum going from k

    for (int i = pos; i < n; i++) {
      if (nums[i] < k)
        R -= 1;
      else if (nums[i] > k)
        R += 1;

      // nums[i] == k gives 0
      // Need :
      // L + R == 0
      // or
      // L + R == 1

      ans += m[-R];
      ans += m[1 - R];
    }

    return ans;
  }
};