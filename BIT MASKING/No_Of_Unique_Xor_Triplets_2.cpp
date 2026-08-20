#include <bits/stdc++.h>
using namespace std;

const int MAX = 2048;

class Solution {
public:
  int uniqueXorTriplets(vector<int> &nums) {
    int n = nums.size();

    vector<bool> present(MAX);
    vector<bool> pairXor(MAX);

    for (int x : nums)
      present[x] = 1;

    // All possible (nums[i] ^ nums[j])
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        pairXor[nums[i] ^ nums[j]] = true;
      }
    }

    // Xor after adding third value
    vector<bool> ans(MAX);

    for (int x = 0; x < MAX; x++) {
      if (!pairXor[x])
        continue;

      for (int y = 0; y < MAX; y++) {
        if (present[y]) {
          ans[x ^ y] = true;
        }
      }
    }

    return count(begin(ans), end(ans), true);
  }
};